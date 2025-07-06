#ifndef LOADCELL_H
#define LOADCELL_H

#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
#define LOADCELL_DOUT_PIN 16
#define LOADCELL_SCK_PIN 17

HX711 scale;

void setupLoadCell() {
    Serial.println("Initializing load cell...");
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(2280.f);
    scale.tare();
    Serial.println("Load cell initialized");
}

float readCompostLevel() {
    // Read the raw value from the load cell
    float rawReading = scale.get_units(10);  // Average of 10 readings
    
    // Convert the raw reading to a percentage
    float maxWeight = 1000.0;  // Adjust this value based on your setup
    float compostLevel = (rawReading / maxWeight) * 100.0;
    
    // Ensure the value is between 0 and 100
    compostLevel = constrain(compostLevel, 0.0, 100.0);
    
    Serial.print("Raw reading: ");
    Serial.print(rawReading);
    Serial.print(" g, Compost level: ");
    Serial.print(compostLevel);
    Serial.println(" %");
    
    return compostLevel;
}

#endif 