#include "internal.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bybit_buf_init(bybit_buf *buf)
{
    buf->data = NULL;
    buf->len = 0;
    buf->cap = 0;
    buf->max = 0;
}

void bybit_buf_free(bybit_buf *buf)
{
    free(buf->data);
    bybit_buf_init(buf);
}

void bybit_buf_set_max(bybit_buf *buf, size_t max)
{
    buf->max = max;
}

static int buf_reserve(bybit_buf *buf, size_t extra)
{
    size_t need;
    size_t cap;
    char *grown;

    if (extra > SIZE_MAX - buf->len - 1)
        return -1;
    need = buf->len + extra + 1;
    if (buf->max != 0 && need > buf->max + 1)
        return -1;
    if (need <= buf->cap)
        return 0;
    cap = buf->cap == 0 ? 64 : buf->cap;
    while (cap < need) {
        if (cap > SIZE_MAX / 2)
            return -1;
        cap *= 2;
    }
    if (buf->max != 0 && cap > buf->max + 1)
        cap = buf->max + 1;
    if (cap < need)
        return -1;
    grown = realloc(buf->data, cap);
    if (grown == NULL)
        return -1;
    buf->data = grown;
    buf->cap = cap;
    return 0;
}

int bybit_buf_append(bybit_buf *buf, const void *data, size_t n)
{
    if (n == 0)
        return 0;
    if (buf_reserve(buf, n) != 0)
        return -1;
    memcpy(buf->data + buf->len, data, n);
    buf->len += n;
    buf->data[buf->len] = '\0';
    return 0;
}

int bybit_buf_append_str(bybit_buf *buf, const char *s)
{
    if (s == NULL)
        return 0;
    return bybit_buf_append(buf, s, strlen(s));
}

int bybit_buf_printf(bybit_buf *buf, const char *fmt, ...)
{
    va_list ap;
    va_list aq;
    int need;
    char scratch[256];

    va_start(ap, fmt);
    va_copy(aq, ap);
    need = vsnprintf(scratch, sizeof scratch, fmt, ap);
    va_end(ap);
    if (need < 0) {
        va_end(aq);
        return -1;
    }
    if ((size_t)need < sizeof scratch) {
        va_end(aq);
        return bybit_buf_append(buf, scratch, (size_t)need);
    }
    if (buf_reserve(buf, (size_t)need) != 0) {
        va_end(aq);
        return -1;
    }
    vsnprintf(buf->data + buf->len, buf->cap - buf->len, fmt, aq);
    va_end(aq);
    buf->len += (size_t)need;
    return 0;
}

char *bybit_buf_detach(bybit_buf *buf)
{
    char *data = buf->data;
    if (data == NULL) {
        data = calloc(1, 1);
        if (data == NULL)
            return NULL;
    }
    buf->data = NULL;
    buf->len = 0;
    buf->cap = 0;
    return data;
}

char *bybit_xstrdup(const char *s)
{
    size_t n;
    char *out;

    if (s == NULL)
        return NULL;
    n = strlen(s);
    out = malloc(n + 1);
    if (out == NULL)
        return NULL;
    memcpy(out, s, n + 1);
    return out;
}

int64_t bybit_now_ms(void)
{
    struct timespec ts;

    if (clock_gettime(CLOCK_REALTIME, &ts) != 0)
        return 0;
    return (int64_t)ts.tv_sec * 1000 + (int64_t)ts.tv_nsec / 1000000;
}
