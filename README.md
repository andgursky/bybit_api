# bybit-c

Клиент Bybit API V5 на C11. Это библиотека на C, без C++.

Покрыты REST-эндпоинты из официальной документации V5 (коммит `d5a43d2` репозитория `bybit-exchange/docs`): 448 методов, из них 56 публичных и 392 с подписью. WebSocket говорит на JSON-каналах V5 и умеет принять бинарные кадры SBE. Схема SBE не декодируется: разбирается только 8-байтовый заголовок сообщения, дальше кадр отдаётся как есть.

## Сборка

Нужны компилятор C11, libcurl, OpenSSL и pthread. Кадры WebSocket собираются поверх TLS в самой библиотеке: системный libcurl часто собран без протокола `wss`.

```sh
make
make test
```

`make test` гоняет модульные тесты (подпись, JSON, стакан, каталог) и живой запрос. С IP в США и материковом Китае Bybit отвечает HTTP 403 на REST; тест это пропускает. Публичный WebSocket проверяется отдельно.

CMake:

```sh
cmake -S . -B build
cmake --build build
```

Статическая библиотека: `build/libbybit.a`. Заголовок: `include/bybit.h`.

Каталог можно пересобрать из свежих docs:

```sh
python3 tools/gen_endpoints.py /path/to/docs/docs/v5 include src
```

## REST

Публичный запрос не требует ключа. Поля `NULL` пропускаются. `BYBIT_STR` кладёт JSON-строку, `BYBIT_RAW` вставляет готовый JSON (число, bool, объект, массив).

```c
#include "bybit.h"

bybit_config cfg = {0};
bybit_client *client = bybit_client_create(&cfg);
bybit_kv query[] = {
    BYBIT_STR("category", "spot"),
    BYBIT_STR("symbol", "BTCUSDT"),
};
bybit_response *response = NULL;

if (bybit_market_tickers(client, query, 2, &response) == BYBIT_OK &&
    bybit_response_ok(response)) {
    /* response->result — JSON результата, response->raw — всё тело */
}

bybit_response_free(response);
bybit_client_destroy(client);
```

`bybit_rest()` возвращает `BYBIT_OK`, когда конверт Bybit разобран, даже если `retCode` не ноль. Код биржи лежит в `response->ret_code`. Транспортные сбои (`BYBIT_ERR_NETWORK`, `BYBIT_ERR_HTTP`, `BYBIT_ERR_JSON`) тоже могут заполнить `response`: его нужно освобождать, если указатель не `NULL`.

Приватный вызов подписывается, только если у эндпоинта `auth_required`. Строка подписи — `timestamp + api_key + recv_window + query` для GET и то же с телом JSON для POST. HMAC-SHA256 уходит в нижнем hex (`X-BAPI-SIGN-TYPE: 2`). RSA — это PKCS#1 v1.5 SHA-256 в base64, незашифрованный PEM в `api_secret` и `sign_type = BYBIT_SIGN_RSA_SHA256`.

```c
bybit_config cfg = {0};
cfg.env = BYBIT_TESTNET;
cfg.api_key = "key";
cfg.api_secret = "secret";
cfg.recv_window_ms = 5000;
cfg.referer = "broker-id"; /* необязательно, заголовок X-Referer */

bybit_client *client = bybit_client_create(&cfg);
bybit_client_sync_time(client); /* сдвиг часов для подписи */

bybit_kv order[] = {
    BYBIT_STR("category", "linear"),
    BYBIT_STR("symbol", "BTCUSDT"),
    BYBIT_STR("side", "Buy"),
    BYBIT_STR("orderType", "Limit"),
    BYBIT_STR("qty", "0.01"),
    BYBIT_STR("price", "50000"),
    BYBIT_RAW("reduceOnly", "false"),
};
bybit_response *response = NULL;
bybit_order_create(client, order, 7, &response);
```

Площадки: `BYBIT_MAINNET`, `BYBIT_TESTNET`, `BYBIT_DEMO` и сайты `BYBIT_SITE_GLOBAL`, `BYBIT_SITE_BYTICK`, `TR`, `KZ`, `GE`, `AE`, `EU`, `ID`, `JP`, `HK`. Свой origin задаётся через `rest_url`.

Список методов — `bybit_endpoint_count`, `bybit_endpoint_at`, `bybit_endpoint_find`. У каждой функции в `include/bybit/endpoints.h` в комментарии указаны метод, путь, нужна ли подпись и обязательные поля.

## WebSocket

Каналы: spot, linear, inverse, option, spread, rfq, event, earn (`/v5/public/fp`), private, trade, system status и SBE (`public-sbe`, `private-sbe`, `trade-sbe`). Демо-счёт использует `stream-demo.bybit.com` только для private; публичные данные идут с mainnet. Trade и SBE на demo нет.

Приватный и торговый сокеты аутентифицируются `GET/realtime{expires}`. Торговые операции: `order.create`, `order.amend`, `order.cancel` и batch-варианты. `args_json` — JSON-массив. Сердечный `{"op":"ping"}` уходит сам каждые 20 секунд из `bybit_ws_poll`; интервал меняется через `bybit_ws_set_ping_interval`.

```c
bybit_ws *ws = bybit_ws_create(client, BYBIT_WS_PUBLIC_LINEAR, NULL);
bybit_ws_connect(ws);

char topic[64];
bybit_topic_public_trade(topic, sizeof topic, "BTCUSDT");
const char *topics[] = { topic };
bybit_ws_subscribe(ws, topics, 1);

for (;;) {
    bybit_ws_msg *msg = NULL;
    if (bybit_ws_poll(ws, 1000) != BYBIT_OK)
        continue;
    while (bybit_ws_next(ws, &msg) == BYBIT_OK) {
        /* msg->data / msg->len, msg->binary для SBE */
        bybit_ws_msg_free(msg);
    }
}
```

Имена топиков: orderbook, RPI, full book, kline, ticker, public trade, allLiquidation, insurance, adlAlert, priceLimit и SBE-темы `ob.rpi.1.sbe`, `ob.50.sbe`, `publicTrade.sbe`. Готовые строки приватных тем — макросы `BYBIT_TOPIC_*` (order, execution, execution.fast, position, wallet, greeks, dcp, strategy, spread, rfq, earn, appeal).

`bybit_orderbook_apply` собирает локальный стакан из snapshot и delta. Нулевый размер удаляет уровень. Цены сравниваются как десятичные строки. `book->gap` становится 1, если `u` у delta не равен предыдущему `u + 1`.

Лимит подписки spot — 10 тем на один запрос и 21000 символов в `args`, как в документации V5.

SBE-хост по умолчанию: testnet `stream-testnet.bybits.org`, mainnet `stream.bybit.com`. Выделенный MMWS задаётся полем `ws_host`.
