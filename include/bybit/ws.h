#ifndef BYBIT_WS_H
#define BYBIT_WS_H

#include "bybit/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum bybit_ws_channel {
    BYBIT_WS_PUBLIC_SPOT = 0,
    BYBIT_WS_PUBLIC_LINEAR,
    BYBIT_WS_PUBLIC_INVERSE,
    BYBIT_WS_PUBLIC_OPTION,
    BYBIT_WS_PUBLIC_SPREAD,
    BYBIT_WS_PUBLIC_RFQ,
    BYBIT_WS_PUBLIC_EVENT,
    BYBIT_WS_PUBLIC_EARN, /* /v5/public/fp */
    BYBIT_WS_PRIVATE,
    BYBIT_WS_TRADE,
    BYBIT_WS_SYSTEM, /* /v5/public/misc/status */
    BYBIT_WS_SBE_SPOT,
    BYBIT_WS_SBE_LINEAR,
    BYBIT_WS_SBE_INVERSE,
    BYBIT_WS_SBE_TRADE,
    BYBIT_WS_SBE_PRIVATE
} bybit_ws_channel;

typedef struct bybit_ws bybit_ws;

typedef struct bybit_ws_msg {
    char *data;
    size_t len;
    int binary;
} bybit_ws_msg;

typedef struct bybit_sbe_header {
    uint16_t block_length;
    uint16_t template_id;
    uint16_t schema_id;
    uint16_t version;
} bybit_sbe_header;

#define BYBIT_OP_AUTH "auth"
#define BYBIT_OP_PING "ping"
#define BYBIT_OP_SUBSCRIBE "subscribe"
#define BYBIT_OP_UNSUBSCRIBE "unsubscribe"
#define BYBIT_OP_ORDER_CREATE "order.create"
#define BYBIT_OP_ORDER_AMEND "order.amend"
#define BYBIT_OP_ORDER_CANCEL "order.cancel"
#define BYBIT_OP_ORDER_CREATE_BATCH "order.create-batch"
#define BYBIT_OP_ORDER_AMEND_BATCH "order.amend-batch"
#define BYBIT_OP_ORDER_CANCEL_BATCH "order.cancel-batch"

#define BYBIT_TOPIC_ORDER "order"
#define BYBIT_TOPIC_ORDER_SPOT "order.spot"
#define BYBIT_TOPIC_ORDER_LINEAR "order.linear"
#define BYBIT_TOPIC_ORDER_INVERSE "order.inverse"
#define BYBIT_TOPIC_ORDER_OPTION "order.option"
#define BYBIT_TOPIC_ORDER_EVENT "order.event"
#define BYBIT_TOPIC_EXECUTION "execution"
#define BYBIT_TOPIC_EXECUTION_SPOT "execution.spot"
#define BYBIT_TOPIC_EXECUTION_LINEAR "execution.linear"
#define BYBIT_TOPIC_EXECUTION_INVERSE "execution.inverse"
#define BYBIT_TOPIC_EXECUTION_OPTION "execution.option"
#define BYBIT_TOPIC_EXECUTION_EVENT "execution.event"
#define BYBIT_TOPIC_EXECUTION_FAST "execution.fast"
#define BYBIT_TOPIC_EXECUTION_FAST_LINEAR "execution.fast.linear"
#define BYBIT_TOPIC_EXECUTION_FAST_INVERSE "execution.fast.inverse"
#define BYBIT_TOPIC_EXECUTION_FAST_SPOT "execution.fast.spot"
#define BYBIT_TOPIC_EXECUTION_FAST_OPTION "execution.fast.option"
#define BYBIT_TOPIC_POSITION "position"
#define BYBIT_TOPIC_POSITION_LINEAR "position.linear"
#define BYBIT_TOPIC_POSITION_INVERSE "position.inverse"
#define BYBIT_TOPIC_POSITION_OPTION "position.option"
#define BYBIT_TOPIC_POSITION_EVENT "position.event"
#define BYBIT_TOPIC_WALLET "wallet"
#define BYBIT_TOPIC_GREEKS "greeks"
#define BYBIT_TOPIC_DCP_FUTURE "dcp.future"
#define BYBIT_TOPIC_DCP_SPOT "dcp.spot"
#define BYBIT_TOPIC_DCP_OPTION "dcp.option"
#define BYBIT_TOPIC_STRATEGY "strategy"
#define BYBIT_TOPIC_SPREAD_ORDER "spread.order"
#define BYBIT_TOPIC_SPREAD_EXECUTION "spread.execution"
#define BYBIT_TOPIC_RFQ_RFQS "rfq.open.rfqs"
#define BYBIT_TOPIC_RFQ_QUOTES "rfq.open.quotes"
#define BYBIT_TOPIC_RFQ_TRADES "rfq.open.trades"
#define BYBIT_TOPIC_RFQ_PUBLIC_TRADES "rfq.open.public.trades"
#define BYBIT_TOPIC_SYSTEM_STATUS "system.status"
#define BYBIT_TOPIC_APPEAL "fiat.compliance.appeal"
#define BYBIT_TOPIC_EARN_DISCOUNT_BUY "earn.discountbuy.offers"
#define BYBIT_TOPIC_EARN_DOUBLE_WIN "earn.doublewin.offers"
#define BYBIT_TOPIC_EARN_DUAL_ASSET "earn.dualassets.offers"
#define BYBIT_TOPIC_EARN_SMART_LEVERAGE "earn.smartleverage.offers"
#define BYBIT_TOPIC_FAST_ORDER_SBE "fast.resp.order"

/*
 * Build wss://host/path[?max_active_time=].
 * max_active_time is only valid for private and trade channels (for example "1m" or "30s").
 * Demo public channels use the mainnet public host. Demo trade and SBE are rejected.
 * SBE testnet defaults to stream-testnet.bybits.org. Pass ws_host to pin a dedicated MMWS host.
 */
bybit_err bybit_build_ws_url(bybit_env env, bybit_site site,
                             bybit_ws_channel channel,
                             const char *ws_host,
                             const char *max_active_time,
                             char *buf, size_t buflen);

int bybit_topic_orderbook(char *dst, size_t dst_len, int depth, const char *symbol);
int bybit_topic_orderbook_full(char *dst, size_t dst_len, const char *symbol);
int bybit_topic_orderbook_rpi(char *dst, size_t dst_len, const char *symbol);
int bybit_topic_public_trade(char *dst, size_t dst_len, const char *symbol);
int bybit_topic_kline(char *dst, size_t dst_len, const char *interval, const char *symbol);
int bybit_topic_ticker(char *dst, size_t dst_len, const char *symbol);
int bybit_topic_all_liquidation(char *dst, size_t dst_len, const char *symbol);
int bybit_topic_insurance(char *dst, size_t dst_len, const char *coin);
int bybit_topic_adl_alert(char *dst, size_t dst_len, const char *coin);
int bybit_topic_price_limit(char *dst, size_t dst_len, const char *symbol);
int bybit_topic_sbe_bbo(char *dst, size_t dst_len, const char *symbol);
int bybit_topic_sbe_ob50(char *dst, size_t dst_len, const char *symbol);
int bybit_topic_sbe_trade(char *dst, size_t dst_len, const char *symbol);

/*
 * Credentials, recv window, referer and the time offset are copied.
 * The client may be destroyed after this returns.
 * max_active_time may be NULL.
 */
bybit_ws *bybit_ws_create(const bybit_client *client,
                          bybit_ws_channel channel,
                          const char *max_active_time);
void bybit_ws_destroy(bybit_ws *ws);
const char *bybit_ws_url(const bybit_ws *ws);
const char *bybit_ws_last_error(const bybit_ws *ws);
void bybit_ws_set_time_offset(bybit_ws *ws, int64_t offset_ms);
/* 0 disables the automatic JSON ping. Default is 20000 ms. */
void bybit_ws_set_ping_interval(bybit_ws *ws, int interval_ms);

bybit_err bybit_ws_connect(bybit_ws *ws);
void bybit_ws_close(bybit_ws *ws);
int bybit_ws_is_open(const bybit_ws *ws);

/* Private and trade channels. Waits up to timeout_ms for the auth ack. */
bybit_err bybit_ws_auth(bybit_ws *ws, int timeout_ms);

bybit_err bybit_ws_subscribe(bybit_ws *ws, const char *const *topics, size_t ntopics);
bybit_err bybit_ws_unsubscribe(bybit_ws *ws, const char *const *topics, size_t ntopics);
bybit_err bybit_ws_ping(bybit_ws *ws);
bybit_err bybit_ws_send_text(bybit_ws *ws, const char *json);
bybit_err bybit_ws_send_binary(bybit_ws *ws, const void *data, size_t len);

/*
 * Trade websocket order entry. args_json is a JSON array of order objects.
 * req_id and referer may be NULL.
 */
bybit_err bybit_ws_trade(bybit_ws *ws,
                         const char *op,
                         const char *req_id,
                         const char *args_json,
                         const char *referer);

/*
 * Wait up to timeout_ms for socket data, reply to protocol pings, and queue
 * complete text or binary messages. BYBIT_ERR_TIMEOUT means nothing was queued.
 * Automatic JSON heartbeats are sent from here when the interval elapses.
 */
bybit_err bybit_ws_poll(bybit_ws *ws, int timeout_ms);
/* Pop one queued message. BYBIT_ERR_AGAIN when the queue is empty. */
bybit_err bybit_ws_next(bybit_ws *ws, bybit_ws_msg **out);
void bybit_ws_msg_free(bybit_ws_msg *msg);

/* First 8 bytes of an SBE frame, little-endian message header. */
bybit_err bybit_sbe_header_decode(const void *frame, size_t len, bybit_sbe_header *out);

typedef struct bybit_orderbook bybit_orderbook;

struct bybit_level {
    char *price;
    char *size;
};

struct bybit_orderbook {
    char *symbol;
    char *topic;
    int64_t ts;
    int64_t cts;
    int64_t u;
    int64_t seq;
    int gap; /* delta update id was not the previous id plus one */
    struct bybit_level *bids; /* highest price first */
    size_t n_bids;
    struct bybit_level *asks; /* lowest price first */
    size_t n_asks;
};

bybit_orderbook *bybit_orderbook_create(void);
void bybit_orderbook_destroy(bybit_orderbook *book);
void bybit_orderbook_reset(bybit_orderbook *book);
/* Apply one public orderbook JSON message (snapshot or delta). */
bybit_err bybit_orderbook_apply(bybit_orderbook *book, const char *json, size_t len);

#ifdef __cplusplus
}
#endif

#endif /* BYBIT_WS_H */
