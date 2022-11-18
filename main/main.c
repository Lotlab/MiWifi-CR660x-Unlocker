#include <esp_log.h>
#include <nvs_flash.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "wifi.h"
#include "http.h"

static const char* TAG = "APP";

void app_main(void)
{
    ESP_LOGI(TAG, "Boot!");

    //Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    wifi_init_softap();

    http_init();

    ESP_LOGI(TAG, "Inited!");
}
