#include "wifi_scan.h"
#include <WiFi.h>

void WiFiScanTask(void *parameter) {
  while (true) {
    int networksFound = WiFi.scanNetworks();
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(20, 30);
    M5.Lcd.print("Wi-Fi Networks:\n");

    for (int i = 0; i < networksFound; i++) {
      M5.Lcd.printf("SSID: %s\n", WiFi.SSID(i).c_str());
      M5.Lcd.printf("Signal Strength: %d\n", WiFi.RSSI(i));
    }
    vTaskDelay(10000 / portTICK_PERIOD_MS);  // 10 saniye bekle
  }
}
