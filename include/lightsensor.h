#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <Arduino.h>
#include <Wire.h>
#include <BH1750.h>    // Include BH1750 library   


BH1750 lightMeter;

void setupLightSensor() {
    Wire.begin();
    lightMeter.begin(); 
}

float readLightIntensity() {
    float lux = lightMeter.readLightLevel(); // Read light level in lux
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lx");
    return lux;
}

#endif