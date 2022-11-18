#include "esp_log.h"
#include <esp_http_server.h>
#include <stdio.h>
#include "http_content.h"

static const char* TAG = "HTTP";
static httpd_handle_t server = NULL;

#define HTTP_GET_ROUTE(url, callback, ctx) \
    {                                      \
        .uri = url,                        \
        .method = HTTP_GET,                \
        .handler = callback,               \
        .user_ctx = (void*)ctx             \
    }
#define HTTP_POST_ROUTE(url, callback, ctx) \
    {                                      \
        .uri = url,                        \
        .method = HTTP_POST,                \
        .handler = callback,               \
        .user_ctx = (void*)ctx             \
    }

/* An HTTP GET handler */
static esp_err_t root_get_handler(httpd_req_t* req)
{
    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, (char*)INDEX, INDEX_SIZE);

    return ESP_OK;
}

static esp_err_t query_get_handler(httpd_req_t* req)
{
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, (char*)COMMAND, COMMAND_SIZE);
    return ESP_OK;
}

static const httpd_uri_t root = HTTP_GET_ROUTE("/", root_get_handler, 0);
static const httpd_uri_t query_test = HTTP_GET_ROUTE("/cgi-bin/luci/api/xqsystem/token", query_get_handler, 0);
static const httpd_uri_t query = HTTP_POST_ROUTE("/cgi-bin/luci/api/xqsystem/token", query_get_handler, 0);

void http_init()
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.lru_purge_enable = true;
    config.max_uri_handlers = 5;

    if (httpd_start(&server, &config) == ESP_OK) {
        // Set URI handlers
        ESP_LOGI(TAG, "Registering URI handlers");
        httpd_register_uri_handler(server, &root);
        httpd_register_uri_handler(server, &query);
        httpd_register_uri_handler(server, &query_test);
    }
}

void http_deinit()
{
    httpd_stop(server);
}
