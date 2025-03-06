#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <Arduino.h>

const int LED_PIN = 5;
const int PWM_CHANNEL = 0;
const int PWM_FREQ = 5000;
const int PWM_RESOLUTION = 8;

void setupLED() {
    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
    ledcAttachPin(LED_PIN, PWM_CHANNEL);
}

void setLEDBrightness(int brightness) {
    if (brightness >= 0 && brightness <= 255) {
        ledcWrite(PWM_CHANNEL, brightness);
        Serial.print("Brightness Set to: ");
        Serial.println(brightness);
    }
}

#endif
