#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN  14       // GPIO connected to the DHT sensor
#define DHT_TYPE DHT22    // Change to DHT11 if using DHT11 sensor

DHT dht(DHT_PIN, DHT_TYPE);

void setupSensor() {
    dht.begin();
}

float readTemperature() {
    float temp = dht.readTemperature();
    if (isnan(temp)) {
        Serial.println("Failed to read temperature!");
        return -1;
    }
    return temp;
}

float readHumidity() {
    float hum = dht.readHumidity();
    if (isnan(hum)) {
        Serial.println("Failed to read humidity!");
        return -1;
    }
    return hum;
}

#endif
