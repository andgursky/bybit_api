#ifndef BYBIT_INTERNAL_H
#define BYBIT_INTERNAL_H

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L
#endif

#include "bybit.h"

#include <pthread.h>
#include <stddef.h>
#include <stdint.h>

#include <curl/curl.h>

#define BYBIT_HTTP_BODY_MAX (32u * 1024u * 1024u)

typedef struct bybit_buf {
    char *data;
    size_t len;
    size_t cap;
    size_t max; /* 0 means no extra cap beyond SIZE_MAX */
} bybit_buf;

void bybit_buf_init(bybit_buf *buf);
void bybit_buf_free(bybit_buf *buf);
void bybit_buf_set_max(bybit_buf *buf, size_t max);
int bybit_buf_append(bybit_buf *buf, const void *data, size_t n);
int bybit_buf_append_str(bybit_buf *buf, const char *s);
int bybit_buf_printf(bybit_buf *buf, const char *fmt, ...);
char *bybit_buf_detach(bybit_buf *buf);

char *bybit_xstrdup(const char *s);
int64_t bybit_now_ms(void);

struct bybit_client {
    char *rest_origin;
    char *ws_host;
    int ws_host_set;
    bybit_env env;
    bybit_site site;
    char *api_key;
    char *api_secret;
    int sign_type;
    long recv_window_ms;
    long timeout_ms;
    char *referer;
    char *user_agent;
    int64_t time_offset_ms;
    unsigned long req_seq;
    char last_error[512];
    CURL *curl;
    pthread_mutex_t mu;
    int mu_ready;
};

void bybit_client_set_error(bybit_client *client, const char *msg);

#define BYBIT_WS_OP_CONTINUATION 0x0
#define BYBIT_WS_OP_TEXT 0x1
#define BYBIT_WS_OP_BINARY 0x2
#define BYBIT_WS_OP_CLOSE 0x8
#define BYBIT_WS_OP_PING 0x9
#define BYBIT_WS_OP_PONG 0xA

typedef struct bybit_ws_conn bybit_ws_conn;

bybit_ws_conn *bybit_ws_conn_open(const char *url, const char *user_agent, long timeout_ms,
                                  char *err, size_t errlen, bybit_err *status);
void bybit_ws_conn_close(bybit_ws_conn *conn);
bybit_err bybit_ws_conn_send(bybit_ws_conn *conn, const void *data, size_t len, int opcode,
                             char *err, size_t errlen);
bybit_err bybit_ws_conn_recv(bybit_ws_conn *conn, int timeout_ms, int *opcode, int *fin,
                             unsigned char **data, size_t *len, char *err, size_t errlen);
int bybit_ws_accept_ok(const char *client_key, const char *accept_value);

#endif /* BYBIT_INTERNAL_H */
