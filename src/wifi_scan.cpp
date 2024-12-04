#include <M5StickCPlus.h>
#include <WiFi.h>

// Wi-Fi ağlarını tarama işlemi
void scanWiFi() {
    int n = WiFi.scanNetworks();  // Çevredeki ağları tarar
    if (n == 0) {
        M5.Lcd.println("No networks found");
    } else {
        M5.Lcd.println("Wi-Fi Networks Found:");
        for (int i = 0; i < n; i++) {
            M5.Lcd.print(i + 1);
            M5.Lcd.print(": ");
            M5.Lcd.print(WiFi.SSID(i));  // Ağ adı
            M5.Lcd.print(" (");
            M5.Lcd.print(WiFi.RSSI(i));  // Sinyal gücü
            M5.Lcd.println(" dBm)");
        }
    }
}

void setup() {
    M5.begin();  // M5StickC'yi başlat
    M5.Lcd.setTextSize(2);
    M5.Lcd.print("Scanning Wi-Fi networks...\n");

    WiFi.mode(WIFI_STA);  // ESP32'yi istasyon (client) moduna alır
    WiFi.disconnect();    // Önceden bağlanmışsa bağlantıyı kes

    delay(1000);  // Biraz bekle
    scanWiFi();  // Wi-Fi tarama işlemini başlat
}

void loop() {
    // Ana döngüde herhangi bir işlem yapılmaz
}
