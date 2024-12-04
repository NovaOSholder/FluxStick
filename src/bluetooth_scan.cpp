#include "bluetooth_scan.h"
#include <BluetoothSerial.h>

BluetoothSerial BTSerial;

void BluetoothScanTask(void *parameter) {
  while (true) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setCursor(20, 30);
    M5.Lcd.print("Scanning Bluetooth devices...\n");

    int devicesFound = BTSerial.scan();
    for (int i = 0; i < devicesFound; i++) {
      M5.Lcd.printf("Device %d: %s\n", i + 1, BTSerial.deviceName(i).c_str());
    }

    vTaskDelay(5000 / portTICK_PERIOD_MS);  // 5 saniye bekle
  }
}
