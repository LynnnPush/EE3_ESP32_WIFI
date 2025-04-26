#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "wifi_handler.h"
#include "communication.h"
#include "config.h"

#define TAG "MAIN"

void app_main(void) {
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    
    ESP_LOGI(TAG, "ESP32 Wi-Fi Communication Example");
    
    // Initialize Wi-Fi
    ESP_LOGI(TAG, "Initializing Wi-Fi in station mode...");
    ret = wifi_init_sta();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize Wi-Fi: %s", esp_err_to_name(ret));
        return;
    }
    
    // Connect to Wi-Fi
    ESP_LOGI(TAG, "Connecting to Wi-Fi network %s...", WIFI_SSID);
    ret = wifi_connect();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to connect to Wi-Fi: %s", esp_err_to_name(ret));
        return;
    }
    
    // Wait a bit for network to stabilize
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    
    // Create the UDP communication task
    xTaskCreate(udp_task, "udp_task", 4096, NULL, 5, NULL);
    
    ESP_LOGI(TAG, "Application started successfully");
    
    // Main loop
    while (1) {
        // This is where you would add your main application logic
        
        // Example: Print a status message every 10 seconds
        ESP_LOGI(TAG, "System running...");
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
}