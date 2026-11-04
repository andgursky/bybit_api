#ifndef BYBIT_TYPES_H
#define BYBIT_TYPES_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BYBIT_C_VERSION_MAJOR 1
#define BYBIT_C_VERSION_MINOR 0
#define BYBIT_C_VERSION_PATCH 0
#define BYBIT_C_VERSION "1.0.0"

#define BYBIT_RECV_WINDOW_DEFAULT 5000L
#define BYBIT_TIMEOUT_DEFAULT 10000L
#define BYBIT_HMAC_HEX_LEN 64

typedef enum bybit_err {
    BYBIT_OK = 0,
    BYBIT_ERR_NOMEM = 1,
    BYBIT_ERR_PARAM = 2,
    BYBIT_ERR_NETWORK = 3,
    BYBIT_ERR_HTTP = 4,
    BYBIT_ERR_JSON = 5,
    BYBIT_ERR_AUTH = 6,
    BYBIT_ERR_SIGN = 7,
    BYBIT_ERR_STATE = 8,
    BYBIT_ERR_TIMEOUT = 9,
    BYBIT_ERR_CLOSED = 10,
    BYBIT_ERR_RANGE = 11,
    BYBIT_ERR_AGAIN = 12
} bybit_err;

typedef enum bybit_env {
    BYBIT_MAINNET = 0,
    BYBIT_TESTNET = 1,
    BYBIT_DEMO = 2
} bybit_env;

typedef enum bybit_site {
    BYBIT_SITE_GLOBAL = 0,
    BYBIT_SITE_BYTICK = 1,
    BYBIT_SITE_TR = 2,
    BYBIT_SITE_KZ = 3,
    BYBIT_SITE_GE = 4,
    BYBIT_SITE_AE = 5,
    BYBIT_SITE_EU = 6,
    BYBIT_SITE_ID = 7,
    BYBIT_SITE_JP = 8,
    BYBIT_SITE_HK = 9
} bybit_site;

typedef enum bybit_sign_type {
    BYBIT_SIGN_HMAC_SHA256 = 2,
    BYBIT_SIGN_RSA_SHA256 = 1
} bybit_sign_type;

/*
 * One request field.
 * raw == 0: value is a JSON string (percent-encoded as text on GET).
 * raw == 1: value is a JSON token inserted as-is (numbers, booleans, objects, arrays).
 * A NULL value is omitted.
 */
typedef struct bybit_kv {
    const char *key;
    const char *value;
    int raw;
} bybit_kv;

#define BYBIT_STR(k, v) { .key = (k), .value = (v), .raw = 0 }
#define BYBIT_RAW(k, v) { .key = (k), .value = (v), .raw = 1 }

typedef struct bybit_config {
    bybit_env env;
    bybit_site site;
    const char *rest_url;     /* optional origin override, no trailing slash */
    const char *ws_host;      /* optional websocket hostname override */
    const char *api_key;      /* NULL for public-only clients */
    const char *api_secret;   /* HMAC secret, or unencrypted PEM for RSA */
    int sign_type;            /* 0 or BYBIT_SIGN_HMAC_SHA256, or BYBIT_SIGN_RSA_SHA256 */
    long recv_window_ms;      /* 0 selects 5000 */
    long timeout_ms;          /* 0 selects 10000 */
    const char *referer;      /* broker X-Referer, optional */
    const char *user_agent;   /* optional */
} bybit_config;

typedef struct bybit_client bybit_client;

typedef struct bybit_response {
    long http_status;
    int ret_code;
    int ret_code_present;
    char *ret_msg;
    char *result;          /* raw JSON of the result field, or NULL */
    char *ret_ext_info;    /* raw JSON, or NULL */
    int64_t time_ms;
    int time_present;
    char *raw;             /* full response body */
    int limit;             /* X-Bapi-Limit, -1 if absent */
    int limit_status;      /* X-Bapi-Limit-Status, -1 if absent */
    int64_t limit_reset_ms;
    char *transport_error;
} bybit_response;

const char *bybit_strerror(bybit_err err);

void bybit_response_free(bybit_response *response);
int bybit_response_ok(const bybit_response *response);

#ifdef __cplusplus
}
#endif

#endif /* BYBIT_TYPES_H */
