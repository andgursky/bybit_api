#include "internal.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static int symbol_ok(const char *symbol)
{
    const unsigned char *p;
    size_t n = 0;
    if (symbol == NULL || symbol[0] == '\0')
        return 0;
    for (p = (const unsigned char *)symbol; *p != 0; p++) {
        if (!(isalnum(*p) || *p == '.' || *p == '_' || *p == '-' || *p == '/'))
            return 0;
        if (++n > 160)
            return 0;
    }
    return 1;
}

static int finish(char *dst, size_t dst_len, int n)
{
    if (dst == NULL || dst_len == 0 || n < 0 || (size_t)n >= dst_len) {
        if (dst != NULL && dst_len > 0)
            dst[0] = '\0';
        return -1;
    }
    return 0;
}

int bybit_topic_orderbook(char *dst, size_t dst_len, int depth, const char *symbol)
{
    if (depth <= 0 || depth > 10000 || !symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "orderbook.%d.%s", depth, symbol));
}

int bybit_topic_orderbook_full(char *dst, size_t dst_len, const char *symbol)
{
    if (!symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "orderbook.full.%s", symbol));
}

int bybit_topic_orderbook_rpi(char *dst, size_t dst_len, const char *symbol)
{
    if (!symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "orderbook.rpi.%s", symbol));
}

int bybit_topic_public_trade(char *dst, size_t dst_len, const char *symbol)
{
    if (!symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "publicTrade.%s", symbol));
}

int bybit_topic_kline(char *dst, size_t dst_len, const char *interval, const char *symbol)
{
    const unsigned char *p;
    if (interval == NULL || interval[0] == '\0' || !symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    for (p = (const unsigned char *)interval; *p != 0; p++) {
        if (!isalnum(*p))
            return finish(dst, dst_len, -1);
    }
    return finish(dst, dst_len, snprintf(dst, dst_len, "kline.%s.%s", interval, symbol));
}

int bybit_topic_ticker(char *dst, size_t dst_len, const char *symbol)
{
    if (!symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "tickers.%s", symbol));
}

int bybit_topic_all_liquidation(char *dst, size_t dst_len, const char *symbol)
{
    if (!symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "allLiquidation.%s", symbol));
}

int bybit_topic_insurance(char *dst, size_t dst_len, const char *coin)
{
    if (!symbol_ok(coin))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "insurance.%s", coin));
}

int bybit_topic_adl_alert(char *dst, size_t dst_len, const char *coin)
{
    if (!symbol_ok(coin))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "adlAlert.%s", coin));
}

int bybit_topic_price_limit(char *dst, size_t dst_len, const char *symbol)
{
    if (!symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "priceLimit.%s", symbol));
}

int bybit_topic_sbe_bbo(char *dst, size_t dst_len, const char *symbol)
{
    if (!symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "ob.rpi.1.sbe.%s", symbol));
}

int bybit_topic_sbe_ob50(char *dst, size_t dst_len, const char *symbol)
{
    if (!symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "ob.50.sbe.%s", symbol));
}

int bybit_topic_sbe_trade(char *dst, size_t dst_len, const char *symbol)
{
    if (!symbol_ok(symbol))
        return finish(dst, dst_len, -1);
    return finish(dst, dst_len, snprintf(dst, dst_len, "publicTrade.sbe.%s", symbol));
}

bybit_err bybit_sbe_header_decode(const void *frame, size_t len, bybit_sbe_header *out)
{
    const unsigned char *p = frame;
    if (out == NULL || frame == NULL || len < 8)
        return BYBIT_ERR_PARAM;
    out->block_length = (uint16_t)(p[0] | (p[1] << 8));
    out->template_id = (uint16_t)(p[2] | (p[3] << 8));
    out->schema_id = (uint16_t)(p[4] | (p[5] << 8));
    out->version = (uint16_t)(p[6] | (p[7] << 8));
    return BYBIT_OK;
}
