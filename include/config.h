#ifndef CONFIG_H
#define CONFIG_H

// Wi-Fi configuration
#define WIFI_SSID "LynnsHW"
#define WIFI_PASSWORD "HWlsh123!"
#define WIFI_CONNECT_RETRY_MAX 10

// Communication configuration
#define UDP_PORT 3333

// Device role configuration
// Set to 1 for device A, 0 for device B to distinguish between them
#define DEVICE_IS_SENDER 1

// Communication partner IP (update this with the IP of the other ESP32)
#define PARTNER_IP "192.168.43.137"

// Time intervals (in milliseconds)
#define SEND_INTERVAL_MS 2000
#define WIFI_RECONNECT_INTERVAL_MS 5000

#endif // CONFIG_H