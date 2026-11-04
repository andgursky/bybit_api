#ifndef BYBIT_JSON_H
#define BYBIT_JSON_H

#include "bybit/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum bybit_json_type {
    BYBIT_JSON_NULL = 0,
    BYBIT_JSON_BOOL,
    BYBIT_JSON_NUMBER,
    BYBIT_JSON_STRING,
    BYBIT_JSON_ARRAY,
    BYBIT_JSON_OBJECT
} bybit_json_type;

typedef struct bybit_json bybit_json;
typedef struct bybit_json_doc bybit_json_doc;

/*
 * Parse one JSON value. On failure returns NULL and, if err is not NULL,
 * stores a pointer to a static message.
 * Numbers are kept as their original text. Object lookup is the first match.
 */
bybit_json_doc *bybit_json_parse(const char *text, size_t len, const char **err);
void bybit_json_doc_free(bybit_json_doc *doc);
const bybit_json *bybit_json_root(const bybit_json_doc *doc);

bybit_json_type bybit_json_get_type(const bybit_json *value);
const char *bybit_json_key(const bybit_json *value);
/* Decoded string, number text, "true", "false", or "null". */
const char *bybit_json_string(const bybit_json *value);
int bybit_json_bool(const bybit_json *value);
/* Slice of the original document covering this value. Not NUL-terminated. */
const char *bybit_json_slice(const bybit_json *value, size_t *len);
size_t bybit_json_length(const bybit_json *value);
const bybit_json *bybit_json_index(const bybit_json *value, size_t index);
const bybit_json *bybit_json_object_get(const bybit_json *object, const char *key);

typedef struct bybit_json_writer bybit_json_writer;

bybit_json_writer *bybit_json_writer_create(void);
void bybit_json_writer_destroy(bybit_json_writer *writer);
bybit_err bybit_json_writer_status(const bybit_json_writer *writer);
bybit_err bybit_json_writer_begin_object(bybit_json_writer *writer);
bybit_err bybit_json_writer_end_object(bybit_json_writer *writer);
bybit_err bybit_json_writer_begin_array(bybit_json_writer *writer);
bybit_err bybit_json_writer_end_array(bybit_json_writer *writer);
bybit_err bybit_json_writer_key(bybit_json_writer *writer, const char *key);
bybit_err bybit_json_writer_string(bybit_json_writer *writer, const char *value);
bybit_err bybit_json_writer_number(bybit_json_writer *writer, const char *number);
bybit_err bybit_json_writer_bool(bybit_json_writer *writer, int value);
bybit_err bybit_json_writer_null(bybit_json_writer *writer);
/* Insert one already-encoded JSON value without changing its bytes. */
bybit_err bybit_json_writer_raw(bybit_json_writer *writer, const char *json);
char *bybit_json_writer_finish(bybit_json_writer *writer);

/* Flat object. NULL values are skipped. Returns a malloc'd JSON string. */
bybit_err bybit_json_object_from_kv(const bybit_kv *fields, size_t nfields, char **out);

#ifdef __cplusplus
}
#endif

#endif /* BYBIT_JSON_H */
