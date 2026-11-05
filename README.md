# bybit-c

A Bybit API V5 client written in C11. This is a C library, without C++.

REST endpoints from the official V5 documentation are covered (commit `d5a43d2` of the `bybit-exchange/docs` repository): 448 methods, of which 56 are public and 392 require a signature. WebSocket speaks the V5 JSON channels and can accept binary SBE frames. The SBE schema is not decoded: only the 8-byte message header is parsed, and the rest of the frame is returned as-is.

## Build

A C11 compiler, libcurl, OpenSSL, and pthread are required. WebSocket frames are assembled over TLS inside the library: the system libcurl is often built without the `wss` protocol.

```sh
make
make test
```

`make test` runs the unit tests (signature, JSON, order book, catalog) and a live request. From IP addresses in the United States and mainland China, Bybit responds with HTTP 403 on REST; the test skips that case. The public WebSocket is checked separately.

CMake:

```sh
cmake -S . -B build
cmake --build build
```

Static library: `build/libbybit.a`. Header: `include/bybit.h`.

The catalog can be regenerated from a fresh copy of the docs:

```sh
python3 tools/gen_endpoints.py /path/to/docs/docs/v5 include src
```

## REST

A public request does not require a key. `NULL` fields are skipped. `BYBIT_STR` writes a JSON string; `BYBIT_RAW` inserts ready-made JSON (a number, bool, object, or array).

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
    /* response->result is the result JSON; response->raw is the full body */
}

bybit_response_free(response);
bybit_client_destroy(client);
```

`bybit_rest()` returns `BYBIT_OK` once the Bybit envelope has been parsed, even when `retCode` is not zero. The exchange code is stored in `response->ret_code`. Transport failures (`BYBIT_ERR_NETWORK`, `BYBIT_ERR_HTTP`, `BYBIT_ERR_JSON`) can also fill in `response`: free it whenever the pointer is not `NULL`.

A private call is signed only when the endpoint has `auth_required`. The signature string is `timestamp + api_key + recv_window + query` for GET, and the same string plus the JSON body for POST. HMAC-SHA256 is sent as lowercase hex (`X-BAPI-SIGN-TYPE: 2`). RSA is PKCS#1 v1.5 SHA-256 in base64, with an unencrypted PEM in `api_secret` and `sign_type = BYBIT_SIGN_RSA_SHA256`.

```c
bybit_config cfg = {0};
cfg.env = BYBIT_TESTNET;
cfg.api_key = "key";
cfg.api_secret = "secret";
cfg.recv_window_ms = 5000;
cfg.referer = "broker-id"; /* optional, X-Referer header */

bybit_client *client = bybit_client_create(&cfg);
bybit_client_sync_time(client); /* clock offset used for the signature */

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

Environments: `BYBIT_MAINNET`, `BYBIT_TESTNET`, `BYBIT_DEMO`, and the sites `BYBIT_SITE_GLOBAL`, `BYBIT_SITE_BYTICK`, `TR`, `KZ`, `GE`, `AE`, `EU`, `ID`, `JP`, `HK`. A custom origin is set through `rest_url`.

The method list is available through `bybit_endpoint_count`, `bybit_endpoint_at`, and `bybit_endpoint_find`. Each function in `include/bybit/endpoints.h` has a comment that lists the HTTP method, path, whether a signature is required, and the required fields.

## WebSocket

Channels: spot, linear, inverse, option, spread, rfq, event, earn (`/v5/public/fp`), private, trade, system status, and SBE (`public-sbe`, `private-sbe`, `trade-sbe`). A demo account uses `stream-demo.bybit.com` only for private streams; public data comes from mainnet. Trade and SBE are unavailable on demo.

Private and trade sockets authenticate with `GET/realtime{expires}`. Trade operations: `order.create`, `order.amend`, `order.cancel`, and the batch variants. `args_json` is a JSON array. A heartbeat `{"op":"ping"}` is sent automatically every 20 seconds from `bybit_ws_poll`; the interval is changed with `bybit_ws_set_ping_interval`.

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
        /* msg->data / msg->len; msg->binary is set for SBE */
        bybit_ws_msg_free(msg);
    }
}
```

Topic names: orderbook, RPI, full book, kline, ticker, public trade, allLiquidation, insurance, adlAlert, priceLimit, and the SBE topics `ob.rpi.1.sbe`, `ob.50.sbe`, `publicTrade.sbe`. Ready-made private topic strings are the `BYBIT_TOPIC_*` macros (order, execution, execution.fast, position, wallet, greeks, dcp, strategy, spread, rfq, earn, appeal).

`bybit_orderbook_apply` builds a local order book from a snapshot and deltas. A zero size removes a level. Prices are compared as decimal strings. `book->gap` becomes 1 when a delta's `u` is not equal to the previous `u + 1`.

The spot subscription limit is 10 topics per request and 21000 characters in `args`, matching the V5 documentation.

The default SBE host is `stream-testnet.bybits.org` on testnet and `stream.bybit.com` on mainnet. A dedicated MMWS host is set with the `ws_host` field.
