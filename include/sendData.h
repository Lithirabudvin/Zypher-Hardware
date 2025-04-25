#ifndef SENDDATA_H
#define SENDDATA_H

#include <FirebaseESP32.h>
#include "deviceConfig.h"

extern FirebaseData fbData;

// Function to send Temperature & Humidity data to Firebase
void sendSensorData(float temperature, float humidity, float light) {
    String sensorDataPath = getSensorDataPath();
    
    // Send temperature data
    if (temperature != -1) {
        String tempPath = sensorDataPath;
        tempPath += String("/temperature");
        if (Firebase.setFloat(fbData, tempPath, temperature)) {
            Serial.print("Temperature Sent: ");
            Serial.println(temperature);
        } else {
            String errorMsg = String("Firebase Temp Error: ");
            errorMsg += fbData.errorReason();
            Serial.println(errorMsg);
        }
    }

    // Send humidity data
    if (humidity != -1) {
        String humidityPath = sensorDataPath;
        humidityPath += String("/humidity");
        if (Firebase.setFloat(fbData, humidityPath, humidity)) {
            Serial.print("Humidity Sent: ");
            Serial.println(humidity);
        } else {
            String errorMsg = String("Firebase Humidity Error: ");
            errorMsg += fbData.errorReason();
            Serial.println(errorMsg);
        }
    }
    
    // Send light data
    if (light != -1) {
        String lightPath = sensorDataPath;
        lightPath += String("/light");
        if (Firebase.setFloat(fbData, lightPath, light)) {
            Serial.print("Light Sent: ");
            Serial.println(light);
        } else {
            String errorMsg = String("Firebase Light Error: ");
            errorMsg += fbData.errorReason();
            Serial.println(errorMsg);
        }
    }
    
    // Update timestamp
    String timestampPath = sensorDataPath;
    timestampPath += String("/createdAt");
    if (Firebase.setInt(fbData, timestampPath, millis())) {
        Serial.println("Timestamp updated");
    } else {
        String errorMsg = String("Firebase Timestamp Error: ");
        errorMsg += fbData.errorReason();
        Serial.println(errorMsg);
    }
}

// Function to send compost level data to Firebase
void sendCompostLevelData(float compostLevel) {
    if (compostLevel != -1) {
        String sensorDataPath = getSensorDataPath();
        String compostPath = sensorDataPath;
        compostPath += String("/compose_level");
        
        if (Firebase.setFloat(fbData, compostPath, compostLevel)) {
            Serial.print("Compost Level Sent: ");
            Serial.println(compostLevel);
        } else {
            String errorMsg = String("Firebase Compost Level Error: ");
            errorMsg += fbData.errorReason();
            Serial.println(errorMsg);
        }
    }
}

#endif