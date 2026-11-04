#include "bybit.h"

#include <stdio.h>
#include <string.h>

int main(void)
{
    bybit_config cfg;
    bybit_client *client;
    bybit_ws *ws;
    char topic[64];
    const char *topics[1];
    int printed = 0;
    bybit_err err;

    memset(&cfg, 0, sizeof cfg);
    client = bybit_client_create(&cfg);
    ws = bybit_ws_create(client, BYBIT_WS_PUBLIC_LINEAR, NULL);
    if (ws == NULL || bybit_ws_connect(ws) != BYBIT_OK) {
        fprintf(stderr, "connect: %s\n", bybit_ws_last_error(ws));
        bybit_ws_destroy(ws);
        bybit_client_destroy(client);
        return 1;
    }
    bybit_topic_public_trade(topic, sizeof topic, "BTCUSDT");
    topics[0] = topic;
    if (bybit_ws_subscribe(ws, topics, 1) != BYBIT_OK) {
        bybit_ws_destroy(ws);
        bybit_client_destroy(client);
        return 1;
    }
    while (printed < 5) {
        bybit_ws_msg *msg = NULL;
        err = bybit_ws_poll(ws, 1000);
        if (err == BYBIT_ERR_TIMEOUT)
            continue;
        if (err != BYBIT_OK)
            break;
        while (bybit_ws_next(ws, &msg) == BYBIT_OK) {
            fwrite(msg->data, 1, msg->len, stdout);
            fputc('\n', stdout);
            printed++;
            bybit_ws_msg_free(msg);
        }
    }
    bybit_ws_destroy(ws);
    bybit_client_destroy(client);
    return printed > 0 ? 0 : 1;
}
