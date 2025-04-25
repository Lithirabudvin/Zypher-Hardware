#ifndef DEVICE_REGISTRATION_H
#define DEVICE_REGISTRATION_H

#include <Arduino.h>
#include <FirebaseESP32.h>
#include "deviceConfig.h"

extern FirebaseData fbData;

// Register device in Firebase if not already registered
bool registerDevice() {
    String devicePath = getDevicePath();
    
    // Check if device already exists
    if (Firebase.getJSON(fbData, devicePath)) {
        Serial.println("Device already registered");
        return true;
    }
    
    // Create device entry
    FirebaseJson json;
    json.set("name", String("ESP Device ") + DEVICE_ID);
    json.set("createdAt", millis());
    
    // Create config entry
    FirebaseJson configJson;
    configJson.set("brightness", 50);
    configJson.set("moist_device", false);
    configJson.set("compost_state", false);
    json.set("config", configJson);
    
    // Create sensor_data entry
    FirebaseJson sensorDataJson;
    sensorDataJson.set("temperature", 0);
    sensorDataJson.set("humidity", 0);
    sensorDataJson.set("light", 0);
    sensorDataJson.set("compose_level", 0);
    sensorDataJson.set("createdAt", millis());
    json.set("sensor_data", sensorDataJson);
    
    // Set device data
    if (Firebase.setJSON(fbData, devicePath, json)) {
        Serial.println("Device registered successfully");
        return true;
    } else {
        String errorMsg = String("Failed to register device: ");
        errorMsg += fbData.errorReason();
        Serial.println(errorMsg);
        return false;
    }
}

#endif // DEVICE_REGISTRATION_H 