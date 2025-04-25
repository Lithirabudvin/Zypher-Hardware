#ifndef TEST_DATA_H
#define TEST_DATA_H

#include <Arduino.h>

// Function to generate a random temperature value (20-30°C)
float getRandomTemperature() {
    return 20.0 + (random(100) / 10.0);
}

// Function to generate a random humidity value (40-80%)
float getRandomHumidity() {
    return 40.0 + (random(40) / 10.0);
}

// Function to generate a random light value (500-1500 lux)
float getRandomLight() {
    return 500.0 + random(1000);
}

// Function to generate a random compost level value (30-80%)
float getRandomCompostLevel() {
    return 30.0 + random(50);
}

// Function to generate random test data
void generateRandomTestData(float& temperature, float& humidity, float& light, float& compostLevel) {
    temperature = getRandomTemperature();
    humidity = getRandomHumidity();
    light = getRandomLight();
    compostLevel = getRandomCompostLevel();
    
    Serial.println("Generated random test data:");
    Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
    Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
    Serial.print("Light: "); Serial.print(light); Serial.println(" lux");
    Serial.print("Compost Level: "); Serial.print(compostLevel); Serial.println(" %");
}

#endif // TEST_DATA_H 