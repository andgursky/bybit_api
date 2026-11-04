#include "internal.h"

#include <stdlib.h>
#include <string.h>

static void level_clear(struct bybit_level *level)
{
    free(level->price);
    free(level->size);
    level->price = NULL;
    level->size = NULL;
}

static void side_clear(struct bybit_level **levels, size_t *n)
{
    size_t i;
    if (*levels == NULL) {
        *n = 0;
        return;
    }
    for (i = 0; i < *n; i++)
        level_clear(&(*levels)[i]);
    free(*levels);
    *levels = NULL;
    *n = 0;
}

void bybit_orderbook_reset(bybit_orderbook *book)
{
    if (book == NULL)
        return;
    side_clear(&book->bids, &book->n_bids);
    side_clear(&book->asks, &book->n_asks);
    free(book->symbol);
    free(book->topic);
    memset(book, 0, sizeof(*book));
}

bybit_orderbook *bybit_orderbook_create(void)
{
    return calloc(1, sizeof(bybit_orderbook));
}

void bybit_orderbook_destroy(bybit_orderbook *book)
{
    if (book == NULL)
        return;
    bybit_orderbook_reset(book);
    free(book);
}

static void split_dec(const char *s, const char **ip, size_t *il, const char **fp, size_t *fl)
{
    const char *dot = strchr(s, '.');
    if (dot == NULL) {
        *ip = s;
        *il = strlen(s);
        *fp = "";
        *fl = 0;
    } else {
        *ip = s;
        *il = (size_t)(dot - s);
        *fp = dot + 1;
        *fl = strlen(*fp);
    }
    while (*il > 0 && **ip == '0') {
        (*ip)++;
        (*il)--;
    }
    while (*fl > 0 && (*fp)[*fl - 1] == '0')
        (*fl)--;
}

static int dec_is_zero(const char *s)
{
    const char *ip;
    const char *fp;
    size_t il;
    size_t fl;
    if (s == NULL || s[0] == '\0')
        return 0;
    if (s[0] == '-')
        return 0;
    split_dec(s, &ip, &il, &fp, &fl);
    return il == 0 && fl == 0;
}

static int dec_cmp(const char *a, const char *b)
{
    const char *aip;
    const char *bip;
    const char *afp;
    const char *bfp;
    size_t ail;
    size_t bil;
    size_t afl;
    size_t bfl;
    size_t n;
    int cmp;

    split_dec(a, &aip, &ail, &afp, &afl);
    split_dec(b, &bip, &bil, &bfp, &bfl);
    if (ail != bil)
        return ail > bil ? 1 : -1;
    if (ail > 0) {
        cmp = memcmp(aip, bip, ail);
        if (cmp != 0)
            return cmp;
    }
    n = afl < bfl ? afl : bfl;
    if (n > 0) {
        cmp = memcmp(afp, bfp, n);
        if (cmp != 0)
            return cmp;
    }
    if (afl != bfl)
        return afl > bfl ? 1 : -1;
    return 0;
}

static void sort_side(struct bybit_level *levels, size_t n, int descending)
{
    size_t i;
    for (i = 1; i < n; i++) {
        struct bybit_level key = levels[i];
        size_t j = i;
        while (j > 0) {
            int cmp = dec_cmp(levels[j - 1].price, key.price);
            int out_of_order = descending ? cmp < 0 : cmp > 0;
            if (!out_of_order)
                break;
            levels[j] = levels[j - 1];
            j--;
        }
        levels[j] = key;
    }
}

static bybit_err side_apply(struct bybit_level **levels, size_t *n, const bybit_json *arr, int descending)
{
    size_t i;
    size_t count;
    size_t cap;

    if (arr == NULL || bybit_json_get_type(arr) == BYBIT_JSON_NULL)
        return BYBIT_OK;
    if (bybit_json_get_type(arr) != BYBIT_JSON_ARRAY)
        return BYBIT_ERR_JSON;
    count = bybit_json_length(arr);
    for (i = 0; i < count; i++) {
        const bybit_json *row = bybit_json_index(arr, i);
        const bybit_json *price_n;
        const bybit_json *size_n;
        const char *price;
        const char *size;
        size_t found = (size_t)-1;
        size_t j;
        if (row == NULL || bybit_json_get_type(row) != BYBIT_JSON_ARRAY || bybit_json_length(row) < 2)
            return BYBIT_ERR_JSON;
        price_n = bybit_json_index(row, 0);
        size_n = bybit_json_index(row, 1);
        price = bybit_json_string(price_n);
        size = bybit_json_string(size_n);
        if (price == NULL || size == NULL)
            return BYBIT_ERR_JSON;
        for (j = 0; j < *n; j++) {
            if (dec_cmp((*levels)[j].price, price) == 0) {
                found = j;
                break;
            }
        }
        if (dec_is_zero(size)) {
            if (found != (size_t)-1) {
                level_clear(&(*levels)[found]);
                memmove(&(*levels)[found], &(*levels)[found + 1],
                        (*n - found - 1) * sizeof(**levels));
                (*n)--;
            }
            continue;
        }
        if (found != (size_t)-1) {
            char *copy = bybit_xstrdup(size);
            if (copy == NULL)
                return BYBIT_ERR_NOMEM;
            free((*levels)[found].size);
            (*levels)[found].size = copy;
            continue;
        }
        cap = *n + 1;
        {
            struct bybit_level *grown = realloc(*levels, cap * sizeof(*grown));
            char *ps;
            char *ss;
            if (grown == NULL)
                return BYBIT_ERR_NOMEM;
            *levels = grown;
            ps = bybit_xstrdup(price);
            ss = bybit_xstrdup(size);
            if (ps == NULL || ss == NULL) {
                free(ps);
                free(ss);
                return BYBIT_ERR_NOMEM;
            }
            (*levels)[*n].price = ps;
            (*levels)[*n].size = ss;
            (*n)++;
        }
    }
    sort_side(*levels, *n, descending);
    return BYBIT_OK;
}

static int64_t json_i64(const bybit_json *node, int *present)
{
    const char *s;
    char *end = NULL;
    long long v;
    *present = 0;
    if (node == NULL)
        return 0;
    s = bybit_json_string(node);
    if (s == NULL || s[0] == '\0')
        return 0;
    v = strtoll(s, &end, 10);
    if (end == s)
        return 0;
    *present = 1;
    return (int64_t)v;
}

bybit_err bybit_orderbook_apply(bybit_orderbook *book, const char *json, size_t len)
{
    const char *err = NULL;
    bybit_json_doc *doc;
    const bybit_json *root;
    const bybit_json *data;
    const bybit_json *type_n;
    const bybit_json *topic_n;
    const char *type;
    const char *topic;
    int present = 0;
    int64_t u;
    int snapshot;
    bybit_err rc;

    if (book == NULL || json == NULL)
        return BYBIT_ERR_PARAM;
    if (len == 0)
        len = strlen(json);
    doc = bybit_json_parse(json, len, &err);
    if (doc == NULL)
        return BYBIT_ERR_JSON;
    root = bybit_json_root(doc);
    topic_n = bybit_json_object_get(root, "topic");
    topic = bybit_json_string(topic_n);
    if (topic == NULL || strstr(topic, "orderbook") == NULL) {
        bybit_json_doc_free(doc);
        return BYBIT_ERR_PARAM;
    }
    type_n = bybit_json_object_get(root, "type");
    type = bybit_json_string(type_n);
    if (type == NULL) {
        bybit_json_doc_free(doc);
        return BYBIT_ERR_JSON;
    }
    snapshot = strcmp(type, "snapshot") == 0;
    if (!snapshot && strcmp(type, "delta") != 0) {
        bybit_json_doc_free(doc);
        return BYBIT_ERR_JSON;
    }
    data = bybit_json_object_get(root, "data");
    if (data == NULL || bybit_json_get_type(data) != BYBIT_JSON_OBJECT) {
        bybit_json_doc_free(doc);
        return BYBIT_ERR_JSON;
    }
    if (snapshot) {
        side_clear(&book->bids, &book->n_bids);
        side_clear(&book->asks, &book->n_asks);
        book->gap = 0;
    }
    rc = side_apply(&book->bids, &book->n_bids, bybit_json_object_get(data, "b"), 1);
    if (rc == BYBIT_OK)
        rc = side_apply(&book->asks, &book->n_asks, bybit_json_object_get(data, "a"), 0);
    if (rc != BYBIT_OK) {
        bybit_json_doc_free(doc);
        return rc;
    }
    {
        const bybit_json *sym = bybit_json_object_get(data, "s");
        if (sym != NULL && bybit_json_string(sym) != NULL) {
            char *copy = bybit_xstrdup(bybit_json_string(sym));
            if (copy == NULL) {
                bybit_json_doc_free(doc);
                return BYBIT_ERR_NOMEM;
            }
            free(book->symbol);
            book->symbol = copy;
        }
    }
    {
        char *copy = bybit_xstrdup(topic);
        if (copy == NULL) {
            bybit_json_doc_free(doc);
            return BYBIT_ERR_NOMEM;
        }
        free(book->topic);
        book->topic = copy;
    }
    u = json_i64(bybit_json_object_get(data, "u"), &present);
    if (present) {
        if (!snapshot && book->u != 0 && u != book->u + 1)
            book->gap = 1;
        else if (!snapshot)
            book->gap = 0;
        book->u = u;
    }
    {
        int64_t seq = json_i64(bybit_json_object_get(data, "seq"), &present);
        if (present)
            book->seq = seq;
        seq = json_i64(bybit_json_object_get(root, "ts"), &present);
        if (present)
            book->ts = seq;
        seq = json_i64(bybit_json_object_get(root, "cts"), &present);
        if (present)
            book->cts = seq;
    }
    bybit_json_doc_free(doc);
    return BYBIT_OK;
}
