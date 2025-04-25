#ifndef MOISTDEVICE_H
#define MOISTDEVICE_H

#include <Arduino.h>  // Include Arduino library for pinMode and digitalWrite
#define MIST_PIN 19  // GPIO pin for the mist-making device

void setupMoistDevice() {
    pinMode(MIST_PIN, OUTPUT);
    //digitalWrite(MIST_PIN, LOW);  // Set mist device pin as an output
}

void controlMoistDevice(int state) {
    if (state == 1) {
        digitalWrite(MIST_PIN, LOW);
        digitalWrite(MIST_PIN, HIGH);
           // Turn on the mist device
    } else {
        digitalWrite(MIST_PIN, HIGH);
        digitalWrite(MIST_PIN, LOW);
          // Turn off the mist device
    }
}

#endif