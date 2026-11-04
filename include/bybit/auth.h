#ifndef BYBIT_AUTH_H
#define BYBIT_AUTH_H

#include "bybit/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * REST canonical string: timestamp + api_key + recv_window + tail.
 * tail is the exact query string (no '?') or the exact JSON body.
 */
bybit_err bybit_auth_canonical(const char *timestamp,
                               const char *api_key,
                               const char *recv_window,
                               const char *tail,
                               char **out);

/* Websocket auth plaintext: GET/realtime{expires}. expires is decimal ms. */
bybit_err bybit_ws_auth_canonical(const char *expires_ms, char **out);

/* out must hold BYBIT_HMAC_HEX_LEN + 1 bytes. Hex is lowercase. */
bybit_err bybit_hmac_sha256_hex(const void *key, size_t key_len,
                                const void *msg, size_t msg_len,
                                char out_hex[BYBIT_HMAC_HEX_LEN + 1]);

/* PKCS#1 v1.5 RSA-SHA256, base64 without newlines. pem is an unencrypted key. */
bybit_err bybit_rsa_sha256_base64(const char *pem,
                                  const void *msg, size_t msg_len,
                                  char **out_b64);

/* Percent-encode application/x-www-form-urlencoded, order preserved, %20 for space. */
bybit_err bybit_query_encode(const bybit_kv *fields, size_t nfields, char **out);

#ifdef __cplusplus
}
#endif

#endif /* BYBIT_AUTH_H */
