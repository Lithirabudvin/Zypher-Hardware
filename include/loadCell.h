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
    
    // Calibration factor - you'll need to calibrate this value
    // This is just an example value, you should calibrate it for your specific setup
    scale.set_scale(2280.f);  // Adjust this value based on your calibration
    scale.tare();  // Reset the scale to 0
    
    Serial.println("Load cell initialized");
}

float readCompostLevel() {
    // Generate random value between 0 and 100 for testing
    float compostLevel = random(0, 101);
    
    Serial.print("Test Compost Level: ");
    Serial.print(compostLevel);
    Serial.println(" %");
    
    return compostLevel;
}

#endif 