#include "internal.h"

#include <stdlib.h>
#include <string.h>

extern const bybit_endpoint bybit_endpoint_table[];
extern const size_t bybit_endpoint_table_count;

size_t bybit_endpoint_count(void)
{
    return bybit_endpoint_table_count;
}

const bybit_endpoint *bybit_endpoint_at(size_t index)
{
    if (index >= bybit_endpoint_table_count)
        return NULL;
    return &bybit_endpoint_table[index];
}

const bybit_endpoint *bybit_endpoint_find(const char *method, const char *path)
{
    size_t i;
    if (method == NULL || path == NULL)
        return NULL;
    for (i = 0; i < bybit_endpoint_table_count; i++) {
        if (strcmp(bybit_endpoint_table[i].method, method) == 0 &&
            strcmp(bybit_endpoint_table[i].path, path) == 0)
            return &bybit_endpoint_table[i];
    }
    return NULL;
}

bybit_err bybit_endpoint_invoke(bybit_client *client,
                                const bybit_endpoint *endpoint,
                                const bybit_kv *fields,
                                size_t nfields,
                                bybit_response **out)
{
    int is_get;
    char *json = NULL;
    bybit_err err;

    if (client == NULL || endpoint == NULL || endpoint->method == NULL || endpoint->path == NULL)
        return BYBIT_ERR_PARAM;
    is_get = strcmp(endpoint->method, "GET") == 0;
    if (is_get)
        return bybit_rest(client, endpoint->method, endpoint->path, endpoint->auth_required,
                          fields, nfields, NULL, out);
    err = bybit_json_object_from_kv(fields, nfields, &json);
    if (err != BYBIT_OK)
        return err;
    err = bybit_rest(client, endpoint->method, endpoint->path, endpoint->auth_required,
                     NULL, 0, json, out);
    free(json);
    return err;
}
