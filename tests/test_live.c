#include "bybit.h"

#include <stdio.h>
#include <string.h>

static int skipped(bybit_err err, const bybit_response *response)
{
    if (err == BYBIT_ERR_HTTP && response != NULL &&
        (response->http_status == 403 || response->http_status == 451)) {
        printf("live skipped: http %ld\n", response->http_status);
        return 1;
    }
    if (err == BYBIT_ERR_NETWORK || err == BYBIT_ERR_TIMEOUT) {
        printf("live skipped: %s\n", bybit_strerror(err));
        return 1;
    }
    return 0;
}

static int test_rest(void)
{
    bybit_config cfg;
    bybit_client *client;
    bybit_kv query[] = { BYBIT_STR("category", "spot"), BYBIT_STR("symbol", "BTCUSDT") };
    bybit_response *response = NULL;
    bybit_err err;

    memset(&cfg, 0, sizeof cfg);
    client = bybit_client_create(&cfg);
    if (client == NULL) {
        fprintf(stderr, "client create failed\n");
        return 1;
    }
    err = bybit_market_time(client, NULL, 0, &response);
    if (skipped(err, response)) {
        bybit_response_free(response);
        bybit_client_destroy(client);
        return 0;
    }
    if (err != BYBIT_OK || !bybit_response_ok(response)) {
        fprintf(stderr, "server time failed: %s (%s) body=%s\n", bybit_strerror(err),
                bybit_client_last_error(client),
                response && response->raw ? response->raw : "");
        bybit_response_free(response);
        bybit_client_destroy(client);
        return 1;
    }
    printf("server time %lld\n", (long long)response->time_ms);
    bybit_response_free(response);
    response = NULL;
    err = bybit_market_tickers(client, query, 2, &response);
    if (skipped(err, response)) {
        bybit_response_free(response);
        bybit_client_destroy(client);
        return 0;
    }
    if (err != BYBIT_OK || !bybit_response_ok(response) || response->result == NULL ||
        strstr(response->result, "BTCUSDT") == NULL) {
        fprintf(stderr, "tickers failed err=%s ret=%d body=%s\n", bybit_strerror(err),
                response == NULL ? -1 : response->ret_code,
                response && response->raw ? response->raw : "");
        bybit_response_free(response);
        bybit_client_destroy(client);
        return 1;
    }
    printf("rest ticker ok ret=%d limit=%d\n", response->ret_code, response->limit);
    bybit_response_free(response);
    bybit_client_destroy(client);
    return 0;
}

static int test_ws(void)
{
    bybit_config cfg;
    bybit_client *client;
    bybit_ws *ws;
    char topic[64];
    const char *topics[1];
    int got = 0;
    int spins = 0;
    bybit_err err;

    memset(&cfg, 0, sizeof cfg);
    client = bybit_client_create(&cfg);
    ws = bybit_ws_create(client, BYBIT_WS_PUBLIC_SPOT, NULL);
    if (client == NULL || ws == NULL) {
        fprintf(stderr, "ws create failed\n");
        bybit_ws_destroy(ws);
        bybit_client_destroy(client);
        return 1;
    }
    bybit_ws_set_ping_interval(ws, 0);
    err = bybit_ws_connect(ws);
    if (err == BYBIT_ERR_NETWORK || err == BYBIT_ERR_TIMEOUT || err == BYBIT_ERR_HTTP) {
        printf("live ws skipped: %s (%s)\n", bybit_strerror(err), bybit_ws_last_error(ws));
        bybit_ws_destroy(ws);
        bybit_client_destroy(client);
        return 0;
    }
    if (err != BYBIT_OK) {
        fprintf(stderr, "connect failed: %s (%s)\n", bybit_strerror(err), bybit_ws_last_error(ws));
        bybit_ws_destroy(ws);
        bybit_client_destroy(client);
        return 1;
    }
    if (bybit_topic_public_trade(topic, sizeof topic, "BTCUSDT") != 0) {
        fprintf(stderr, "topic failed\n");
        bybit_ws_destroy(ws);
        bybit_client_destroy(client);
        return 1;
    }
    topics[0] = topic;
    err = bybit_ws_subscribe(ws, topics, 1);
    if (err != BYBIT_OK) {
        fprintf(stderr, "subscribe failed: %s\n", bybit_strerror(err));
        bybit_ws_destroy(ws);
        bybit_client_destroy(client);
        return 1;
    }
    while (got < 2 && spins < 40) {
        bybit_ws_msg *msg = NULL;
        err = bybit_ws_poll(ws, 500);
        spins++;
        if (err == BYBIT_ERR_TIMEOUT)
            continue;
        if (err != BYBIT_OK) {
            fprintf(stderr, "poll failed: %s (%s)\n", bybit_strerror(err), bybit_ws_last_error(ws));
            bybit_ws_destroy(ws);
            bybit_client_destroy(client);
            return 1;
        }
        while (bybit_ws_next(ws, &msg) == BYBIT_OK) {
            if (!msg->binary && msg->data != NULL &&
                (strstr(msg->data, "publicTrade.BTCUSDT") != NULL ||
                 strstr(msg->data, "\"op\":\"subscribe\"") != NULL ||
                 strstr(msg->data, "\"op\": \"subscribe\"") != NULL))
                got++;
            bybit_ws_msg_free(msg);
        }
    }
    if (got == 0) {
        fprintf(stderr, "no public trade messages\n");
        bybit_ws_destroy(ws);
        bybit_client_destroy(client);
        return 1;
    }
    printf("ws public trade ok messages=%d\n", got);
    bybit_ws_destroy(ws);
    bybit_client_destroy(client);
    return 0;
}

int main(void)
{
    int rc = test_rest();
    if (rc != 0)
        return rc;
    return test_ws();
}
