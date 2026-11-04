#include "bybit.h"

#include <openssl/evp.h>
#include <openssl/pem.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bybit_ws_accept_ok(const char *client_key, const char *accept_value);

static int g_failed = 0;

static void expect(int cond, const char *msg)
{
    if (!cond) {
        fprintf(stderr, "FAIL %s\n", msg);
        g_failed++;
    }
}

static void test_hmac(void)
{
    char hex[BYBIT_HMAC_HEX_LEN + 1];
    const char *msg = "1658384314791XXXXXXXXXX5000category=option&symbol=BTC-29JUL22-25000-C";
    bybit_err err = bybit_hmac_sha256_hex("test-secret", strlen("test-secret"), msg, strlen(msg), hex);
    expect(err == BYBIT_OK, "hmac ok");
    expect(strcmp(hex, "236d8f7132d3e4c8bad803010e296f3d07211356e54c01455b26c8229a682297") == 0, "hmac hex");

    msg = "1658385579423XXXXXXXXXX5000{\"category\": \"option\"}";
    err = bybit_hmac_sha256_hex("test-secret", strlen("test-secret"), msg, strlen(msg), hex);
    expect(err == BYBIT_OK &&
               strcmp(hex, "17a6bfe3e7a2aa41dffd3f16bfa0febb8b18ff79bb33de625705dc86876feffe") == 0,
           "hmac post");
}

static void test_canonical(void)
{
    char *out = NULL;
    bybit_err err = bybit_auth_canonical("1658384314791", "XXXXXXXXXX", "5000",
                                         "category=option&symbol=BTC-29JUL22-25000-C", &out);
    expect(err == BYBIT_OK, "canonical");
    expect(strcmp(out, "1658384314791XXXXXXXXXX5000category=option&symbol=BTC-29JUL22-25000-C") == 0,
           "canonical bytes");
    free(out);
    err = bybit_ws_auth_canonical("1662350400000", &out);
    expect(err == BYBIT_OK && strcmp(out, "GET/realtime1662350400000") == 0, "ws canonical");
    free(out);
    {
        char hex[BYBIT_HMAC_HEX_LEN + 1];
        err = bybit_hmac_sha256_hex("test-secret", 11, "GET/realtime1662350400000",
                                    strlen("GET/realtime1662350400000"), hex);
        expect(strcmp(hex, "f072aab6fa18cd774da998325df6cfc87c3ccf10d5722e6b43b570c5feaf6172") == 0,
               "ws hmac");
    }
}

static void test_query(void)
{
    char *q = NULL;
    bybit_kv fields[] = {
        BYBIT_STR("category", "option"),
        BYBIT_STR("symbol", "BTC-29JUL22-25000-C"),
        BYBIT_STR("skip", NULL),
        BYBIT_STR("note", "a b/c"),
    };
    expect(bybit_query_encode(fields, 4, &q) == BYBIT_OK, "query");
    expect(strcmp(q, "category=option&symbol=BTC-29JUL22-25000-C&note=a%20b%2Fc") == 0, "query text");
    free(q);
}

static void test_json(void)
{
    const char *err = NULL;
    const char *text =
        "{\"retCode\":0,\"retMsg\":\"OK\",\"result\":{\"timeSecond\":\"1\"},\"retExtInfo\":{},\"time\":1688639403427}";
    bybit_json_doc *doc = bybit_json_parse(text, strlen(text), &err);
    const bybit_json *root;
    const bybit_json *result;
    size_t n = 0;
    const char *slice;
    char *obj = NULL;
    bybit_kv fields[] = {
        BYBIT_STR("category", "option"),
        BYBIT_RAW("n", "1"),
        BYBIT_STR("name", "a\"b"),
    };
    expect(doc != NULL, "parse envelope");
    root = bybit_json_root(doc);
    expect(strcmp(bybit_json_string(bybit_json_object_get(root, "retMsg")), "OK") == 0, "retMsg");
    result = bybit_json_object_get(root, "result");
    slice = bybit_json_slice(result, &n);
    expect(slice != NULL && n == strlen("{\"timeSecond\":\"1\"}") &&
               memcmp(slice, "{\"timeSecond\":\"1\"}", n) == 0,
           "result slice");
    bybit_json_doc_free(doc);

    doc = bybit_json_parse("\"\\uD83D\\uDE00\"", strlen("\"\\uD83D\\uDE00\""), &err);
    expect(doc != NULL, "surrogate");
    expect(strcmp(bybit_json_string(bybit_json_root(doc)), "\xF0\x9F\x98\x80") == 0, "emoji");
    bybit_json_doc_free(doc);

    doc = bybit_json_parse("01", 2, &err);
    expect(doc == NULL, "leading zero");
    doc = bybit_json_parse("{\"a\":1} ", 8, &err);
    expect(doc != NULL, "trailing space");
    bybit_json_doc_free(doc);
    doc = bybit_json_parse("{\"a\":1} x", 9, &err);
    expect(doc == NULL, "trailing junk");

    expect(bybit_json_object_from_kv(fields, 3, &obj) == BYBIT_OK, "object");
    expect(strcmp(obj, "{\"category\":\"option\",\"n\":1,\"name\":\"a\\\"b\"}") == 0, "object text");
    free(obj);
}

static void test_book(void)
{
    bybit_orderbook *book = bybit_orderbook_create();
    const char *snap =
        "{\"topic\":\"orderbook.1.BTCUSDT\",\"type\":\"snapshot\",\"ts\":1000,\"cts\":999,"
        "\"data\":{\"s\":\"BTCUSDT\",\"b\":[[\"100.5\",\"2\"],[\"99\",\"1\"]],"
        "\"a\":[[\"101\",\"3\"],[\"102\",\"4\"]],\"u\":10,\"seq\":20}}";
    const char *delta =
        "{\"topic\":\"orderbook.1.BTCUSDT\",\"type\":\"delta\",\"ts\":\"1001\","
        "\"data\":{\"s\":\"BTCUSDT\",\"b\":[[\"100.5\",\"0\"],[\"100\",\"5\"]],"
        "\"a\":[[\"101\",\"3.5\"]],\"u\":11,\"seq\":21}}";
    expect(bybit_orderbook_apply(book, snap, 0) == BYBIT_OK, "snap");
    expect(book->n_bids == 2 && strcmp(book->bids[0].price, "100.5") == 0, "bid order");
    expect(bybit_orderbook_apply(book, delta, 0) == BYBIT_OK, "delta");
    expect(book->gap == 0, "no gap");
    expect(book->n_bids == 2, "bid count");
    expect(strcmp(book->bids[0].price, "100") == 0 && strcmp(book->bids[0].size, "5") == 0, "new bid");
    expect(strcmp(book->bids[1].price, "99") == 0, "old bid");
    expect(book->n_asks == 2 && strcmp(book->asks[0].size, "3.5") == 0, "ask update");
    expect(book->u == 11 && book->ts == 1001, "ids");
    expect(bybit_orderbook_apply(book, "{\"topic\":\"publicTrade.BTCUSDT\",\"type\":\"snapshot\"}", 0) ==
               BYBIT_ERR_PARAM,
           "reject trade");
    bybit_orderbook_destroy(book);
}

static void test_catalog(void)
{
    const bybit_endpoint *ep;
    bybit_response *out = NULL;
    expect(bybit_endpoint_count() == 448, "count");
    ep = bybit_endpoint_find("POST", "/v5/order/create");
    expect(ep != NULL && ep->auth_required == 1 && strcmp(ep->name, "bybit_order_create") == 0, "create");
    ep = bybit_endpoint_find("GET", "/v5/market/time");
    expect(ep != NULL && ep->auth_required == 0, "time public");
    ep = bybit_endpoint_find("GET", "/v5/order/realtime");
    expect(ep != NULL && ep->auth_required == 1, "realtime private");
    expect(bybit_market_time(NULL, NULL, 0, &out) == BYBIT_ERR_PARAM, "null client");
    expect(out == NULL, "no response");
}

static void test_hosts(void)
{
    char buf[256];
    expect(bybit_build_rest_origin(BYBIT_MAINNET, BYBIT_SITE_TR, buf, sizeof buf) == BYBIT_OK, "rest");
    expect(strcmp(buf, "https://api.bybit.tr") == 0, "tr rest");
    expect(bybit_build_rest_origin(BYBIT_DEMO, BYBIT_SITE_GLOBAL, buf, sizeof buf) == BYBIT_OK, "demo");
    expect(strcmp(buf, "https://api-demo.bybit.com") == 0, "demo rest");
    expect(bybit_build_rest_origin(BYBIT_TESTNET, BYBIT_SITE_JP, buf, sizeof buf) == BYBIT_OK, "jp");
    expect(strcmp(buf, "https://api-testnet.manepa.jp") == 0, "jp rest");
    expect(bybit_build_ws_url(BYBIT_TESTNET, BYBIT_SITE_GLOBAL, BYBIT_WS_PUBLIC_SPOT, NULL, NULL, buf,
                              sizeof buf) == BYBIT_OK,
           "ws spot");
    expect(strcmp(buf, "wss://stream-testnet.bybit.com/v5/public/spot") == 0, "ws spot url");
    expect(bybit_build_ws_url(BYBIT_DEMO, BYBIT_SITE_GLOBAL, BYBIT_WS_PRIVATE, NULL, "1m", buf,
                              sizeof buf) == BYBIT_OK,
           "demo private");
    expect(strcmp(buf, "wss://stream-demo.bybit.com/v5/private?max_active_time=1m") == 0, "demo url");
    expect(bybit_build_ws_url(BYBIT_DEMO, BYBIT_SITE_GLOBAL, BYBIT_WS_PUBLIC_LINEAR, NULL, NULL, buf,
                              sizeof buf) == BYBIT_OK,
           "demo public");
    expect(strcmp(buf, "wss://stream.bybit.com/v5/public/linear") == 0, "demo public url");
    expect(bybit_build_ws_url(BYBIT_DEMO, BYBIT_SITE_GLOBAL, BYBIT_WS_TRADE, NULL, NULL, buf,
                              sizeof buf) == BYBIT_ERR_PARAM,
           "demo trade rejected");
    expect(bybit_build_ws_url(BYBIT_MAINNET, BYBIT_SITE_EU, BYBIT_WS_SYSTEM, NULL, NULL, buf,
                              sizeof buf) == BYBIT_OK,
           "eu status");
    expect(strcmp(buf, "wss://stream.bybit.eu/v5/public/misc/status") == 0, "eu url");
    expect(bybit_build_ws_url(BYBIT_TESTNET, BYBIT_SITE_GLOBAL, BYBIT_WS_SBE_SPOT, NULL, NULL, buf,
                              sizeof buf) == BYBIT_OK,
           "sbe");
    expect(strcmp(buf, "wss://stream-testnet.bybits.org/v5/public-sbe/spot") == 0, "sbe url");
    expect(bybit_build_ws_url(BYBIT_MAINNET, BYBIT_SITE_GLOBAL, BYBIT_WS_PUBLIC_SPOT, NULL, "1m", buf,
                              sizeof buf) == BYBIT_ERR_PARAM,
           "public max active");
}

static void test_topics(void)
{
    char buf[128];
    unsigned char frame[8] = {8, 0, 2, 0, 1, 0, 3, 0};
    bybit_sbe_header hdr;
    expect(bybit_topic_orderbook(buf, sizeof buf, 1, "BTCUSDT") == 0, "ob");
    expect(strcmp(buf, "orderbook.1.BTCUSDT") == 0, "ob text");
    expect(bybit_topic_kline(buf, sizeof buf, "30", "BTCUSDT") == 0, "kline");
    expect(strcmp(buf, "kline.30.BTCUSDT") == 0, "kline text");
    expect(bybit_topic_public_trade(buf, sizeof buf, "BTC") == 0, "trade");
    expect(strcmp(buf, "publicTrade.BTC") == 0, "trade text");
    expect(bybit_topic_orderbook(buf, sizeof buf, 1, "bad symbol") != 0, "bad symbol");
    expect(bybit_topic_sbe_bbo(buf, sizeof buf, "ETHUSDT") == 0, "sbe bbo");
    expect(strcmp(buf, "ob.rpi.1.sbe.ETHUSDT") == 0, "sbe bbo text");
    expect(bybit_sbe_header_decode(frame, sizeof frame, &hdr) == BYBIT_OK, "sbe hdr");
    expect(hdr.block_length == 8 && hdr.template_id == 2 && hdr.schema_id == 1 && hdr.version == 3,
           "sbe fields");
}

static void test_rsa(void)
{
    EVP_PKEY *pkey = NULL;
    EVP_PKEY_CTX *ctx = NULL;
    BIO *bio = NULL;
    char *pem = NULL;
    long pem_len = 0;
    char *sig = NULL;
    const char *msg = "1658384314791XXXXXXXXXX5000category=option";
    EVP_MD_CTX *md = NULL;
    int verified = 0;

    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    expect(ctx != NULL && EVP_PKEY_keygen_init(ctx) == 1 && EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 2048) == 1 &&
               EVP_PKEY_keygen(ctx, &pkey) == 1,
           "rsa key");
    bio = BIO_new(BIO_s_mem());
    expect(bio != NULL && PEM_write_bio_PrivateKey(bio, pkey, NULL, NULL, 0, NULL, NULL) == 1, "pem");
    pem_len = BIO_get_mem_data(bio, &pem);
    expect(pem_len > 0, "pem len");
    {
        char *copy = malloc((size_t)pem_len + 1);
        expect(copy != NULL, "pem copy");
        memcpy(copy, pem, (size_t)pem_len);
        copy[pem_len] = '\0';
        expect(bybit_rsa_sha256_base64(copy, msg, strlen(msg), &sig) == BYBIT_OK, "rsa sign");
        free(copy);
    }
    md = EVP_MD_CTX_new();
    {
        unsigned char raw[512];
        int raw_len = EVP_DecodeBlock(raw, (const unsigned char *)sig, (int)strlen(sig));
        int pad = 0;
        size_t i = strlen(sig);
        while (i > 0 && sig[i - 1] == '=') {
            pad++;
            i--;
        }
        raw_len -= pad;
        expect(raw_len > 0, "rsa decode");
        expect(EVP_DigestVerifyInit(md, NULL, EVP_sha256(), NULL, pkey) == 1, "verify init");
        expect(EVP_DigestVerifyUpdate(md, msg, strlen(msg)) == 1, "verify update");
        verified = EVP_DigestVerifyFinal(md, raw, (size_t)raw_len) == 1;
        expect(verified, "rsa verify");
    }
    free(sig);
    EVP_MD_CTX_free(md);
    BIO_free(bio);
    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(ctx);
}

static void test_ws_accept(void)
{
    expect(bybit_ws_accept_ok("dGhlIHNhbXBsZSBub25jZQ==", "s3pPLMBiTxaQ9kYGzzhZRbK+xOo=") == 1,
           "rfc accept");
    expect(bybit_ws_accept_ok("dGhlIHNhbXBsZSBub25jZQ==", "nope") == 0, "bad accept");
}

static void test_client_url(void)
{
    bybit_config cfg;
    bybit_client *client;
    memset(&cfg, 0, sizeof cfg);
    expect(bybit_client_create(NULL) == NULL, "null cfg");
    cfg.api_key = "only-key";
    expect(bybit_client_create(&cfg) == NULL, "half key");
    memset(&cfg, 0, sizeof cfg);
    cfg.env = BYBIT_TESTNET;
    cfg.site = BYBIT_SITE_KZ;
    client = bybit_client_create(&cfg);
    expect(client != NULL, "client");
    expect(strcmp(bybit_client_rest_url(client), "https://api-testnet.bybit.com") == 0, "testnet origin");
    bybit_client_destroy(client);
    bybit_response_free(NULL);
}

int main(void)
{
    test_hmac();
    test_canonical();
    test_query();
    test_json();
    test_book();
    test_catalog();
    test_hosts();
    test_topics();
    test_rsa();
    test_ws_accept();
    test_client_url();
    if (g_failed != 0) {
        fprintf(stderr, "%d assertion(s) failed\n", g_failed);
        return 1;
    }
    printf("unit ok\n");
    return 0;
}
