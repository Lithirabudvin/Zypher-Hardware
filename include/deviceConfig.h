#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

#include <Arduino.h>
#include <FirebaseESP32.h>

// Hardcoded device ID - Change this for each ESP device
// For the first ESP device, use "esp1"
// For the second ESP device, use "esp2"
#define DEVICE_ID "egg-1234"

// Function to get the device path in Firebase
String getDevicePath() {
    String path = String("devices/");
    path += DEVICE_ID;
    return path;
}

// Function to get the config path in Firebase
String getConfigPath() {
    String path = getDevicePath();
    path += String("/config");
    return path;
}

// Function to get the sensor data path in Firebase
String getSensorDataPath() {
    String path = getDevicePath();
    path += String("/sensor_data");
    return path;
}

#endif // DEVICE_CONFIG_H 