#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <Arduino.h>  // Include Arduino core library for pinMode and analogWrite

#define LED_PIN 23  // GPIO pin for the LED

void setupLED() {
    pinMode(LED_PIN, OUTPUT);  // Set LED pin as an output
}

void setLEDBrightness(int brightness) {
    analogWrite(LED_PIN, brightness);  // Set the brightness using PWM
}





#endif