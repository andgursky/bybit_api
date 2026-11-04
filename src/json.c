#include "internal.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bybit_json {
    bybit_json_type type;
    const char *key;
    const char *str;
    const char *raw;
    size_t raw_off;
    size_t raw_len;
    struct bybit_json *child;
    struct bybit_json *last;
    struct bybit_json *next;
    size_t nchild;
};

typedef struct bybit_chunk {
    struct bybit_chunk *next;
    size_t used;
    size_t cap;
    unsigned char data[1];
} bybit_chunk;

struct bybit_json_doc {
    char *source;
    size_t source_len;
    bybit_chunk *chunks;
    const bybit_json *root;
};

typedef struct parser {
    const char *s;
    size_t n;
    size_t i;
    int depth;
    bybit_json_doc *doc;
    const char *err;
} parser;

static void *arena_alloc(bybit_json_doc *doc, size_t n, size_t align)
{
    bybit_chunk *chunk;
    size_t pad;
    size_t cap;

    if (align == 0)
        align = 1;
    chunk = doc->chunks;
    if (chunk != NULL) {
        pad = (align - (chunk->used % align)) % align;
        if (chunk->used <= chunk->cap && pad <= chunk->cap - chunk->used &&
            n <= chunk->cap - chunk->used - pad) {
            void *ptr = chunk->data + chunk->used + pad;
            chunk->used += pad + n;
            return ptr;
        }
    }
    cap = n + align + 64;
    if (cap < 4096)
        cap = 4096;
    chunk = malloc(sizeof(bybit_chunk) + cap);
    if (chunk == NULL)
        return NULL;
    chunk->next = doc->chunks;
    chunk->used = 0;
    chunk->cap = cap;
    doc->chunks = chunk;
    pad = (align - (chunk->used % align)) % align;
    if (n > chunk->cap - pad) {
        return NULL;
    }
    {
        void *ptr = chunk->data + pad;
        chunk->used = pad + n;
        return ptr;
    }
}

static char *arena_copy(bybit_json_doc *doc, const char *s, size_t n)
{
    char *out = arena_alloc(doc, n + 1, 1);
    if (out == NULL)
        return NULL;
    memcpy(out, s, n);
    out[n] = '\0';
    return out;
}

static int fail(parser *p, const char *msg)
{
    if (p->err == NULL)
        p->err = msg;
    return -1;
}

static void skip_ws(parser *p)
{
    while (p->i < p->n) {
        char c = p->s[p->i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
            p->i++;
        else
            break;
    }
}

static int utf8_encode(unsigned cp, char out[4])
{
    if (cp > 0x10FFFFu || (cp >= 0xD800u && cp <= 0xDFFFu))
        return -1;
    if (cp <= 0x7Fu) {
        out[0] = (char)cp;
        return 1;
    }
    if (cp <= 0x7FFu) {
        out[0] = (char)(0xC0u | (cp >> 6));
        out[1] = (char)(0x80u | (cp & 0x3Fu));
        return 2;
    }
    if (cp <= 0xFFFFu) {
        out[0] = (char)(0xE0u | (cp >> 12));
        out[1] = (char)(0x80u | ((cp >> 6) & 0x3Fu));
        out[2] = (char)(0x80u | (cp & 0x3Fu));
        return 3;
    }
    out[0] = (char)(0xF0u | (cp >> 18));
    out[1] = (char)(0x80u | ((cp >> 12) & 0x3Fu));
    out[2] = (char)(0x80u | ((cp >> 6) & 0x3Fu));
    out[3] = (char)(0x80u | (cp & 0x3Fu));
    return 4;
}

static int hex4(parser *p, unsigned *out)
{
    unsigned v = 0;
    int k;

    if (p->i + 4 > p->n)
        return fail(p, "truncated unicode escape");
    for (k = 0; k < 4; k++) {
        unsigned char c = (unsigned char)p->s[p->i++];
        v <<= 4;
        if (c >= '0' && c <= '9')
            v |= (unsigned)(c - '0');
        else if (c >= 'a' && c <= 'f')
            v |= (unsigned)(c - 'a' + 10);
        else if (c >= 'A' && c <= 'F')
            v |= (unsigned)(c - 'A' + 10);
        else
            return fail(p, "invalid unicode escape");
    }
    *out = v;
    return 0;
}

static char *parse_string(parser *p)
{
    bybit_buf buf;
    char utf[4];

    if (p->i >= p->n || p->s[p->i] != '"') {
        fail(p, "expected string");
        return NULL;
    }
    p->i++;
    bybit_buf_init(&buf);
    while (p->i < p->n) {
        unsigned char c = (unsigned char)p->s[p->i++];
        if (c == '"') {
            char *out = arena_copy(p->doc, buf.data == NULL ? "" : buf.data, buf.len);
            bybit_buf_free(&buf);
            if (out == NULL)
                fail(p, "out of memory");
            return out;
        }
        if (c == '\\') {
            unsigned char e;
            if (p->i >= p->n) {
                fail(p, "truncated string escape");
                break;
            }
            e = (unsigned char)p->s[p->i++];
            if (e == '"' || e == '\\' || e == '/')
                c = e;
            else if (e == 'b')
                c = '\b';
            else if (e == 'f')
                c = '\f';
            else if (e == 'n')
                c = '\n';
            else if (e == 'r')
                c = '\r';
            else if (e == 't')
                c = '\t';
            else if (e == 'u') {
                unsigned cp;
                int n;
                if (hex4(p, &cp) != 0)
                    break;
                if (cp >= 0xD800u && cp <= 0xDBFFu) {
                    unsigned lo;
                    if (p->i + 2 > p->n || p->s[p->i] != '\\' || p->s[p->i + 1] != 'u') {
                        fail(p, "lonely surrogate");
                        break;
                    }
                    p->i += 2;
                    if (hex4(p, &lo) != 0)
                        break;
                    if (lo < 0xDC00u || lo > 0xDFFFu) {
                        fail(p, "invalid surrogate pair");
                        break;
                    }
                    cp = 0x10000u + (((cp - 0xD800u) << 10) | (lo - 0xDC00u));
                } else if (cp >= 0xDC00u && cp <= 0xDFFFu) {
                    fail(p, "lonely surrogate");
                    break;
                }
                n = utf8_encode(cp, utf);
                if (n < 0 || bybit_buf_append(&buf, utf, (size_t)n) != 0) {
                    fail(p, "invalid code point");
                    break;
                }
                continue;
            } else {
                fail(p, "invalid string escape");
                break;
            }
        } else if (c < 0x20u) {
            fail(p, "raw control character in string");
            break;
        }
        if (bybit_buf_append(&buf, &c, 1) != 0) {
            fail(p, "out of memory");
            break;
        }
    }
    bybit_buf_free(&buf);
    if (p->err == NULL)
        fail(p, "unterminated string");
    return NULL;
}

static bybit_json *parse_value(parser *p);

static bybit_json *make_node(parser *p, bybit_json_type type, size_t start)
{
    bybit_json *node = arena_alloc(p->doc, sizeof(*node), sizeof(void *));
    if (node == NULL) {
        fail(p, "out of memory");
        return NULL;
    }
    memset(node, 0, sizeof(*node));
    node->type = type;
    node->raw_off = start;
    return node;
}

static int append_child(bybit_json *parent, bybit_json *child)
{
    if (parent->last == NULL)
        parent->child = child;
    else
        parent->last->next = child;
    parent->last = child;
    parent->nchild++;
    return 0;
}

static bybit_json *parse_container(parser *p, int is_object)
{
    size_t start = p->i;
    bybit_json *node;
    char open = is_object ? '{' : '[';
    char close = is_object ? '}' : ']';

    if (p->depth >= 64) {
        fail(p, "json nesting limit");
        return NULL;
    }
    if (p->i >= p->n || p->s[p->i] != open) {
        fail(p, "expected container");
        return NULL;
    }
    node = make_node(p, is_object ? BYBIT_JSON_OBJECT : BYBIT_JSON_ARRAY, start);
    if (node == NULL)
        return NULL;
    p->i++;
    p->depth++;
    skip_ws(p);
    if (p->i < p->n && p->s[p->i] == close) {
        p->i++;
        p->depth--;
        node->raw_len = p->i - start;
        node->raw = p->s + start;
        return node;
    }
    for (;;) {
        bybit_json *child;
        if (is_object) {
            char *key = parse_string(p);
            if (key == NULL) {
                p->depth--;
                return NULL;
            }
            skip_ws(p);
            if (p->i >= p->n || p->s[p->i] != ':') {
                fail(p, "expected colon");
                p->depth--;
                return NULL;
            }
            p->i++;
            child = parse_value(p);
            if (child == NULL) {
                p->depth--;
                return NULL;
            }
            child->key = key;
        } else {
            child = parse_value(p);
            if (child == NULL) {
                p->depth--;
                return NULL;
            }
        }
        append_child(node, child);
        skip_ws(p);
        if (p->i < p->n && p->s[p->i] == ',') {
            p->i++;
            skip_ws(p);
            continue;
        }
        if (p->i < p->n && p->s[p->i] == close) {
            p->i++;
            break;
        }
        fail(p, "expected comma or end of container");
        p->depth--;
        return NULL;
    }
    p->depth--;
    node->raw_len = p->i - start;
    node->raw = p->s + start;
    return node;
}

static bybit_json *parse_number(parser *p)
{
    size_t start = p->i;
    size_t i = p->i;
    bybit_json *node;

    if (i < p->n && p->s[i] == '-')
        i++;
    if (i >= p->n || !isdigit((unsigned char)p->s[i])) {
        fail(p, "invalid number");
        return NULL;
    }
    if (p->s[i] == '0') {
        i++;
        if (i < p->n && isdigit((unsigned char)p->s[i])) {
            fail(p, "leading zero");
            return NULL;
        }
    } else {
        while (i < p->n && isdigit((unsigned char)p->s[i]))
            i++;
    }
    if (i < p->n && p->s[i] == '.') {
        size_t frac;
        i++;
        frac = i;
        while (i < p->n && isdigit((unsigned char)p->s[i]))
            i++;
        if (frac == i) {
            fail(p, "invalid fraction");
            return NULL;
        }
    }
    if (i < p->n && (p->s[i] == 'e' || p->s[i] == 'E')) {
        size_t exp;
        i++;
        if (i < p->n && (p->s[i] == '+' || p->s[i] == '-'))
            i++;
        exp = i;
        while (i < p->n && isdigit((unsigned char)p->s[i]))
            i++;
        if (exp == i) {
            fail(p, "invalid exponent");
            return NULL;
        }
    }
    node = make_node(p, BYBIT_JSON_NUMBER, start);
    if (node == NULL)
        return NULL;
    node->str = arena_copy(p->doc, p->s + start, i - start);
    if (node->str == NULL) {
        fail(p, "out of memory");
        return NULL;
    }
    p->i = i;
    node->raw_len = p->i - start;
    node->raw = p->s + start;
    return node;
}

static bybit_json *parse_literal(parser *p, const char *lit, bybit_json_type type, const char *shown)
{
    size_t n = strlen(lit);
    size_t start = p->i;
    bybit_json *node;

    if (p->i + n > p->n || memcmp(p->s + p->i, lit, n) != 0) {
        fail(p, "invalid literal");
        return NULL;
    }
    node = make_node(p, type, start);
    if (node == NULL)
        return NULL;
    node->str = shown;
    p->i += n;
    node->raw_len = n;
    node->raw = p->s + start;
    return node;
}

static bybit_json *parse_value(parser *p)
{
    skip_ws(p);
    if (p->i >= p->n) {
        fail(p, "unexpected end");
        return NULL;
    }
    switch (p->s[p->i]) {
    case '{':
        return parse_container(p, 1);
    case '[':
        return parse_container(p, 0);
    case '"': {
        size_t start = p->i;
        bybit_json *node = make_node(p, BYBIT_JSON_STRING, start);
        char *s;
        if (node == NULL)
            return NULL;
        s = parse_string(p);
        if (s == NULL)
            return NULL;
        node->str = s;
        node->raw_len = p->i - start;
        node->raw = p->s + start;
        return node;
    }
    case 't':
        return parse_literal(p, "true", BYBIT_JSON_BOOL, "true");
    case 'f':
        return parse_literal(p, "false", BYBIT_JSON_BOOL, "false");
    case 'n':
        return parse_literal(p, "null", BYBIT_JSON_NULL, "null");
    default:
        if (p->s[p->i] == '-' || isdigit((unsigned char)p->s[p->i]))
            return parse_number(p);
        fail(p, "unexpected token");
        return NULL;
    }
}

bybit_json_doc *bybit_json_parse(const char *text, size_t len, const char **err)
{
    parser p;
    bybit_json_doc *doc;
    bybit_json *root;

    if (err != NULL)
        *err = NULL;
    if (text == NULL) {
        if (err != NULL)
            *err = "null input";
        return NULL;
    }
    doc = calloc(1, sizeof(*doc));
    if (doc == NULL) {
        if (err != NULL)
            *err = "out of memory";
        return NULL;
    }
    doc->source = malloc(len + 1);
    if (doc->source == NULL) {
        free(doc);
        if (err != NULL)
            *err = "out of memory";
        return NULL;
    }
    memcpy(doc->source, text, len);
    doc->source[len] = '\0';
    doc->source_len = len;
    memset(&p, 0, sizeof p);
    p.s = doc->source;
    p.n = len;
    p.doc = doc;
    root = parse_value(&p);
    skip_ws(&p);
    if (root == NULL || p.err != NULL || p.i != p.n) {
        if (err != NULL)
            *err = p.err != NULL ? p.err : "trailing data";
        bybit_json_doc_free(doc);
        return NULL;
    }
    doc->root = root;
    return doc;
}

void bybit_json_doc_free(bybit_json_doc *doc)
{
    bybit_chunk *chunk;
    if (doc == NULL)
        return;
    chunk = doc->chunks;
    while (chunk != NULL) {
        bybit_chunk *next = chunk->next;
        free(chunk);
        chunk = next;
    }
    free(doc->source);
    free(doc);
}

const bybit_json *bybit_json_root(const bybit_json_doc *doc)
{
    return doc == NULL ? NULL : doc->root;
}

bybit_json_type bybit_json_get_type(const bybit_json *value)
{
    return value == NULL ? BYBIT_JSON_NULL : value->type;
}

const char *bybit_json_key(const bybit_json *value)
{
    return value == NULL ? NULL : value->key;
}

const char *bybit_json_string(const bybit_json *value)
{
    return value == NULL ? NULL : value->str;
}

int bybit_json_bool(const bybit_json *value)
{
    return value != NULL && value->type == BYBIT_JSON_BOOL && value->str != NULL &&
           value->str[0] == 't';
}

const char *bybit_json_slice(const bybit_json *value, size_t *len)
{
    if (value == NULL || value->raw == NULL) {
        if (len != NULL)
            *len = 0;
        return NULL;
    }
    if (len != NULL)
        *len = value->raw_len;
    return value->raw;
}

size_t bybit_json_length(const bybit_json *value)
{
    if (value == NULL)
        return 0;
    if (value->type != BYBIT_JSON_ARRAY && value->type != BYBIT_JSON_OBJECT)
        return 0;
    return value->nchild;
}

const bybit_json *bybit_json_index(const bybit_json *value, size_t index)
{
    const bybit_json *child;
    size_t i;

    if (value == NULL)
        return NULL;
    child = value->child;
    for (i = 0; child != NULL && i < index; i++)
        child = child->next;
    return child;
}

const bybit_json *bybit_json_object_get(const bybit_json *object, const char *key)
{
    const bybit_json *child;

    if (object == NULL || key == NULL || object->type != BYBIT_JSON_OBJECT)
        return NULL;
    for (child = object->child; child != NULL; child = child->next) {
        if (child->key != NULL && strcmp(child->key, key) == 0)
            return child;
    }
    return NULL;
}

typedef enum writer_expect {
    EXP_VALUE = 0,
    EXP_KEY,
    EXP_END
} writer_expect;

struct bybit_json_writer {
    bybit_buf buf;
    writer_expect expect[65];
    int is_object[65];
    int need_comma[65];
    int depth;
    int root_done;
    bybit_err err;
};

static bybit_err writer_fail(bybit_json_writer *w, bybit_err err)
{
    if (w->err == BYBIT_OK)
        w->err = err;
    return w->err;
}

static int append_escaped(bybit_buf *buf, const char *s)
{
    const unsigned char *p;
    if (bybit_buf_append(buf, "\"", 1) != 0)
        return -1;
    if (s == NULL)
        s = "";
    for (p = (const unsigned char *)s; *p != 0; p++) {
        char esc[8];
        size_t n = 0;
        unsigned char c = *p;
        if (c == '"' || c == '\\') {
            esc[0] = '\\';
            esc[1] = (char)c;
            n = 2;
        } else if (c == '\b') {
            esc[0] = '\\';
            esc[1] = 'b';
            n = 2;
        } else if (c == '\f') {
            esc[0] = '\\';
            esc[1] = 'f';
            n = 2;
        } else if (c == '\n') {
            esc[0] = '\\';
            esc[1] = 'n';
            n = 2;
        } else if (c == '\r') {
            esc[0] = '\\';
            esc[1] = 'r';
            n = 2;
        } else if (c == '\t') {
            esc[0] = '\\';
            esc[1] = 't';
            n = 2;
        } else if (c < 0x20u) {
            n = (size_t)snprintf(esc, sizeof esc, "\\u%04x", c);
        } else {
            esc[0] = (char)c;
            n = 1;
        }
        if (bybit_buf_append(buf, esc, n) != 0)
            return -1;
    }
    return bybit_buf_append(buf, "\"", 1);
}

static bybit_err begin_value(bybit_json_writer *w)
{
    if (w == NULL)
        return BYBIT_ERR_PARAM;
    if (w->err != BYBIT_OK)
        return w->err;
    if (w->root_done && w->depth == 0)
        return writer_fail(w, BYBIT_ERR_STATE);
    if (w->depth > 0 && w->expect[w->depth] == EXP_KEY)
        return writer_fail(w, BYBIT_ERR_STATE);
    if (w->depth > 0 && w->need_comma[w->depth] &&
        bybit_buf_append(&w->buf, ",", 1) != 0)
        return writer_fail(w, BYBIT_ERR_NOMEM);
    return BYBIT_OK;
}

static void end_value(bybit_json_writer *w)
{
    if (w->depth == 0)
        w->root_done = 1;
    else {
        w->need_comma[w->depth] = 1;
        if (w->is_object[w->depth])
            w->expect[w->depth] = EXP_KEY;
    }
}

bybit_json_writer *bybit_json_writer_create(void)
{
    bybit_json_writer *w = calloc(1, sizeof(*w));
    if (w == NULL)
        return NULL;
    bybit_buf_init(&w->buf);
    w->expect[0] = EXP_VALUE;
    return w;
}

void bybit_json_writer_destroy(bybit_json_writer *writer)
{
    if (writer == NULL)
        return;
    bybit_buf_free(&writer->buf);
    free(writer);
}

bybit_err bybit_json_writer_status(const bybit_json_writer *writer)
{
    if (writer == NULL)
        return BYBIT_ERR_PARAM;
    return writer->err;
}

bybit_err bybit_json_writer_begin_object(bybit_json_writer *writer)
{
    bybit_err err = begin_value(writer);
    if (err != BYBIT_OK)
        return err;
    if (writer->depth >= 64)
        return writer_fail(writer, BYBIT_ERR_RANGE);
    if (bybit_buf_append(&writer->buf, "{", 1) != 0)
        return writer_fail(writer, BYBIT_ERR_NOMEM);
    writer->depth++;
    writer->is_object[writer->depth] = 1;
    writer->need_comma[writer->depth] = 0;
    writer->expect[writer->depth] = EXP_KEY;
    return BYBIT_OK;
}

bybit_err bybit_json_writer_begin_array(bybit_json_writer *writer)
{
    bybit_err err = begin_value(writer);
    if (err != BYBIT_OK)
        return err;
    if (writer->depth >= 64)
        return writer_fail(writer, BYBIT_ERR_RANGE);
    if (bybit_buf_append(&writer->buf, "[", 1) != 0)
        return writer_fail(writer, BYBIT_ERR_NOMEM);
    writer->depth++;
    writer->is_object[writer->depth] = 0;
    writer->need_comma[writer->depth] = 0;
    writer->expect[writer->depth] = EXP_VALUE;
    return BYBIT_OK;
}

static bybit_err end_container(bybit_json_writer *writer, int is_object)
{
    if (writer == NULL)
        return BYBIT_ERR_PARAM;
    if (writer->err != BYBIT_OK)
        return writer->err;
    if (writer->depth <= 0 || writer->is_object[writer->depth] != is_object)
        return writer_fail(writer, BYBIT_ERR_STATE);
    if (is_object && writer->expect[writer->depth] == EXP_VALUE)
        return writer_fail(writer, BYBIT_ERR_STATE);
    if (bybit_buf_append(&writer->buf, is_object ? "}" : "]", 1) != 0)
        return writer_fail(writer, BYBIT_ERR_NOMEM);
    writer->depth--;
    end_value(writer);
    return BYBIT_OK;
}

bybit_err bybit_json_writer_end_object(bybit_json_writer *writer)
{
    return end_container(writer, 1);
}

bybit_err bybit_json_writer_end_array(bybit_json_writer *writer)
{
    return end_container(writer, 0);
}

bybit_err bybit_json_writer_key(bybit_json_writer *writer, const char *key)
{
    if (writer == NULL || key == NULL)
        return BYBIT_ERR_PARAM;
    if (writer->err != BYBIT_OK)
        return writer->err;
    if (writer->depth <= 0 || !writer->is_object[writer->depth] ||
        writer->expect[writer->depth] != EXP_KEY)
        return writer_fail(writer, BYBIT_ERR_STATE);
    if (writer->need_comma[writer->depth] &&
        bybit_buf_append(&writer->buf, ",", 1) != 0)
        return writer_fail(writer, BYBIT_ERR_NOMEM);
    if (append_escaped(&writer->buf, key) != 0 ||
        bybit_buf_append(&writer->buf, ":", 1) != 0)
        return writer_fail(writer, BYBIT_ERR_NOMEM);
    writer->expect[writer->depth] = EXP_VALUE;
    writer->need_comma[writer->depth] = 0;
    return BYBIT_OK;
}

static bybit_err put_raw_text(bybit_json_writer *writer, const char *text)
{
    bybit_err err = begin_value(writer);
    if (err != BYBIT_OK)
        return err;
    if (bybit_buf_append_str(&writer->buf, text) != 0)
        return writer_fail(writer, BYBIT_ERR_NOMEM);
    end_value(writer);
    return BYBIT_OK;
}

bybit_err bybit_json_writer_string(bybit_json_writer *writer, const char *value)
{
    bybit_err err;
    if (writer == NULL)
        return BYBIT_ERR_PARAM;
    err = begin_value(writer);
    if (err != BYBIT_OK)
        return err;
    if (append_escaped(&writer->buf, value == NULL ? "" : value) != 0)
        return writer_fail(writer, BYBIT_ERR_NOMEM);
    end_value(writer);
    return BYBIT_OK;
}

static int is_json_number(const char *number)
{
    const char *s = number;
    if (s == NULL || *s == '\0')
        return 0;
    if (*s == '-')
        s++;
    if (!isdigit((unsigned char)*s))
        return 0;
    if (*s == '0') {
        s++;
    } else {
        while (isdigit((unsigned char)*s))
            s++;
    }
    if (*s == '.') {
        s++;
        if (!isdigit((unsigned char)*s))
            return 0;
        while (isdigit((unsigned char)*s))
            s++;
    }
    if (*s == 'e' || *s == 'E') {
        s++;
        if (*s == '+' || *s == '-')
            s++;
        if (!isdigit((unsigned char)*s))
            return 0;
        while (isdigit((unsigned char)*s))
            s++;
    }
    return *s == '\0';
}

bybit_err bybit_json_writer_number(bybit_json_writer *writer, const char *number)
{
    if (!is_json_number(number))
        return writer == NULL ? BYBIT_ERR_PARAM : writer_fail(writer, BYBIT_ERR_PARAM);
    return put_raw_text(writer, number);
}

bybit_err bybit_json_writer_bool(bybit_json_writer *writer, int value)
{
    return put_raw_text(writer, value ? "true" : "false");
}

bybit_err bybit_json_writer_null(bybit_json_writer *writer)
{
    return put_raw_text(writer, "null");
}

bybit_err bybit_json_writer_raw(bybit_json_writer *writer, const char *json)
{
    const char *err = NULL;
    bybit_json_doc *doc;
    if (writer == NULL || json == NULL || json[0] == '\0')
        return BYBIT_ERR_PARAM;
    doc = bybit_json_parse(json, strlen(json), &err);
    if (doc == NULL)
        return writer_fail(writer, BYBIT_ERR_JSON);
    bybit_json_doc_free(doc);
    return put_raw_text(writer, json);
}

char *bybit_json_writer_finish(bybit_json_writer *writer)
{
    char *out;
    if (writer == NULL || writer->err != BYBIT_OK || writer->depth != 0 || !writer->root_done)
        return NULL;
    out = bybit_buf_detach(&writer->buf);
    if (out == NULL)
        writer->err = BYBIT_ERR_NOMEM;
    return out;
}

bybit_err bybit_json_object_from_kv(const bybit_kv *fields, size_t nfields, char **out)
{
    bybit_json_writer *w;
    size_t i;
    char *json;

    if (out == NULL)
        return BYBIT_ERR_PARAM;
    *out = NULL;
    if (nfields > 0 && fields == NULL)
        return BYBIT_ERR_PARAM;
    w = bybit_json_writer_create();
    if (w == NULL)
        return BYBIT_ERR_NOMEM;
    if (bybit_json_writer_begin_object(w) != BYBIT_OK) {
        bybit_err err = bybit_json_writer_status(w);
        bybit_json_writer_destroy(w);
        return err;
    }
    for (i = 0; i < nfields; i++) {
        bybit_err err;
        if (fields[i].key == NULL || fields[i].value == NULL)
            continue;
        err = bybit_json_writer_key(w, fields[i].key);
        if (err != BYBIT_OK) {
            bybit_json_writer_destroy(w);
            return err;
        }
        if (fields[i].raw)
            err = bybit_json_writer_raw(w, fields[i].value);
        else
            err = bybit_json_writer_string(w, fields[i].value);
        if (err != BYBIT_OK) {
            bybit_json_writer_destroy(w);
            return err;
        }
    }
    if (bybit_json_writer_end_object(w) != BYBIT_OK) {
        bybit_err err = bybit_json_writer_status(w);
        bybit_json_writer_destroy(w);
        return err;
    }
    json = bybit_json_writer_finish(w);
    if (json == NULL) {
        bybit_err err = bybit_json_writer_status(w);
        bybit_json_writer_destroy(w);
        return err == BYBIT_OK ? BYBIT_ERR_JSON : err;
    }
    bybit_json_writer_destroy(w);
    *out = json;
    return BYBIT_OK;
}
