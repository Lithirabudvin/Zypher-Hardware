#ifndef CONNECTWIFI_H
#define CONNECTWIFI_H

#include <WiFi.h>

#define WIFI_SSID "ABC"
#define WIFI_PASSWORD "zzom5037"

void connectToWiFi() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi!");
}

#endif