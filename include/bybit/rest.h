#ifndef BYBIT_REST_H
#define BYBIT_REST_H

#include "bybit/types.h"

#ifdef __cplusplus
extern "C" {
#endif

bybit_client *bybit_client_create(const bybit_config *config);
void bybit_client_destroy(bybit_client *client);

const char *bybit_client_rest_url(const bybit_client *client);
const char *bybit_client_ws_host(const bybit_client *client);
const char *bybit_client_last_error(const bybit_client *client);

/* server_time - local_time, milliseconds. Applied to later signatures. */
int64_t bybit_client_time_offset(const bybit_client *client);
bybit_err bybit_client_set_time_offset(bybit_client *client, int64_t offset_ms);
/* GET /v5/market/time and store the midpoint offset. */
bybit_err bybit_client_sync_time(bybit_client *client);

/*
 * Issue one REST call.
 * authenticated != 0 requires an API key and signs the request.
 * Public calls are not signed.
 * GET uses fields as the query. Any other method sends fields ignored and body as-is
 * (body NULL becomes an empty body).
 * On a completed HTTP response, *out is set even when the return is BYBIT_ERR_HTTP
 * or BYBIT_ERR_JSON. The caller frees it. *out is NULL when the call never completed.
 * A Bybit retCode other than 0 is still BYBIT_OK: read response->ret_code.
 */
bybit_err bybit_rest(bybit_client *client,
                     const char *method,
                     const char *path,
                     int authenticated,
                     const bybit_kv *query,
                     size_t nquery,
                     const char *body,
                     bybit_response **out);

/* Origin such as https://api.bybit.com. buf receives a NUL-terminated string. */
bybit_err bybit_build_rest_origin(bybit_env env, bybit_site site,
                                  char *buf, size_t buflen);

#ifdef __cplusplus
}
#endif

#endif /* BYBIT_REST_H */
