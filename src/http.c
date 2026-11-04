#include "internal.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *bybit_strerror(bybit_err err)
{
    switch (err) {
    case BYBIT_OK:
        return "ok";
    case BYBIT_ERR_NOMEM:
        return "out of memory";
    case BYBIT_ERR_PARAM:
        return "invalid parameter";
    case BYBIT_ERR_NETWORK:
        return "network error";
    case BYBIT_ERR_HTTP:
        return "http error";
    case BYBIT_ERR_JSON:
        return "json error";
    case BYBIT_ERR_AUTH:
        return "authentication required";
    case BYBIT_ERR_SIGN:
        return "signature error";
    case BYBIT_ERR_STATE:
        return "invalid state";
    case BYBIT_ERR_TIMEOUT:
        return "timeout";
    case BYBIT_ERR_CLOSED:
        return "connection closed";
    case BYBIT_ERR_RANGE:
        return "value out of range";
    case BYBIT_ERR_AGAIN:
        return "try again";
    default:
        return "unknown error";
    }
}

void bybit_response_free(bybit_response *response)
{
    if (response == NULL)
        return;
    free(response->ret_msg);
    free(response->result);
    free(response->ret_ext_info);
    free(response->raw);
    free(response->transport_error);
    free(response);
}

int bybit_response_ok(const bybit_response *response)
{
    return response != NULL && response->ret_code_present && response->ret_code == 0;
}

static size_t body_cb(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    bybit_buf *buf = userdata;
    size_t n = size * nmemb;
    if (size != 0 && nmemb > SIZE_MAX / size)
        return 0;
    if (bybit_buf_append(buf, ptr, n) != 0)
        return 0;
    return n;
}

static int header_key(const char *line, size_t n, const char *name, const char **value, size_t *value_len)
{
    size_t name_len = strlen(name);
    size_t i;
    if (n < name_len + 1)
        return 0;
    for (i = 0; i < name_len; i++) {
        if (tolower((unsigned char)line[i]) != tolower((unsigned char)name[i]))
            return 0;
    }
    if (line[name_len] != ':')
        return 0;
    i = name_len + 1;
    while (i < n && (line[i] == ' ' || line[i] == '\t'))
        i++;
    *value = line + i;
    *value_len = n - i;
    while (*value_len > 0 &&
           ((*value)[*value_len - 1] == '\r' || (*value)[*value_len - 1] == '\n' ||
            (*value)[*value_len - 1] == ' '))
        (*value_len)--;
    return 1;
}

typedef struct header_acc {
    int limit;
    int limit_status;
    int64_t limit_reset_ms;
} header_acc;

static size_t header_cb(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    header_acc *acc = userdata;
    size_t n = size * nmemb;
    const char *value;
    size_t value_len;
    char tmp[64];

    if (size != 0 && nmemb > SIZE_MAX / size)
        return 0;
    if (header_key(ptr, n, "X-Bapi-Limit", &value, &value_len) ||
        header_key(ptr, n, "X-Bapi-Limit-Status", &value, &value_len) ||
        header_key(ptr, n, "X-Bapi-Limit-Reset-Timestamp", &value, &value_len)) {
        if (value_len >= sizeof tmp)
            value_len = sizeof tmp - 1;
        memcpy(tmp, value, value_len);
        tmp[value_len] = '\0';
        if (header_key(ptr, n, "X-Bapi-Limit-Status", &value, &value_len))
            acc->limit_status = atoi(tmp);
        else if (header_key(ptr, n, "X-Bapi-Limit-Reset-Timestamp", &value, &value_len))
            acc->limit_reset_ms = strtoll(tmp, NULL, 10);
        else
            acc->limit = atoi(tmp);
    }
    return n;
}

static char *slice_dup(const bybit_json *node)
{
    size_t n = 0;
    const char *s = bybit_json_slice(node, &n);
    char *out;
    if (s == NULL)
        return NULL;
    out = malloc(n + 1);
    if (out == NULL)
        return NULL;
    memcpy(out, s, n);
    out[n] = '\0';
    return out;
}

static void parse_envelope(bybit_response *response)
{
    const char *err = NULL;
    bybit_json_doc *doc;
    const bybit_json *root;
    const bybit_json *node;

    if (response->raw == NULL)
        return;
    doc = bybit_json_parse(response->raw, strlen(response->raw), &err);
    if (doc == NULL)
        return;
    root = bybit_json_root(doc);
    node = bybit_json_object_get(root, "retCode");
    if (node != NULL && bybit_json_string(node) != NULL) {
        response->ret_code = (int)strtol(bybit_json_string(node), NULL, 10);
        response->ret_code_present = 1;
    }
    node = bybit_json_object_get(root, "retMsg");
    if (node != NULL && bybit_json_get_type(node) == BYBIT_JSON_STRING)
        response->ret_msg = bybit_xstrdup(bybit_json_string(node));
    node = bybit_json_object_get(root, "time");
    if (node != NULL && bybit_json_string(node) != NULL) {
        response->time_ms = strtoll(bybit_json_string(node), NULL, 10);
        response->time_present = 1;
    }
    node = bybit_json_object_get(root, "result");
    if (node != NULL && bybit_json_get_type(node) != BYBIT_JSON_NULL)
        response->result = slice_dup(node);
    node = bybit_json_object_get(root, "retExtInfo");
    if (node != NULL && bybit_json_get_type(node) != BYBIT_JSON_NULL)
        response->ret_ext_info = slice_dup(node);
    bybit_json_doc_free(doc);
}

static bybit_err sign_request(bybit_client *client, const char *tail, char **sig_out, char *ts_out, size_t ts_len)
{
    int64_t ts;
    char recv[32];
    char *payload = NULL;
    bybit_err err;

    ts = bybit_now_ms() + client->time_offset_ms;
    snprintf(ts_out, ts_len, "%lld", (long long)ts);
    snprintf(recv, sizeof recv, "%ld", client->recv_window_ms);
    err = bybit_auth_canonical(ts_out, client->api_key, recv, tail == NULL ? "" : tail, &payload);
    if (err != BYBIT_OK)
        return err;
    if (client->sign_type == BYBIT_SIGN_RSA_SHA256) {
        err = bybit_rsa_sha256_base64(client->api_secret, payload, strlen(payload), sig_out);
    } else {
        char hex[BYBIT_HMAC_HEX_LEN + 1];
        err = bybit_hmac_sha256_hex(client->api_secret, strlen(client->api_secret),
                                    payload, strlen(payload), hex);
        if (err == BYBIT_OK) {
            *sig_out = bybit_xstrdup(hex);
            if (*sig_out == NULL)
                err = BYBIT_ERR_NOMEM;
        }
    }
    free(payload);
    return err;
}

bybit_err bybit_rest(bybit_client *client,
                     const char *method,
                     const char *path,
                     int authenticated,
                     const bybit_kv *query,
                     size_t nquery,
                     const char *body,
                     bybit_response **out)
{
    CURL *curl;
    CURLcode rc;
    bybit_response *response;
    bybit_buf body_buf;
    header_acc headers;
    struct curl_slist *hdrs = NULL;
    char *query_str = NULL;
    char *url = NULL;
    char *sig = NULL;
    char ts[32];
    char recv[32];
    char sign_type[8];
    char request_id[64];
    char errbuf[CURL_ERROR_SIZE];
    bybit_err err = BYBIT_OK;
    long http_status = 0;
    int is_get;

    bybit_buf_init(&body_buf);
    if (out == NULL)
        return BYBIT_ERR_PARAM;
    *out = NULL;
    if (client == NULL || method == NULL || path == NULL || path[0] != '/')
        return BYBIT_ERR_PARAM;
    is_get = strcmp(method, "GET") == 0;
    if (!is_get && strcmp(method, "POST") != 0)
        return BYBIT_ERR_PARAM;
    if (authenticated && (client->api_key == NULL || client->api_secret == NULL))
        return BYBIT_ERR_AUTH;

    pthread_mutex_lock(&client->mu);
    client->last_error[0] = '\0';
    if (client->curl == NULL) {
        client->curl = curl_easy_init();
        if (client->curl == NULL) {
            bybit_client_set_error(client, "curl_easy_init failed");
            err = BYBIT_ERR_NOMEM;
            goto unlock;
        }
    }
    curl = client->curl;
    curl_easy_reset(curl);

    if (is_get) {
        err = bybit_query_encode(query, nquery, &query_str);
        if (err != BYBIT_OK)
            goto unlock;
    }
    {
        bybit_buf ubuf;
        bybit_buf_init(&ubuf);
        if (bybit_buf_append_str(&ubuf, client->rest_origin) != 0 ||
            bybit_buf_append_str(&ubuf, path) != 0 ||
            (query_str != NULL && query_str[0] != '\0' &&
             (bybit_buf_append(&ubuf, "?", 1) != 0 ||
              bybit_buf_append_str(&ubuf, query_str) != 0))) {
            bybit_buf_free(&ubuf);
            err = BYBIT_ERR_NOMEM;
            goto unlock;
        }
        url = bybit_buf_detach(&ubuf);
        if (url == NULL) {
            err = BYBIT_ERR_NOMEM;
            goto unlock;
        }
    }

    bybit_buf_set_max(&body_buf, BYBIT_HTTP_BODY_MAX);
    memset(&headers, 0, sizeof headers);
    headers.limit = -1;
    headers.limit_status = -1;
    headers.limit_reset_ms = -1;
    errbuf[0] = '\0';

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
    curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_1_1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, body_cb);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body_buf);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_cb);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &headers);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, client->timeout_ms);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, client->timeout_ms);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 0L);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, client->user_agent);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);

    hdrs = curl_slist_append(hdrs, "Accept: application/json");
    snprintf(request_id, sizeof request_id, "%lld-%lu",
             (long long)bybit_now_ms(), ++client->req_seq);
    {
        char line[96];
        snprintf(line, sizeof line, "cdn-request-id: %s", request_id);
        hdrs = curl_slist_append(hdrs, line);
    }
    if (!is_get) {
        hdrs = curl_slist_append(hdrs, "Content-Type: application/json");
        if (body == NULL)
            body = "";
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(body));
    }
    if (authenticated) {
        const char *tail = is_get ? (query_str == NULL ? "" : query_str) : body;
        char line[1024];
        err = sign_request(client, tail, &sig, ts, sizeof ts);
        if (err != BYBIT_OK)
            goto unlock;
        snprintf(recv, sizeof recv, "%ld", client->recv_window_ms);
        snprintf(sign_type, sizeof sign_type, "%d", client->sign_type);
        snprintf(line, sizeof line, "X-BAPI-API-KEY: %s", client->api_key);
        hdrs = curl_slist_append(hdrs, line);
        snprintf(line, sizeof line, "X-BAPI-TIMESTAMP: %s", ts);
        hdrs = curl_slist_append(hdrs, line);
        snprintf(line, sizeof line, "X-BAPI-RECV-WINDOW: %s", recv);
        hdrs = curl_slist_append(hdrs, line);
        snprintf(line, sizeof line, "X-BAPI-SIGN-TYPE: %s", sign_type);
        hdrs = curl_slist_append(hdrs, line);
        if (strlen(sig) + 16 < sizeof line) {
            snprintf(line, sizeof line, "X-BAPI-SIGN: %s", sig);
            hdrs = curl_slist_append(hdrs, line);
        } else {
            /* RSA signatures are longer than the stack line. */
            char *long_line = NULL;
            size_t need = strlen(sig) + 16;
            long_line = malloc(need);
            if (long_line == NULL) {
                err = BYBIT_ERR_NOMEM;
                goto unlock;
            }
            snprintf(long_line, need, "X-BAPI-SIGN: %s", sig);
            hdrs = curl_slist_append(hdrs, long_line);
            free(long_line);
        }
        if (client->referer != NULL) {
            char *ref = NULL;
            size_t need = strlen(client->referer) + 16;
            ref = malloc(need);
            if (ref == NULL) {
                err = BYBIT_ERR_NOMEM;
                goto unlock;
            }
            snprintf(ref, need, "X-Referer: %s", client->referer);
            hdrs = curl_slist_append(hdrs, ref);
            free(ref);
        }
    }
    if (hdrs == NULL && authenticated) {
        err = BYBIT_ERR_NOMEM;
        goto unlock;
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hdrs);

    rc = curl_easy_perform(curl);
    if (rc != CURLE_OK) {
        bybit_client_set_error(client, errbuf[0] != '\0' ? errbuf : curl_easy_strerror(rc));
        err = (rc == CURLE_OPERATION_TIMEDOUT) ? BYBIT_ERR_TIMEOUT : BYBIT_ERR_NETWORK;
        goto unlock;
    }
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_status);

    response = calloc(1, sizeof(*response));
    if (response == NULL) {
        err = BYBIT_ERR_NOMEM;
        goto unlock;
    }
    response->http_status = http_status;
    response->limit = headers.limit;
    response->limit_status = headers.limit_status;
    response->limit_reset_ms = headers.limit_reset_ms;
    response->raw = bybit_buf_detach(&body_buf);
    if (response->raw == NULL) {
        bybit_response_free(response);
        err = BYBIT_ERR_NOMEM;
        goto unlock;
    }
    parse_envelope(response);
    if (response->ret_msg == NULL && response->ret_code_present == 0) {
        /* Body was not a Bybit envelope. */
    }
    *out = response;
    if (http_status < 200 || http_status >= 300) {
        err = BYBIT_ERR_HTTP;
        snprintf(client->last_error, sizeof client->last_error, "http status %ld", http_status);
    } else if (!response->ret_code_present) {
        err = BYBIT_ERR_JSON;
        bybit_client_set_error(client, "response is not a bybit envelope");
    } else {
        err = BYBIT_OK;
    }

unlock:
    curl_slist_free_all(hdrs);
    free(query_str);
    free(url);
    if (sig != NULL) {
        memset(sig, 0, strlen(sig));
        free(sig);
    }
    bybit_buf_free(&body_buf);
    pthread_mutex_unlock(&client->mu);
    return err;
}

bybit_err bybit_client_sync_time(bybit_client *client)
{
    int64_t t0;
    int64_t t1;
    bybit_response *response = NULL;
    bybit_err err;
    int64_t offset;

    if (client == NULL)
        return BYBIT_ERR_PARAM;
    t0 = bybit_now_ms();
    err = bybit_rest(client, "GET", "/v5/market/time", 0, NULL, 0, NULL, &response);
    t1 = bybit_now_ms();
    if (err != BYBIT_OK) {
        bybit_response_free(response);
        return err;
    }
    if (!bybit_response_ok(response) || !response->time_present) {
        bybit_response_free(response);
        return BYBIT_ERR_JSON;
    }
    offset = response->time_ms - (t0 + t1) / 2;
    bybit_response_free(response);
    return bybit_client_set_time_offset(client, offset);
}
