#include "internal.h"

#include <stdio.h>
#include <string.h>

static const char *rest_mainnet(bybit_site site)
{
    switch (site) {
    case BYBIT_SITE_BYTICK:
        return "https://api.bytick.com";
    case BYBIT_SITE_TR:
        return "https://api.bybit.tr";
    case BYBIT_SITE_KZ:
        return "https://api.bybit.kz";
    case BYBIT_SITE_GE:
        return "https://api.bybitgeorgia.ge";
    case BYBIT_SITE_AE:
        return "https://api.bybit.ae";
    case BYBIT_SITE_EU:
        return "https://api.bybit.eu";
    case BYBIT_SITE_ID:
        return "https://api.bybit.id";
    case BYBIT_SITE_JP:
        return "https://api.manepa.jp";
    case BYBIT_SITE_HK:
        return "https://api.spark-fintech.com";
    case BYBIT_SITE_GLOBAL:
    default:
        return "https://api.bybit.com";
    }
}

static const char *rest_testnet(bybit_site site)
{
    switch (site) {
    case BYBIT_SITE_JP:
        return "https://api-testnet.manepa.jp";
    case BYBIT_SITE_HK:
        return "https://api-testnet.spark-fintech.com";
    default:
        return "https://api-testnet.bybit.com";
    }
}

bybit_err bybit_build_rest_origin(bybit_env env, bybit_site site, char *buf, size_t buflen)
{
    const char *origin;

    if (buf == NULL || buflen == 0)
        return BYBIT_ERR_PARAM;
    if (env == BYBIT_DEMO)
        origin = "https://api-demo.bybit.com";
    else if (env == BYBIT_TESTNET)
        origin = rest_testnet(site);
    else if (env == BYBIT_MAINNET)
        origin = rest_mainnet(site);
    else
        return BYBIT_ERR_PARAM;
    if (strlen(origin) + 1 > buflen)
        return BYBIT_ERR_RANGE;
    memcpy(buf, origin, strlen(origin) + 1);
    return BYBIT_OK;
}

static int channel_path(bybit_ws_channel channel, const char **path, int *kind)
{
    /* kind: 0 public, 1 private, 2 trade, 3 sbe public, 4 sbe private, 5 sbe trade */
    switch (channel) {
    case BYBIT_WS_PUBLIC_SPOT:
        *path = "/v5/public/spot";
        *kind = 0;
        return 0;
    case BYBIT_WS_PUBLIC_LINEAR:
        *path = "/v5/public/linear";
        *kind = 0;
        return 0;
    case BYBIT_WS_PUBLIC_INVERSE:
        *path = "/v5/public/inverse";
        *kind = 0;
        return 0;
    case BYBIT_WS_PUBLIC_OPTION:
        *path = "/v5/public/option";
        *kind = 0;
        return 0;
    case BYBIT_WS_PUBLIC_SPREAD:
        *path = "/v5/public/spread";
        *kind = 0;
        return 0;
    case BYBIT_WS_PUBLIC_RFQ:
        *path = "/v5/public/rfq";
        *kind = 0;
        return 0;
    case BYBIT_WS_PUBLIC_EVENT:
        *path = "/v5/public/event";
        *kind = 0;
        return 0;
    case BYBIT_WS_PUBLIC_EARN:
        *path = "/v5/public/fp";
        *kind = 0;
        return 0;
    case BYBIT_WS_SYSTEM:
        *path = "/v5/public/misc/status";
        *kind = 0;
        return 0;
    case BYBIT_WS_PRIVATE:
        *path = "/v5/private";
        *kind = 1;
        return 0;
    case BYBIT_WS_TRADE:
        *path = "/v5/trade";
        *kind = 2;
        return 0;
    case BYBIT_WS_SBE_SPOT:
        *path = "/v5/public-sbe/spot";
        *kind = 3;
        return 0;
    case BYBIT_WS_SBE_LINEAR:
        *path = "/v5/public-sbe/linear";
        *kind = 3;
        return 0;
    case BYBIT_WS_SBE_INVERSE:
        *path = "/v5/public-sbe/inverse";
        *kind = 3;
        return 0;
    case BYBIT_WS_SBE_PRIVATE:
        *path = "/v5/private-sbe";
        *kind = 4;
        return 0;
    case BYBIT_WS_SBE_TRADE:
        *path = "/v5/trade-sbe";
        *kind = 5;
        return 0;
    default:
        return -1;
    }
}

static const char *ws_mainnet(bybit_site site)
{
    switch (site) {
    case BYBIT_SITE_TR:
        return "stream.bybit.tr";
    case BYBIT_SITE_KZ:
        return "stream.bybit.kz";
    case BYBIT_SITE_GE:
        return "stream.bybitgeorgia.ge";
    case BYBIT_SITE_AE:
        return "stream.bybit.ae";
    case BYBIT_SITE_EU:
        return "stream.bybit.eu";
    case BYBIT_SITE_ID:
        return "stream.bybit.id";
    case BYBIT_SITE_JP:
        return "stream.manepa.jp";
    case BYBIT_SITE_HK:
        return "stream.spark-fintech.com";
    case BYBIT_SITE_GLOBAL:
    case BYBIT_SITE_BYTICK:
    default:
        return "stream.bybit.com";
    }
}

static const char *ws_testnet(bybit_site site)
{
    switch (site) {
    case BYBIT_SITE_JP:
        return "stream-testnet.manepa.jp";
    case BYBIT_SITE_HK:
        return "stream-testnet.spark-fintech.com";
    default:
        return "stream-testnet.bybit.com";
    }
}

static int valid_max_active(const char *s)
{
    size_t i;
    if (s == NULL || s[0] == '\0')
        return 1;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] < '0' || s[i] > '9')
            break;
    }
    if (i == 0 || i > 4)
        return 0;
    if (s[i] == '\0')
        return 1;
    if ((s[i] == 's' || s[i] == 'm') && s[i + 1] == '\0')
        return 1;
    return 0;
}

bybit_err bybit_build_ws_url(bybit_env env, bybit_site site,
                             bybit_ws_channel channel,
                             const char *ws_host,
                             const char *max_active_time,
                             char *buf, size_t buflen)
{
    const char *path = NULL;
    const char *host;
    int kind = 0;
    int n;

    if (buf == NULL || buflen == 0)
        return BYBIT_ERR_PARAM;
    buf[0] = '\0';
    if (channel_path(channel, &path, &kind) != 0)
        return BYBIT_ERR_PARAM;
    if (!valid_max_active(max_active_time))
        return BYBIT_ERR_PARAM;
    if (max_active_time != NULL && max_active_time[0] != '\0' && kind != 1 && kind != 2 &&
        kind != 4 && kind != 5)
        return BYBIT_ERR_PARAM;

    if (env == BYBIT_DEMO) {
        if (kind == 2 || kind == 3 || kind == 4 || kind == 5)
            return BYBIT_ERR_PARAM;
        if (kind == 1)
            host = "stream-demo.bybit.com";
        else
            host = "stream.bybit.com";
    } else if (kind == 3 || kind == 4 || kind == 5) {
        if (env == BYBIT_TESTNET)
            host = "stream-testnet.bybits.org";
        else if (env == BYBIT_MAINNET)
            host = "stream.bybit.com";
        else
            return BYBIT_ERR_PARAM;
    } else if (env == BYBIT_TESTNET) {
        host = ws_testnet(site);
    } else if (env == BYBIT_MAINNET) {
        host = ws_mainnet(site);
    } else {
        return BYBIT_ERR_PARAM;
    }
    if (ws_host != NULL && ws_host[0] != '\0')
        host = ws_host;

    if (max_active_time != NULL && max_active_time[0] != '\0')
        n = snprintf(buf, buflen, "wss://%s%s?max_active_time=%s", host, path, max_active_time);
    else
        n = snprintf(buf, buflen, "wss://%s%s", host, path);
    if (n < 0 || (size_t)n >= buflen)
        return BYBIT_ERR_RANGE;
    return BYBIT_OK;
}
