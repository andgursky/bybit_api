#include "internal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static pthread_once_t g_curl_once = PTHREAD_ONCE_INIT;

static void curl_once(void)
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

static int valid_origin(const char *url)
{
    size_t n;
    if (url == NULL)
        return 0;
    n = strlen(url);
    if (n < 8 || n > 200)
        return 0;
    if (strncmp(url, "https://", 8) != 0 && strncmp(url, "http://", 7) != 0)
        return 0;
    if (strchr(url, ' ') != NULL || strchr(url, '?') != NULL)
        return 0;
    return 1;
}

static char *copy_origin(const char *url)
{
    size_t n = strlen(url);
    char *out;
    while (n > 0 && url[n - 1] == '/')
        n--;
    out = malloc(n + 1);
    if (out == NULL)
        return NULL;
    memcpy(out, url, n);
    out[n] = '\0';
    return out;
}

void bybit_client_set_error(bybit_client *client, const char *msg)
{
    if (client == NULL)
        return;
    if (msg == NULL)
        msg = "";
    snprintf(client->last_error, sizeof client->last_error, "%s", msg);
}

bybit_client *bybit_client_create(const bybit_config *config)
{
    bybit_client *client;
    char origin[256];
    char hostbuf[256];
    bybit_err err;
    int sign;

    pthread_once(&g_curl_once, curl_once);
    if (config == NULL)
        return NULL;
    sign = config->sign_type;
    if (sign == 0)
        sign = BYBIT_SIGN_HMAC_SHA256;
    if (sign != BYBIT_SIGN_HMAC_SHA256 && sign != BYBIT_SIGN_RSA_SHA256)
        return NULL;
    if ((config->api_key == NULL) != (config->api_secret == NULL))
        return NULL;

    client = calloc(1, sizeof(*client));
    if (client == NULL)
        return NULL;
    if (pthread_mutex_init(&client->mu, NULL) != 0) {
        free(client);
        return NULL;
    }
    client->mu_ready = 1;
    client->env = config->env;
    client->site = config->site;
    client->sign_type = sign;
    client->recv_window_ms = config->recv_window_ms > 0 ? config->recv_window_ms
                                                         : BYBIT_RECV_WINDOW_DEFAULT;
    client->timeout_ms = config->timeout_ms > 0 ? config->timeout_ms : BYBIT_TIMEOUT_DEFAULT;

    if (config->rest_url != NULL && config->rest_url[0] != '\0') {
        if (!valid_origin(config->rest_url))
            goto fail;
        client->rest_origin = copy_origin(config->rest_url);
    } else {
        err = bybit_build_rest_origin(config->env, config->site, origin, sizeof origin);
        if (err != BYBIT_OK)
            goto fail;
        client->rest_origin = bybit_xstrdup(origin);
    }
    if (client->rest_origin == NULL)
        goto fail;

    if (config->ws_host != NULL && config->ws_host[0] != '\0') {
        if (strchr(config->ws_host, '/') != NULL || strchr(config->ws_host, ' ') != NULL)
            goto fail;
        client->ws_host = bybit_xstrdup(config->ws_host);
        client->ws_host_set = 1;
    } else {
        err = bybit_build_ws_url(config->env, config->site, BYBIT_WS_PUBLIC_LINEAR,
                                 NULL, NULL, hostbuf, sizeof hostbuf);
        if (err != BYBIT_OK)
            goto fail;
        /* hostbuf is wss://host/path. Extract host. */
        {
            const char *start = strstr(hostbuf, "://");
            const char *slash;
            size_t n;
            start = start == NULL ? hostbuf : start + 3;
            slash = strchr(start, '/');
            n = slash == NULL ? strlen(start) : (size_t)(slash - start);
            client->ws_host = malloc(n + 1);
            if (client->ws_host == NULL)
                goto fail;
            memcpy(client->ws_host, start, n);
            client->ws_host[n] = '\0';
        }
    }
    if (client->ws_host == NULL)
        goto fail;

    if (config->api_key != NULL) {
        client->api_key = bybit_xstrdup(config->api_key);
        client->api_secret = bybit_xstrdup(config->api_secret);
        if (client->api_key == NULL || client->api_secret == NULL)
            goto fail;
    }
    if (config->referer != NULL) {
        client->referer = bybit_xstrdup(config->referer);
        if (client->referer == NULL)
            goto fail;
    }
    client->user_agent = bybit_xstrdup(config->user_agent != NULL ? config->user_agent
                                                                  : "bybit-c/" BYBIT_C_VERSION);
    if (client->user_agent == NULL)
        goto fail;
    return client;

fail:
    bybit_client_destroy(client);
    return NULL;
}

void bybit_client_destroy(bybit_client *client)
{
    if (client == NULL)
        return;
    if (client->mu_ready)
        pthread_mutex_lock(&client->mu);
    if (client->curl != NULL)
        curl_easy_cleanup(client->curl);
    client->curl = NULL;
    if (client->mu_ready)
        pthread_mutex_unlock(&client->mu);
    if (client->api_secret != NULL) {
        memset(client->api_secret, 0, strlen(client->api_secret));
        free(client->api_secret);
    }
    free(client->api_key);
    free(client->rest_origin);
    free(client->ws_host);
    free(client->referer);
    free(client->user_agent);
    if (client->mu_ready)
        pthread_mutex_destroy(&client->mu);
    free(client);
}

const char *bybit_client_rest_url(const bybit_client *client)
{
    return client == NULL ? NULL : client->rest_origin;
}

const char *bybit_client_ws_host(const bybit_client *client)
{
    return client == NULL ? NULL : client->ws_host;
}

const char *bybit_client_last_error(const bybit_client *client)
{
    if (client == NULL)
        return "";
    return client->last_error;
}

int64_t bybit_client_time_offset(const bybit_client *client)
{
    return client == NULL ? 0 : client->time_offset_ms;
}

bybit_err bybit_client_set_time_offset(bybit_client *client, int64_t offset_ms)
{
    if (client == NULL)
        return BYBIT_ERR_PARAM;
    pthread_mutex_lock(&client->mu);
    client->time_offset_ms = offset_ms;
    pthread_mutex_unlock(&client->mu);
    return BYBIT_OK;
}
