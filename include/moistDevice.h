#ifndef MOISTDEVICE_H
#define MOISTDEVICE_H

#include <Arduino.h>

const int MIST_PIN = 4; // GPIO pin for mist device

void setupMoistDevice() {
    pinMode(MIST_PIN, OUTPUT);
    digitalWrite(MIST_PIN, LOW); // Ensure device is OFF at startup
}

void controlMoistDevice(int state) {
    if (state == 1) {
        digitalWrite(MIST_PIN, HIGH);
        Serial.println("Mist Device: ON");
    } else {
        digitalWrite(MIST_PIN, LOW);
        Serial.println("Mist Device: OFF");
    }
}

#endif
