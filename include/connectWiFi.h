#ifndef CONNECTWIFI_H
#define CONNECTWIFI_H

#include <WiFi.h>

#define WIFI_SSID "ABC"          // Replace with your Wi-Fi SSID
#define WIFI_PASSWORD "zzom5037"  // Replace with your Wi-Fi Password

void connectToWiFi() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("\nConnected to WiFi");
}

#endif
