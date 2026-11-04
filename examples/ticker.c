#include "bybit.h"

#include <stdio.h>
#include <string.h>

int main(void)
{
    bybit_config cfg;
    bybit_client *client;
    bybit_kv query[] = {
        BYBIT_STR("category", "spot"),
        BYBIT_STR("symbol", "BTCUSDT"),
    };
    bybit_response *response = NULL;
    bybit_err err;

    memset(&cfg, 0, sizeof cfg);
    client = bybit_client_create(&cfg);
    if (client == NULL)
        return 1;
    err = bybit_market_tickers(client, query, 2, &response);
    if (response != NULL && response->raw != NULL)
        fwrite(response->raw, 1, strlen(response->raw), stdout);
    fputc('\n', stdout);
    bybit_response_free(response);
    bybit_client_destroy(client);
    return err == BYBIT_OK ? 0 : 1;
}
