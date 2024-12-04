#include <M5StickCPlus.h>
#include <WiFi.h>
#include <BluetoothSerial.h>
#include <FreeRTOS.h>
#include "wifi_scan.h"
#include "bluetooth_scan.h"
#include "port_scan.h"
#include "password_cracking.h"
#include "utils.h"

// Wi-Fi ve Bluetooth başlatma
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
BluetoothSerial BTSerial;

void setup() {
  M5.begin();
  Serial.begin(115200);
  
  // Wi-Fi ve Bluetooth bağlantısı
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi connected");
  BTSerial.begin("M5StickC_Bluetooth");

  // FreeRTOS görevlerini başlat
  xTaskCreate(WiFiScanTask, "Wi-Fi Scan", 2048, NULL, 1, NULL);
  xTaskCreate(BluetoothScanTask, "Bluetooth Scan", 2048, NULL, 1, NULL);
  xTaskCreate(PortScanTask, "Port Scan", 2048, NULL, 1, NULL);
  xTaskCreate(PasswordCrackTask, "Password Cracking", 2048, NULL, 1, NULL);
}

void loop() {
  vTaskDelay(1000 / portTICK_PERIOD_MS);  // FreeRTOS görevleri çalışacak
}
