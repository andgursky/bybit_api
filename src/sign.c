#include "internal.h"

#include <openssl/evp.h>
#include <openssl/core_names.h>
#include <openssl/pem.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bybit_err bybit_auth_canonical(const char *timestamp,
                               const char *api_key,
                               const char *recv_window,
                               const char *tail,
                               char **out)
{
    bybit_buf buf;

    if (out == NULL || timestamp == NULL || api_key == NULL || recv_window == NULL)
        return BYBIT_ERR_PARAM;
    *out = NULL;
    if (tail == NULL)
        tail = "";
    bybit_buf_init(&buf);
    if (bybit_buf_append_str(&buf, timestamp) != 0 ||
        bybit_buf_append_str(&buf, api_key) != 0 ||
        bybit_buf_append_str(&buf, recv_window) != 0 ||
        bybit_buf_append_str(&buf, tail) != 0) {
        bybit_buf_free(&buf);
        return BYBIT_ERR_NOMEM;
    }
    *out = bybit_buf_detach(&buf);
    return *out == NULL ? BYBIT_ERR_NOMEM : BYBIT_OK;
}

bybit_err bybit_ws_auth_canonical(const char *expires_ms, char **out)
{
    bybit_buf buf;

    if (out == NULL || expires_ms == NULL || expires_ms[0] == '\0')
        return BYBIT_ERR_PARAM;
    *out = NULL;
    bybit_buf_init(&buf);
    if (bybit_buf_printf(&buf, "GET/realtime%s", expires_ms) != 0) {
        bybit_buf_free(&buf);
        return BYBIT_ERR_NOMEM;
    }
    *out = bybit_buf_detach(&buf);
    return *out == NULL ? BYBIT_ERR_NOMEM : BYBIT_OK;
}

bybit_err bybit_hmac_sha256_hex(const void *key, size_t key_len,
                                const void *msg, size_t msg_len,
                                char out_hex[BYBIT_HMAC_HEX_LEN + 1])
{
    EVP_MAC *mac = NULL;
    EVP_MAC_CTX *ctx = NULL;
    OSSL_PARAM params[2];
    unsigned char raw[EVP_MAX_MD_SIZE];
    size_t raw_len = 0;
    size_t i;
    char digest[] = "SHA256";

    if (out_hex == NULL || (key == NULL && key_len != 0) || (msg == NULL && msg_len != 0))
        return BYBIT_ERR_PARAM;
    out_hex[0] = '\0';
    mac = EVP_MAC_fetch(NULL, "HMAC", NULL);
    if (mac == NULL)
        return BYBIT_ERR_SIGN;
    ctx = EVP_MAC_CTX_new(mac);
    EVP_MAC_free(mac);
    if (ctx == NULL)
        return BYBIT_ERR_SIGN;
    params[0] = OSSL_PARAM_construct_utf8_string(OSSL_MAC_PARAM_DIGEST, digest, 0);
    params[1] = OSSL_PARAM_construct_end();
    if (EVP_MAC_init(ctx, key, key_len, params) != 1 ||
        EVP_MAC_update(ctx, msg, msg_len) != 1 ||
        EVP_MAC_final(ctx, raw, &raw_len, sizeof raw) != 1 ||
        raw_len != 32) {
        EVP_MAC_CTX_free(ctx);
        return BYBIT_ERR_SIGN;
    }
    EVP_MAC_CTX_free(ctx);
    for (i = 0; i < raw_len; i++)
        snprintf(out_hex + (i * 2), 3, "%02x", raw[i]);
    out_hex[BYBIT_HMAC_HEX_LEN] = '\0';
    return BYBIT_OK;
}

bybit_err bybit_rsa_sha256_base64(const char *pem,
                                  const void *msg, size_t msg_len,
                                  char **out_b64)
{
    BIO *bio = NULL;
    EVP_PKEY *pkey = NULL;
    EVP_MD_CTX *ctx = NULL;
    unsigned char *sig = NULL;
    size_t sig_len = 0;
    unsigned char *b64 = NULL;
    int b64_len;
    bybit_err err = BYBIT_ERR_SIGN;

    if (out_b64 == NULL)
        return BYBIT_ERR_PARAM;
    *out_b64 = NULL;
    if (pem == NULL || (msg == NULL && msg_len != 0))
        return BYBIT_ERR_PARAM;
    bio = BIO_new_mem_buf(pem, -1);
    if (bio == NULL)
        return BYBIT_ERR_NOMEM;
    pkey = PEM_read_bio_PrivateKey(bio, NULL, NULL, NULL);
    BIO_free(bio);
    if (pkey == NULL)
        return BYBIT_ERR_SIGN;
    ctx = EVP_MD_CTX_new();
    if (ctx == NULL) {
        EVP_PKEY_free(pkey);
        return BYBIT_ERR_NOMEM;
    }
    if (EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, pkey) != 1 ||
        EVP_DigestSignUpdate(ctx, msg, msg_len) != 1 ||
        EVP_DigestSignFinal(ctx, NULL, &sig_len) != 1)
        goto done;
    sig = malloc(sig_len);
    if (sig == NULL) {
        err = BYBIT_ERR_NOMEM;
        goto done;
    }
    if (EVP_DigestSignFinal(ctx, sig, &sig_len) != 1)
        goto done;
    b64 = malloc((sig_len + 2) / 3 * 4 + 1);
    if (b64 == NULL) {
        err = BYBIT_ERR_NOMEM;
        goto done;
    }
    b64_len = EVP_EncodeBlock(b64, sig, (int)sig_len);
    if (b64_len < 0)
        goto done;
    b64[b64_len] = '\0';
    *out_b64 = (char *)b64;
    b64 = NULL;
    err = BYBIT_OK;
done:
    free(b64);
    free(sig);
    EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(pkey);
    return err;
}

static int unreserved(unsigned char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.' || c == '~';
}

static int append_encoded(bybit_buf *buf, const char *s)
{
    const unsigned char *p;
    for (p = (const unsigned char *)s; *p != 0; p++) {
        if (unreserved(*p)) {
            if (bybit_buf_append(buf, p, 1) != 0)
                return -1;
        } else {
            char hex[4];
            snprintf(hex, sizeof hex, "%%%02X", *p);
            if (bybit_buf_append(buf, hex, 3) != 0)
                return -1;
        }
    }
    return 0;
}

bybit_err bybit_query_encode(const bybit_kv *fields, size_t nfields, char **out)
{
    bybit_buf buf;
    size_t i;
    int any = 0;

    if (out == NULL)
        return BYBIT_ERR_PARAM;
    *out = NULL;
    if (nfields > 0 && fields == NULL)
        return BYBIT_ERR_PARAM;
    bybit_buf_init(&buf);
    for (i = 0; i < nfields; i++) {
        if (fields[i].key == NULL || fields[i].value == NULL)
            continue;
        if (fields[i].key[0] == '\0') {
            bybit_buf_free(&buf);
            return BYBIT_ERR_PARAM;
        }
        if (any && bybit_buf_append(&buf, "&", 1) != 0) {
            bybit_buf_free(&buf);
            return BYBIT_ERR_NOMEM;
        }
        if (append_encoded(&buf, fields[i].key) != 0 ||
            bybit_buf_append(&buf, "=", 1) != 0 ||
            append_encoded(&buf, fields[i].value) != 0) {
            bybit_buf_free(&buf);
            return BYBIT_ERR_NOMEM;
        }
        any = 1;
    }
    *out = bybit_buf_detach(&buf);
    return *out == NULL ? BYBIT_ERR_NOMEM : BYBIT_OK;
}
