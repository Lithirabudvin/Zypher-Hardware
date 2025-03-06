#ifndef SENDDATA_H
#define SENDDATA_H

#include <FirebaseESP32.h>

extern FirebaseData fbData;

// Function to send Temperature & Humidity to Firebase
void sendSensorData(float temperature, float humidity) {
    if (temperature != -1) {
        if (Firebase.setFloat(fbData, "/IOT2/temperature", temperature)) {
            Serial.print("Temperature Sent: ");
            Serial.println(temperature);
        } else {
            Serial.print("Firebase Temp Error: ");
            Serial.println(fbData.errorReason());
        }
    }

    if (humidity != -1) {
        if (Firebase.setFloat(fbData, "/IOT2/humidity", humidity)) {
            Serial.print("Humidity Sent: ");
            Serial.println(humidity);
        } else {
            Serial.print("Firebase Humidity Error: ");
            Serial.println(fbData.errorReason());
        }
    }
}

#endif
