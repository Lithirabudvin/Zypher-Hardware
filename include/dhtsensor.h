#ifndef DHTSENSOR_H
#define DHTSENSOR_H

#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN  4       // GPIO connected to the DHT sensor
#define DHT_TYPE DHT22    // Change to DHT11 if using DHT11 sensor
 // Midpoint voltage for ACS712 (VCC/2)

DHT dht(DHT_PIN, DHT_TYPE);

void setupSensor() {
    dht.begin();
}

float readTemperature() {
  float temperature = dht.readTemperature(); 
  if (isnan(temperature)) {
      Serial.println("Failed to read humidity!");
      return -1;
  }
  return temperature;
}

float readHumidity() {
    float humidity = dht.readHumidity();
    if (isnan(humidity)) {
        Serial.println("Failed to read humidity!");
        return -1;
    }
    return humidity;
}

#endif