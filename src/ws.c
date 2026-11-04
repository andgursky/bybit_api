#include "internal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ws_qnode {
    bybit_ws_msg *msg;
    struct ws_qnode *next;
} ws_qnode;

struct bybit_ws {
    bybit_ws_conn *conn;
    char *url;
    char *api_key;
    char *api_secret;
    char *referer;
    char *user_agent;
    int sign_type;
    long recv_window_ms;
    long timeout_ms;
    int64_t time_offset_ms;
    bybit_ws_channel channel;
    int needs_auth;
    int authed;
    int spot_limit;
    int open;
    int ping_interval_ms;
    int64_t last_ping_ms;
    char last_error[512];
    ws_qnode *head;
    ws_qnode *tail;
    size_t queued;
    size_t queued_bytes;
    bybit_buf frag;
    int frag_kind;
};

static void ws_error(bybit_ws *ws, const char *msg)
{
    if (ws == NULL)
        return;
    snprintf(ws->last_error, sizeof ws->last_error, "%s", msg == NULL ? "" : msg);
}

static void clear_queue(bybit_ws *ws)
{
    ws_qnode *n = ws->head;
    while (n != NULL) {
        ws_qnode *next = n->next;
        bybit_ws_msg_free(n->msg);
        free(n);
        n = next;
    }
    ws->head = NULL;
    ws->tail = NULL;
    ws->queued = 0;
    ws->queued_bytes = 0;
}

bybit_ws *bybit_ws_create(const bybit_client *client,
                          bybit_ws_channel channel,
                          const char *max_active_time)
{
    bybit_ws *ws;
    char url[768];
    bybit_err err;
    const char *host = NULL;
    bybit_client *mutable_client;
    int need_key;

    if (client == NULL)
        return NULL;
    mutable_client = (bybit_client *)client;
    pthread_mutex_lock(&mutable_client->mu);
    need_key = client->api_key != NULL;
    if (client->ws_host_set)
        host = client->ws_host;
    err = bybit_build_ws_url(client->env, client->site, channel, host, max_active_time,
                             url, sizeof url);
    if (err != BYBIT_OK) {
        pthread_mutex_unlock(&mutable_client->mu);
        return NULL;
    }
    ws = calloc(1, sizeof(*ws));
    if (ws == NULL) {
        pthread_mutex_unlock(&mutable_client->mu);
        return NULL;
    }
    ws->url = bybit_xstrdup(url);
    ws->channel = channel;
    ws->sign_type = client->sign_type;
    ws->recv_window_ms = client->recv_window_ms;
    ws->timeout_ms = client->timeout_ms;
    ws->time_offset_ms = client->time_offset_ms;
    ws->ping_interval_ms = 20000;
    ws->spot_limit = channel == BYBIT_WS_PUBLIC_SPOT;
    ws->needs_auth = channel == BYBIT_WS_PRIVATE || channel == BYBIT_WS_TRADE ||
                     channel == BYBIT_WS_SBE_PRIVATE || channel == BYBIT_WS_SBE_TRADE;
    if (client->api_key != NULL) {
        ws->api_key = bybit_xstrdup(client->api_key);
        ws->api_secret = bybit_xstrdup(client->api_secret);
    }
    if (client->referer != NULL)
        ws->referer = bybit_xstrdup(client->referer);
    ws->user_agent = bybit_xstrdup(client->user_agent);
    bybit_buf_init(&ws->frag);
    pthread_mutex_unlock(&mutable_client->mu);
    if (ws->url == NULL || ws->user_agent == NULL ||
        (need_key && (ws->api_key == NULL || ws->api_secret == NULL))) {
        bybit_ws_destroy(ws);
        return NULL;
    }
    return ws;
}

void bybit_ws_destroy(bybit_ws *ws)
{
    if (ws == NULL)
        return;
    bybit_ws_close(ws);
    clear_queue(ws);
    bybit_buf_free(&ws->frag);
    if (ws->api_secret != NULL) {
        memset(ws->api_secret, 0, strlen(ws->api_secret));
        free(ws->api_secret);
    }
    free(ws->api_key);
    free(ws->referer);
    free(ws->user_agent);
    free(ws->url);
    free(ws);
}

const char *bybit_ws_url(const bybit_ws *ws)
{
    return ws == NULL ? NULL : ws->url;
}

const char *bybit_ws_last_error(const bybit_ws *ws)
{
    return ws == NULL ? "" : ws->last_error;
}

void bybit_ws_set_time_offset(bybit_ws *ws, int64_t offset_ms)
{
    if (ws != NULL)
        ws->time_offset_ms = offset_ms;
}

void bybit_ws_set_ping_interval(bybit_ws *ws, int interval_ms)
{
    if (ws != NULL)
        ws->ping_interval_ms = interval_ms < 0 ? 0 : interval_ms;
}

int bybit_ws_is_open(const bybit_ws *ws)
{
    return ws != NULL && ws->open;
}

void bybit_ws_msg_free(bybit_ws_msg *msg)
{
    if (msg == NULL)
        return;
    free(msg->data);
    free(msg);
}

bybit_err bybit_ws_connect(bybit_ws *ws)
{
    bybit_err status = BYBIT_ERR_NETWORK;

    if (ws == NULL)
        return BYBIT_ERR_PARAM;
    if (ws->open)
        bybit_ws_close(ws);
    ws->conn = bybit_ws_conn_open(ws->url, ws->user_agent, ws->timeout_ms, ws->last_error,
                                  sizeof ws->last_error, &status);
    if (ws->conn == NULL)
        return status;
    ws->open = 1;
    ws->authed = 0;
    ws->last_ping_ms = bybit_now_ms();
    return BYBIT_OK;
}

void bybit_ws_close(bybit_ws *ws)
{
    if (ws == NULL)
        return;
    if (ws->conn != NULL && ws->open)
        bybit_ws_conn_send(ws->conn, "", 0, BYBIT_WS_OP_CLOSE, NULL, 0);
    bybit_ws_conn_close(ws->conn);
    ws->conn = NULL;
    ws->open = 0;
    ws->authed = 0;
    bybit_buf_free(&ws->frag);
    ws->frag_kind = 0;
}

static bybit_err send_frame(bybit_ws *ws, const void *data, size_t len, int opcode)
{
    bybit_err err;
    if (ws == NULL)
        return BYBIT_ERR_PARAM;
    if (!ws->open || ws->conn == NULL)
        return BYBIT_ERR_CLOSED;
    err = bybit_ws_conn_send(ws->conn, data, len, opcode, ws->last_error, sizeof ws->last_error);
    if (err == BYBIT_ERR_NETWORK || err == BYBIT_ERR_CLOSED)
        ws->open = 0;
    return err;
}

bybit_err bybit_ws_send_text(bybit_ws *ws, const char *json)
{
    if (ws == NULL || json == NULL)
        return BYBIT_ERR_PARAM;
    return send_frame(ws, json, strlen(json), BYBIT_WS_OP_TEXT);
}

bybit_err bybit_ws_send_binary(bybit_ws *ws, const void *data, size_t len)
{
    if (ws == NULL || (data == NULL && len != 0))
        return BYBIT_ERR_PARAM;
    return send_frame(ws, data, len, BYBIT_WS_OP_BINARY);
}

bybit_err bybit_ws_ping(bybit_ws *ws)
{
    bybit_err err = bybit_ws_send_text(ws, "{\"op\":\"ping\"}");
    if (err == BYBIT_OK)
        ws->last_ping_ms = bybit_now_ms();
    return err;
}

static bybit_err enqueue(bybit_ws *ws, char *data, size_t len, int binary)
{
    bybit_ws_msg *msg;
    ws_qnode *node;

    if (ws->queued >= 1024 || ws->queued_bytes + len > (8u * 1024u * 1024u)) {
        free(data);
        ws_error(ws, "websocket queue is full");
        return BYBIT_ERR_RANGE;
    }
    msg = calloc(1, sizeof(*msg));
    node = calloc(1, sizeof(*node));
    if (msg == NULL || node == NULL) {
        free(msg);
        free(node);
        free(data);
        return BYBIT_ERR_NOMEM;
    }
    msg->data = data;
    msg->len = len;
    msg->binary = binary;
    node->msg = msg;
    if (ws->tail != NULL)
        ws->tail->next = node;
    else
        ws->head = node;
    ws->tail = node;
    ws->queued++;
    ws->queued_bytes += len;
    return BYBIT_OK;
}

static bybit_err dispatch_fragment(bybit_ws *ws)
{
    size_t len = ws->frag.len;
    char *data = bybit_buf_detach(&ws->frag);
    int kind = ws->frag_kind;

    ws->frag_kind = 0;
    if (data == NULL)
        return BYBIT_ERR_NOMEM;
    return enqueue(ws, data, len, kind == BYBIT_WS_OP_BINARY);
}

static bybit_err read_once(bybit_ws *ws, int timeout_ms, int *got)
{
    int64_t deadline;
    int forever;

    *got = 0;
    if (!ws->open || ws->conn == NULL)
        return BYBIT_ERR_CLOSED;
    forever = timeout_ms < 0;
    deadline = forever ? -1 : bybit_now_ms() + timeout_ms;
    for (;;) {
        int opcode = 0;
        int fin = 0;
        unsigned char *payload = NULL;
        size_t plen = 0;
        int wait;
        bybit_err err;
        int64_t left;

        if (forever)
            wait = -1;
        else {
            left = deadline - bybit_now_ms();
            if (left <= 0)
                return BYBIT_ERR_TIMEOUT;
            wait = left > 86400000 ? 86400000 : (int)left;
        }
        err = bybit_ws_conn_recv(ws->conn, wait, &opcode, &fin, &payload, &plen, ws->last_error,
                                 sizeof ws->last_error);
        if (err != BYBIT_OK) {
            if (err == BYBIT_ERR_NETWORK || err == BYBIT_ERR_CLOSED)
                ws->open = 0;
            return err;
        }
        if (opcode == BYBIT_WS_OP_PING) {
            err = send_frame(ws, payload, plen, BYBIT_WS_OP_PONG);
            free(payload);
            if (err != BYBIT_OK)
                return err;
            continue;
        }
        if (opcode == BYBIT_WS_OP_PONG) {
            free(payload);
            continue;
        }
        if (opcode == BYBIT_WS_OP_CLOSE) {
            free(payload);
            ws->open = 0;
            ws_error(ws, "websocket closed by peer");
            return BYBIT_ERR_CLOSED;
        }
        if (opcode == BYBIT_WS_OP_TEXT || opcode == BYBIT_WS_OP_BINARY) {
            if (ws->frag.len != 0) {
                free(payload);
                ws_error(ws, "unexpected websocket data frame");
                return BYBIT_ERR_NETWORK;
            }
            ws->frag_kind = opcode;
        } else if (opcode != BYBIT_WS_OP_CONTINUATION) {
            free(payload);
            ws_error(ws, "unknown websocket opcode");
            return BYBIT_ERR_NETWORK;
        }
        if (plen > 0 && bybit_buf_append(&ws->frag, payload, plen) != 0) {
            free(payload);
            return BYBIT_ERR_NOMEM;
        }
        free(payload);
        if (!fin)
            continue;
        err = dispatch_fragment(ws);
        if (err != BYBIT_OK)
            return err;
        *got = 1;
        return BYBIT_OK;
    }
}

static int remaining_ms(int64_t deadline, int forever)
{
    int64_t left;
    if (forever)
        return -1;
    left = deadline - bybit_now_ms();
    if (left <= 0)
        return 0;
    if (left > 86400000)
        return 86400000;
    return (int)left;
}

bybit_err bybit_ws_poll(bybit_ws *ws, int timeout_ms)
{
    int forever;
    int64_t deadline;
    int got_any = 0;

    if (ws == NULL)
        return BYBIT_ERR_PARAM;
    if (timeout_ms < -1)
        return BYBIT_ERR_PARAM;
    if (!ws->open)
        return BYBIT_ERR_CLOSED;
    if (ws->ping_interval_ms > 0) {
        int64_t now = bybit_now_ms();
        if (now - ws->last_ping_ms >= ws->ping_interval_ms) {
            bybit_err err = bybit_ws_ping(ws);
            if (err != BYBIT_OK)
                return err;
        }
    }
    forever = timeout_ms < 0;
    deadline = forever ? 0 : bybit_now_ms() + timeout_ms;
    for (;;) {
        int got = 0;
        int wait = remaining_ms(deadline, forever);
        bybit_err err;
        if (!forever && wait == 0)
            return got_any ? BYBIT_OK : BYBIT_ERR_TIMEOUT;
        err = read_once(ws, wait, &got);
        if (err == BYBIT_OK && got)
            return BYBIT_OK;
        if (err == BYBIT_ERR_AGAIN || err == BYBIT_ERR_TIMEOUT) {
            if (!forever && remaining_ms(deadline, 0) == 0)
                return got_any ? BYBIT_OK : BYBIT_ERR_TIMEOUT;
            continue;
        }
        return err;
    }
}

bybit_err bybit_ws_next(bybit_ws *ws, bybit_ws_msg **out)
{
    ws_qnode *node;
    if (out == NULL)
        return BYBIT_ERR_PARAM;
    *out = NULL;
    if (ws == NULL)
        return BYBIT_ERR_PARAM;
    node = ws->head;
    if (node == NULL)
        return BYBIT_ERR_AGAIN;
    ws->head = node->next;
    if (ws->head == NULL)
        ws->tail = NULL;
    if (ws->queued > 0)
        ws->queued--;
    if (ws->queued_bytes >= node->msg->len)
        ws->queued_bytes -= node->msg->len;
    else
        ws->queued_bytes = 0;
    *out = node->msg;
    free(node);
    return BYBIT_OK;
}

static int message_is_auth(const bybit_ws_msg *msg, int *ok)
{
    const char *err = NULL;
    bybit_json_doc *doc;
    const bybit_json *root;
    const bybit_json *op;
    const bybit_json *success;
    const bybit_json *code;

    *ok = 0;
    if (msg == NULL || msg->binary)
        return 0;
    doc = bybit_json_parse(msg->data, msg->len, &err);
    if (doc == NULL)
        return 0;
    root = bybit_json_root(doc);
    op = bybit_json_object_get(root, "op");
    if (op == NULL || bybit_json_string(op) == NULL || strcmp(bybit_json_string(op), "auth") != 0) {
        bybit_json_doc_free(doc);
        return 0;
    }
    success = bybit_json_object_get(root, "success");
    code = bybit_json_object_get(root, "retCode");
    if (success != NULL && bybit_json_get_type(success) == BYBIT_JSON_BOOL)
        *ok = bybit_json_bool(success);
    else if (code != NULL && bybit_json_string(code) != NULL)
        *ok = strtol(bybit_json_string(code), NULL, 10) == 0;
    bybit_json_doc_free(doc);
    return 1;
}

bybit_err bybit_ws_auth(bybit_ws *ws, int timeout_ms)
{
    char expires[32];
    char *plain = NULL;
    char hex[BYBIT_HMAC_HEX_LEN + 1];
    char *sig = NULL;
    bybit_json_writer *writer;
    char *json = NULL;
    bybit_err err;
    int forever;
    int64_t deadline;

    if (ws == NULL)
        return BYBIT_ERR_PARAM;
    if (!ws->needs_auth)
        return BYBIT_ERR_STATE;
    if (!ws->open)
        return BYBIT_ERR_CLOSED;
    if (ws->api_key == NULL || ws->api_secret == NULL)
        return BYBIT_ERR_AUTH;
    snprintf(expires, sizeof expires, "%lld", (long long)(bybit_now_ms() + ws->time_offset_ms + 10000));
    err = bybit_ws_auth_canonical(expires, &plain);
    if (err != BYBIT_OK)
        return err;
    if (ws->sign_type == BYBIT_SIGN_RSA_SHA256)
        err = bybit_rsa_sha256_base64(ws->api_secret, plain, strlen(plain), &sig);
    else {
        err = bybit_hmac_sha256_hex(ws->api_secret, strlen(ws->api_secret), plain, strlen(plain), hex);
        if (err == BYBIT_OK)
            sig = bybit_xstrdup(hex);
    }
    free(plain);
    if (err != BYBIT_OK || sig == NULL) {
        free(sig);
        return err == BYBIT_OK ? BYBIT_ERR_NOMEM : err;
    }
    writer = bybit_json_writer_create();
    if (writer == NULL) {
        free(sig);
        return BYBIT_ERR_NOMEM;
    }
    err = bybit_json_writer_begin_object(writer);
    if (err == BYBIT_OK)
        err = bybit_json_writer_key(writer, "op");
    if (err == BYBIT_OK)
        err = bybit_json_writer_string(writer, "auth");
    if (err == BYBIT_OK)
        err = bybit_json_writer_key(writer, "args");
    if (err == BYBIT_OK)
        err = bybit_json_writer_begin_array(writer);
    if (err == BYBIT_OK)
        err = bybit_json_writer_string(writer, ws->api_key);
    if (err == BYBIT_OK)
        err = bybit_json_writer_number(writer, expires);
    if (err == BYBIT_OK)
        err = bybit_json_writer_string(writer, sig);
    if (err == BYBIT_OK)
        err = bybit_json_writer_end_array(writer);
    if (err == BYBIT_OK)
        err = bybit_json_writer_end_object(writer);
    free(sig);
    if (err != BYBIT_OK) {
        bybit_json_writer_destroy(writer);
        return err;
    }
    json = bybit_json_writer_finish(writer);
    bybit_json_writer_destroy(writer);
    if (json == NULL)
        return BYBIT_ERR_JSON;
    err = bybit_ws_send_text(ws, json);
    free(json);
    if (err != BYBIT_OK)
        return err;

    forever = timeout_ms < 0;
    deadline = forever ? 0 : bybit_now_ms() + (timeout_ms < 0 ? 0 : timeout_ms);
    for (;;) {
        ws_qnode **link;
        int wait = remaining_ms(deadline, forever);
        if (!forever && wait == 0)
            return BYBIT_ERR_TIMEOUT;
        err = bybit_ws_poll(ws, wait);
        if (err != BYBIT_OK)
            return err;
        for (link = &ws->head; *link != NULL; link = &(*link)->next) {
            int ok = 0;
            if (!message_is_auth((*link)->msg, &ok))
                continue;
            {
                ws_qnode *node = *link;
                *link = node->next;
                if (ws->tail == node) {
                    ws->tail = NULL;
                    if (ws->head != NULL) {
                        ws_qnode *scan = ws->head;
                        while (scan->next != NULL)
                            scan = scan->next;
                        ws->tail = scan;
                    }
                }
                if (ws->queued > 0)
                    ws->queued--;
                if (ws->queued_bytes >= node->msg->len)
                    ws->queued_bytes -= node->msg->len;
                bybit_ws_msg_free(node->msg);
                free(node);
                if (ok) {
                    ws->authed = 1;
                    return BYBIT_OK;
                }
                ws_error(ws, "websocket authentication rejected");
                return BYBIT_ERR_AUTH;
            }
        }
    }
}

static bybit_err send_sub(bybit_ws *ws, const char *op, const char *const *topics, size_t ntopics)
{
    bybit_json_writer *writer;
    char *json;
    bybit_err err;
    size_t i;
    size_t chars = 2;

    if (ws == NULL || op == NULL || (ntopics > 0 && topics == NULL))
        return BYBIT_ERR_PARAM;
    if (!ws->open)
        return BYBIT_ERR_CLOSED;
    if (ntopics == 0)
        return BYBIT_ERR_PARAM;
    if (ws->spot_limit && ntopics > 10)
        return BYBIT_ERR_RANGE;
    for (i = 0; i < ntopics; i++) {
        if (topics[i] == NULL || topics[i][0] == '\0')
            return BYBIT_ERR_PARAM;
        chars += strlen(topics[i]) + 3;
    }
    if (chars > 21000)
        return BYBIT_ERR_RANGE;
    writer = bybit_json_writer_create();
    if (writer == NULL)
        return BYBIT_ERR_NOMEM;
    err = bybit_json_writer_begin_object(writer);
    if (err == BYBIT_OK)
        err = bybit_json_writer_key(writer, "op");
    if (err == BYBIT_OK)
        err = bybit_json_writer_string(writer, op);
    if (err == BYBIT_OK)
        err = bybit_json_writer_key(writer, "args");
    if (err == BYBIT_OK)
        err = bybit_json_writer_begin_array(writer);
    for (i = 0; err == BYBIT_OK && i < ntopics; i++)
        err = bybit_json_writer_string(writer, topics[i]);
    if (err == BYBIT_OK)
        err = bybit_json_writer_end_array(writer);
    if (err == BYBIT_OK)
        err = bybit_json_writer_end_object(writer);
    if (err != BYBIT_OK) {
        bybit_json_writer_destroy(writer);
        return err;
    }
    json = bybit_json_writer_finish(writer);
    bybit_json_writer_destroy(writer);
    if (json == NULL)
        return BYBIT_ERR_JSON;
    err = bybit_ws_send_text(ws, json);
    free(json);
    return err;
}

bybit_err bybit_ws_subscribe(bybit_ws *ws, const char *const *topics, size_t ntopics)
{
    return send_sub(ws, BYBIT_OP_SUBSCRIBE, topics, ntopics);
}

bybit_err bybit_ws_unsubscribe(bybit_ws *ws, const char *const *topics, size_t ntopics)
{
    return send_sub(ws, BYBIT_OP_UNSUBSCRIBE, topics, ntopics);
}

bybit_err bybit_ws_trade(bybit_ws *ws,
                         const char *op,
                         const char *req_id,
                         const char *args_json,
                         const char *referer)
{
    bybit_json_writer *writer;
    char *json;
    char ts[32];
    char recv[32];
    const char *errtxt = NULL;
    bybit_json_doc *doc;
    bybit_err err;
    const char *use_referer;

    if (ws == NULL || op == NULL || args_json == NULL)
        return BYBIT_ERR_PARAM;
    if (ws->channel != BYBIT_WS_TRADE && ws->channel != BYBIT_WS_SBE_TRADE)
        return BYBIT_ERR_STATE;
    if (!ws->open)
        return BYBIT_ERR_CLOSED;
    if (!ws->authed)
        return BYBIT_ERR_AUTH;
    doc = bybit_json_parse(args_json, strlen(args_json), &errtxt);
    if (doc == NULL || bybit_json_get_type(bybit_json_root(doc)) != BYBIT_JSON_ARRAY) {
        bybit_json_doc_free(doc);
        return BYBIT_ERR_JSON;
    }
    bybit_json_doc_free(doc);
    snprintf(ts, sizeof ts, "%lld", (long long)(bybit_now_ms() + ws->time_offset_ms));
    snprintf(recv, sizeof recv, "%ld", ws->recv_window_ms);
    use_referer = referer != NULL ? referer : ws->referer;
    writer = bybit_json_writer_create();
    if (writer == NULL)
        return BYBIT_ERR_NOMEM;
    err = bybit_json_writer_begin_object(writer);
    if (err == BYBIT_OK && req_id != NULL) {
        err = bybit_json_writer_key(writer, "reqId");
        if (err == BYBIT_OK)
            err = bybit_json_writer_string(writer, req_id);
    }
    if (err == BYBIT_OK)
        err = bybit_json_writer_key(writer, "header");
    if (err == BYBIT_OK)
        err = bybit_json_writer_begin_object(writer);
    if (err == BYBIT_OK)
        err = bybit_json_writer_key(writer, "X-BAPI-TIMESTAMP");
    if (err == BYBIT_OK)
        err = bybit_json_writer_string(writer, ts);
    if (err == BYBIT_OK)
        err = bybit_json_writer_key(writer, "X-BAPI-RECV-WINDOW");
    if (err == BYBIT_OK)
        err = bybit_json_writer_string(writer, recv);
    if (err == BYBIT_OK && use_referer != NULL) {
        err = bybit_json_writer_key(writer, "Referer");
        if (err == BYBIT_OK)
            err = bybit_json_writer_string(writer, use_referer);
    }
    if (err == BYBIT_OK)
        err = bybit_json_writer_end_object(writer);
    if (err == BYBIT_OK)
        err = bybit_json_writer_key(writer, "op");
    if (err == BYBIT_OK)
        err = bybit_json_writer_string(writer, op);
    if (err == BYBIT_OK)
        err = bybit_json_writer_key(writer, "args");
    if (err == BYBIT_OK)
        err = bybit_json_writer_raw(writer, args_json);
    if (err == BYBIT_OK)
        err = bybit_json_writer_end_object(writer);
    if (err != BYBIT_OK) {
        bybit_json_writer_destroy(writer);
        return err;
    }
    json = bybit_json_writer_finish(writer);
    bybit_json_writer_destroy(writer);
    if (json == NULL)
        return BYBIT_ERR_JSON;
    err = bybit_ws_send_text(ws, json);
    free(json);
    return err;
}
