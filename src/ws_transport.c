#include "internal.h"

#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

struct bybit_ws_conn {
    int fd;
    SSL_CTX *ctx;
    SSL *ssl;
};

static void set_err(char *err, size_t errlen, const char *msg)
{
    if (err != NULL && errlen > 0)
        snprintf(err, errlen, "%s", msg == NULL ? "" : msg);
}

static int64_t deadline_from(long timeout_ms)
{
    if (timeout_ms < 0)
        return -1;
    return bybit_now_ms() + timeout_ms;
}

static int wait_ms(int64_t deadline)
{
    int64_t left;
    if (deadline < 0)
        return -1;
    left = deadline - bybit_now_ms();
    if (left <= 0)
        return 0;
    if (left > 86400000)
        return 86400000;
    return (int)left;
}

static bybit_err poll_fd(int fd, short events, int64_t deadline, char *err, size_t errlen)
{
    struct pollfd pfd;
    int rc;
    int timeout = wait_ms(deadline);

    if (timeout == 0) {
        set_err(err, errlen, "timeout");
        return BYBIT_ERR_TIMEOUT;
    }
    pfd.fd = fd;
    pfd.events = events;
    pfd.revents = 0;
    do {
        rc = poll(&pfd, 1, timeout);
    } while (rc < 0 && errno == EINTR);
    if (rc == 0) {
        set_err(err, errlen, "timeout");
        return BYBIT_ERR_TIMEOUT;
    }
    if (rc < 0) {
        set_err(err, errlen, "poll failed");
        return BYBIT_ERR_NETWORK;
    }
    return BYBIT_OK;
}

static int random_bytes(unsigned char *buf, size_t n)
{
    int fd = open("/dev/urandom", O_RDONLY);
    size_t off = 0;
    if (fd < 0)
        return -1;
    while (off < n) {
        ssize_t got = read(fd, buf + off, n - off);
        if (got <= 0) {
            close(fd);
            return -1;
        }
        off += (size_t)got;
    }
    close(fd);
    return 0;
}

int bybit_ws_accept_ok(const char *client_key, const char *accept_value)
{
    char plain[128];
    unsigned char dig[EVP_MAX_MD_SIZE];
    unsigned int dlen = 0;
    unsigned char expect[64];
    const char *guid = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
    char got[128];
    size_t i;

    if (client_key == NULL || accept_value == NULL)
        return 0;
    if (strlen(client_key) + strlen(guid) >= sizeof plain)
        return 0;
    snprintf(plain, sizeof plain, "%s%s", client_key, guid);
    if (EVP_Digest(plain, strlen(plain), dig, &dlen, EVP_sha1(), NULL) != 1)
        return 0;
    if (EVP_EncodeBlock(expect, dig, (int)dlen) < 0)
        return 0;
    i = 0;
    while (accept_value[i] != '\0' && accept_value[i] != '\r' && accept_value[i] != '\n' &&
           i + 1 < sizeof got) {
        got[i] = accept_value[i];
        i++;
    }
    got[i] = '\0';
    while (i > 0 && (got[i - 1] == ' ' || got[i - 1] == '\t')) {
        got[--i] = '\0';
    }
    return strcmp((char *)expect, got) == 0;
}

static bybit_err parse_wss(const char *url, char **host, int *port, char **path)
{
    const char *start;
    const char *slash;
    const char *colon;
    char *h;
    size_t host_len;

    *host = NULL;
    *path = NULL;
    *port = 443;
    if (url == NULL || strncmp(url, "wss://", 6) != 0)
        return BYBIT_ERR_PARAM;
    start = url + 6;
    slash = strchr(start, '/');
    if (slash == NULL || slash == start)
        return BYBIT_ERR_PARAM;
    colon = memchr(start, ':', (size_t)(slash - start));
    if (colon != NULL) {
        host_len = (size_t)(colon - start);
        *port = atoi(colon + 1);
        if (*port <= 0 || *port > 65535)
            return BYBIT_ERR_PARAM;
    } else {
        host_len = (size_t)(slash - start);
    }
    if (host_len == 0 || host_len > 253)
        return BYBIT_ERR_PARAM;
    h = malloc(host_len + 1);
    if (h == NULL)
        return BYBIT_ERR_NOMEM;
    memcpy(h, start, host_len);
    h[host_len] = '\0';
    *host = h;
    *path = bybit_xstrdup(slash);
    if (*path == NULL) {
        free(*host);
        *host = NULL;
        return BYBIT_ERR_NOMEM;
    }
    return BYBIT_OK;
}

static bybit_err tcp_connect(const char *host, int port, long timeout_ms, int *fd_out, char *err, size_t errlen)
{
    struct addrinfo hints;
    struct addrinfo *res = NULL;
    struct addrinfo *ai;
    char port_text[16];
    int rc;
    int fd = -1;
    int64_t deadline = deadline_from(timeout_ms);
    bybit_err errc = BYBIT_ERR_NETWORK;

    memset(&hints, 0, sizeof hints);
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_UNSPEC;
    snprintf(port_text, sizeof port_text, "%d", port);
    rc = getaddrinfo(host, port_text, &hints, &res);
    if (rc != 0) {
        set_err(err, errlen, gai_strerror(rc));
        return BYBIT_ERR_NETWORK;
    }
    for (ai = res; ai != NULL; ai = ai->ai_next) {
        int flags;
        int soerr = 0;
        socklen_t sl = sizeof soerr;
        fd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
        if (fd < 0)
            continue;
        flags = fcntl(fd, F_GETFL, 0);
        if (flags >= 0)
            fcntl(fd, F_SETFL, flags | O_NONBLOCK);
        rc = connect(fd, ai->ai_addr, ai->ai_addrlen);
        if (rc != 0 && errno != EINPROGRESS) {
            close(fd);
            fd = -1;
            continue;
        }
        if (rc != 0) {
            errc = poll_fd(fd, POLLOUT, deadline, err, errlen);
            if (errc != BYBIT_OK) {
                close(fd);
                fd = -1;
                if (errc == BYBIT_ERR_TIMEOUT)
                    break;
                continue;
            }
            if (getsockopt(fd, SOL_SOCKET, SO_ERROR, &soerr, &sl) != 0 || soerr != 0) {
                close(fd);
                fd = -1;
                continue;
            }
        }
        {
            int one = 1;
            setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &one, sizeof one);
        }
        errc = BYBIT_OK;
        break;
    }
    freeaddrinfo(res);
    if (fd < 0) {
        if (errc == BYBIT_OK)
            errc = BYBIT_ERR_NETWORK;
        if (err != NULL && err[0] == '\0')
            set_err(err, errlen, "tcp connect failed");
        return errc;
    }
    *fd_out = fd;
    return BYBIT_OK;
}

static bybit_err ssl_handshake(bybit_ws_conn *conn, const char *host, int64_t deadline, char *err, size_t errlen)
{
    conn->ctx = SSL_CTX_new(TLS_client_method());
    if (conn->ctx == NULL) {
        set_err(err, errlen, "ssl context");
        return BYBIT_ERR_NETWORK;
    }
    SSL_CTX_set_verify(conn->ctx, SSL_VERIFY_PEER, NULL);
    SSL_CTX_set_default_verify_paths(conn->ctx);
    conn->ssl = SSL_new(conn->ctx);
    if (conn->ssl == NULL) {
        set_err(err, errlen, "ssl new");
        return BYBIT_ERR_NETWORK;
    }
    SSL_set_fd(conn->ssl, conn->fd);
    SSL_set_tlsext_host_name(conn->ssl, host);
    SSL_set1_host(conn->ssl, host);
    SSL_set_connect_state(conn->ssl);
    ERR_clear_error();
    for (;;) {
        int rc = SSL_connect(conn->ssl);
        int sslerr;
        short ev;
        if (rc == 1)
            return BYBIT_OK;
        sslerr = SSL_get_error(conn->ssl, rc);
        if (sslerr == SSL_ERROR_WANT_READ)
            ev = POLLIN;
        else if (sslerr == SSL_ERROR_WANT_WRITE)
            ev = POLLOUT;
        else {
            char buf[256];
            unsigned long e = ERR_get_error();
            if (e != 0)
                ERR_error_string_n(e, buf, sizeof buf);
            else
                snprintf(buf, sizeof buf, "tls handshake failed");
            set_err(err, errlen, buf);
            return BYBIT_ERR_NETWORK;
        }
        if (poll_fd(conn->fd, ev, deadline, err, errlen) != BYBIT_OK)
            return BYBIT_ERR_TIMEOUT;
    }
}

static bybit_err ssl_write_all(bybit_ws_conn *conn, const void *data, size_t len, char *err, size_t errlen)
{
    const unsigned char *p = data;
    size_t off = 0;
    while (off < len) {
        int rc = SSL_write(conn->ssl, p + off, (int)(len - off > 1 << 20 ? 1 << 20 : len - off));
        int sslerr;
        if (rc > 0) {
            off += (size_t)rc;
            continue;
        }
        sslerr = SSL_get_error(conn->ssl, rc);
        if (sslerr == SSL_ERROR_WANT_READ) {
            if (poll_fd(conn->fd, POLLIN, deadline_from(10000), err, errlen) != BYBIT_OK)
                return BYBIT_ERR_TIMEOUT;
            continue;
        }
        if (sslerr == SSL_ERROR_WANT_WRITE) {
            if (poll_fd(conn->fd, POLLOUT, deadline_from(10000), err, errlen) != BYBIT_OK)
                return BYBIT_ERR_TIMEOUT;
            continue;
        }
        set_err(err, errlen, "tls write failed");
        return BYBIT_ERR_NETWORK;
    }
    return BYBIT_OK;
}

static bybit_err ssl_read_full(bybit_ws_conn *conn, void *data, size_t len, int timeout_ms, char *err, size_t errlen)
{
    unsigned char *p = data;
    size_t off = 0;
    int64_t deadline = deadline_from(timeout_ms);
    while (off < len) {
        int rc = SSL_read(conn->ssl, p + off, (int)(len - off > 1 << 20 ? 1 << 20 : len - off));
        int sslerr;
        if (rc > 0) {
            off += (size_t)rc;
            continue;
        }
        sslerr = SSL_get_error(conn->ssl, rc);
        if (sslerr == SSL_ERROR_WANT_READ || sslerr == SSL_ERROR_WANT_WRITE) {
            bybit_err wait = poll_fd(conn->fd, sslerr == SSL_ERROR_WANT_WRITE ? POLLOUT : POLLIN,
                                     deadline, err, errlen);
            if (wait != BYBIT_OK)
                return wait;
            continue;
        }
        if (sslerr == SSL_ERROR_ZERO_RETURN) {
            set_err(err, errlen, "connection closed");
            return BYBIT_ERR_CLOSED;
        }
        set_err(err, errlen, "tls read failed");
        return BYBIT_ERR_NETWORK;
    }
    return BYBIT_OK;
}

static const char *header_find(const char *headers, const char *name)
{
    size_t n = strlen(name);
    const char *p = headers;
    while (*p != '\0') {
        if (strncasecmp(p, name, n) == 0 && p[n] == ':') {
            p += n + 1;
            while (*p == ' ' || *p == '\t')
                p++;
            return p;
        }
        p = strstr(p, "\r\n");
        if (p == NULL)
            return NULL;
        p += 2;
    }
    return NULL;
}

void bybit_ws_conn_close(bybit_ws_conn *conn)
{
    if (conn == NULL)
        return;
    if (conn->ssl != NULL) {
        SSL_shutdown(conn->ssl);
        SSL_free(conn->ssl);
    }
    if (conn->ctx != NULL)
        SSL_CTX_free(conn->ctx);
    if (conn->fd >= 0)
        close(conn->fd);
    free(conn);
}

bybit_ws_conn *bybit_ws_conn_open(const char *url, const char *user_agent, long timeout_ms,
                                  char *err, size_t errlen, bybit_err *status)
{
    char *host = NULL;
    char *path = NULL;
    int port = 443;
    bybit_ws_conn *conn = NULL;
    bybit_err errc;
    unsigned char nonce[16];
    unsigned char key_b64[32];
    char request[1024];
    bybit_buf resp;
    int64_t deadline;
    int code = 0;
    const char *accept;
    int nreq;

    if (status != NULL)
        *status = BYBIT_ERR_NETWORK;
    set_err(err, errlen, "");
    errc = parse_wss(url, &host, &port, &path);
    if (errc != BYBIT_OK) {
        if (status != NULL)
            *status = errc;
        set_err(err, errlen, "invalid websocket url");
        return NULL;
    }
    conn = calloc(1, sizeof(*conn));
    if (conn == NULL) {
        free(host);
        free(path);
        if (status != NULL)
            *status = BYBIT_ERR_NOMEM;
        return NULL;
    }
    conn->fd = -1;
    errc = tcp_connect(host, port, timeout_ms, &conn->fd, err, errlen);
    if (errc != BYBIT_OK) {
        if (status != NULL)
            *status = errc;
        free(host);
        free(path);
        bybit_ws_conn_close(conn);
        return NULL;
    }
    deadline = deadline_from(timeout_ms);
    errc = ssl_handshake(conn, host, deadline, err, errlen);
    if (errc != BYBIT_OK) {
        if (status != NULL)
            *status = errc;
        free(host);
        free(path);
        bybit_ws_conn_close(conn);
        return NULL;
    }
    if (random_bytes(nonce, sizeof nonce) != 0) {
        set_err(err, errlen, "urandom");
        if (status != NULL)
            *status = BYBIT_ERR_NETWORK;
        free(host);
        free(path);
        bybit_ws_conn_close(conn);
        return NULL;
    }
    EVP_EncodeBlock(key_b64, nonce, (int)sizeof nonce);
    nreq = snprintf(request, sizeof request,
                    "GET %s HTTP/1.1\r\n"
                    "Host: %s\r\n"
                    "Upgrade: websocket\r\n"
                    "Connection: Upgrade\r\n"
                    "Sec-WebSocket-Key: %s\r\n"
                    "Sec-WebSocket-Version: 13\r\n"
                    "User-Agent: %s\r\n"
                    "\r\n",
                    path, host, key_b64, user_agent != NULL ? user_agent : "bybit-c");
    free(path);
    free(host);
    if (nreq < 0 || (size_t)nreq >= sizeof request) {
        set_err(err, errlen, "handshake request too long");
        if (status != NULL)
            *status = BYBIT_ERR_RANGE;
        bybit_ws_conn_close(conn);
        return NULL;
    }
    errc = ssl_write_all(conn, request, (size_t)nreq, err, errlen);
    if (errc != BYBIT_OK) {
        if (status != NULL)
            *status = errc;
        bybit_ws_conn_close(conn);
        return NULL;
    }
    bybit_buf_init(&resp);
    bybit_buf_set_max(&resp, 16384);
    for (;;) {
        unsigned char byte;
        errc = ssl_read_full(conn, &byte, 1, (int)(timeout_ms > 0 ? timeout_ms : 10000), err, errlen);
        if (errc != BYBIT_OK) {
            bybit_buf_free(&resp);
            if (status != NULL)
                *status = errc;
            bybit_ws_conn_close(conn);
            return NULL;
        }
        if (bybit_buf_append(&resp, &byte, 1) != 0) {
            bybit_buf_free(&resp);
            if (status != NULL)
                *status = BYBIT_ERR_NOMEM;
            bybit_ws_conn_close(conn);
            return NULL;
        }
        if (resp.len >= 4 && memcmp(resp.data + resp.len - 4, "\r\n\r\n", 4) == 0)
            break;
        if (resp.len > 16384) {
            bybit_buf_free(&resp);
            set_err(err, errlen, "handshake header too large");
            if (status != NULL)
                *status = BYBIT_ERR_RANGE;
            bybit_ws_conn_close(conn);
            return NULL;
        }
    }
    {
        const char *sp = strchr(resp.data, ' ');
        code = sp != NULL ? atoi(sp + 1) : 0;
    }
    if (code != 101) {
        snprintf(err, errlen, "http status %d", code);
        bybit_buf_free(&resp);
        if (status != NULL)
            *status = code == 403 ? BYBIT_ERR_HTTP : BYBIT_ERR_NETWORK;
        bybit_ws_conn_close(conn);
        return NULL;
    }
    accept = header_find(resp.data, "Sec-WebSocket-Accept");
    if (accept == NULL || !bybit_ws_accept_ok((char *)key_b64, accept)) {
        set_err(err, errlen, "websocket accept mismatch");
        bybit_buf_free(&resp);
        if (status != NULL)
            *status = BYBIT_ERR_NETWORK;
        bybit_ws_conn_close(conn);
        return NULL;
    }
    bybit_buf_free(&resp);
    if (status != NULL)
        *status = BYBIT_OK;
    return conn;
}

bybit_err bybit_ws_conn_send(bybit_ws_conn *conn, const void *data, size_t len, int opcode,
                             char *err, size_t errlen)
{
    unsigned char hdr[14];
    size_t hlen;
    unsigned char mask[4];
    unsigned char *masked = NULL;
    size_t i;
    bybit_err errc;
    const unsigned char *src = data == NULL ? (const unsigned char *)"" : data;

    if (conn == NULL || conn->ssl == NULL)
        return BYBIT_ERR_CLOSED;
    if (len > 8u * 1024u * 1024u)
        return BYBIT_ERR_RANGE;
    if (random_bytes(mask, sizeof mask) != 0) {
        set_err(err, errlen, "urandom");
        return BYBIT_ERR_NETWORK;
    }
    hdr[0] = (unsigned char)(0x80 | (opcode & 0x0f));
    if (len < 126) {
        hdr[1] = (unsigned char)(0x80 | len);
        hlen = 2;
    } else if (len <= 65535u) {
        hdr[1] = 0x80 | 126;
        hdr[2] = (unsigned char)((len >> 8) & 0xff);
        hdr[3] = (unsigned char)(len & 0xff);
        hlen = 4;
    } else {
        hdr[1] = 0x80 | 127;
        for (i = 0; i < 8; i++)
            hdr[2 + i] = (unsigned char)((len >> (56 - 8 * i)) & 0xff);
        hlen = 10;
    }
    memcpy(hdr + hlen, mask, 4);
    hlen += 4;
    if (len > 0) {
        masked = malloc(len);
        if (masked == NULL)
            return BYBIT_ERR_NOMEM;
        for (i = 0; i < len; i++)
            masked[i] = (unsigned char)(src[i] ^ mask[i & 3]);
    }
    errc = ssl_write_all(conn, hdr, hlen, err, errlen);
    if (errc == BYBIT_OK && len > 0)
        errc = ssl_write_all(conn, masked, len, err, errlen);
    free(masked);
    return errc;
}

bybit_err bybit_ws_conn_recv(bybit_ws_conn *conn, int timeout_ms, int *opcode, int *fin,
                             unsigned char **data, size_t *len, char *err, size_t errlen)
{
    unsigned char hdr[2];
    unsigned char ext[8];
    unsigned char mask[4];
    size_t payload_len;
    int masked;
    unsigned char *buf = NULL;
    bybit_err errc;
    size_t i;

    if (data != NULL)
        *data = NULL;
    if (len != NULL)
        *len = 0;
    if (conn == NULL || opcode == NULL || fin == NULL || data == NULL || len == NULL)
        return BYBIT_ERR_PARAM;
    errc = ssl_read_full(conn, hdr, 2, timeout_ms, err, errlen);
    if (errc != BYBIT_OK)
        return errc;
    *fin = (hdr[0] & 0x80) != 0;
    *opcode = hdr[0] & 0x0f;
    masked = (hdr[1] & 0x80) != 0;
    payload_len = hdr[1] & 0x7f;
    if (payload_len == 126) {
        errc = ssl_read_full(conn, ext, 2, timeout_ms, err, errlen);
        if (errc != BYBIT_OK)
            return errc;
        payload_len = ((size_t)ext[0] << 8) | ext[1];
    } else if (payload_len == 127) {
        errc = ssl_read_full(conn, ext, 8, timeout_ms, err, errlen);
        if (errc != BYBIT_OK)
            return errc;
        payload_len = 0;
        for (i = 0; i < 8; i++)
            payload_len = (payload_len << 8) | ext[i];
    }
    if (payload_len > 8u * 1024u * 1024u) {
        set_err(err, errlen, "websocket frame too large");
        return BYBIT_ERR_RANGE;
    }
    if (masked) {
        errc = ssl_read_full(conn, mask, 4, timeout_ms, err, errlen);
        if (errc != BYBIT_OK)
            return errc;
    }
    if (payload_len > 0) {
        buf = malloc(payload_len + 1);
        if (buf == NULL)
            return BYBIT_ERR_NOMEM;
        errc = ssl_read_full(conn, buf, payload_len, timeout_ms, err, errlen);
        if (errc != BYBIT_OK) {
            free(buf);
            return errc;
        }
        if (masked) {
            for (i = 0; i < payload_len; i++)
                buf[i] = (unsigned char)(buf[i] ^ mask[i & 3]);
        }
        buf[payload_len] = '\0';
    } else {
        buf = calloc(1, 1);
        if (buf == NULL)
            return BYBIT_ERR_NOMEM;
    }
    *data = buf;
    *len = payload_len;
    return BYBIT_OK;
}
