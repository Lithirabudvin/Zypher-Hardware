#ifndef FIREBASEHANDLER_H
#define FIREBASEHANDLER_H

#include <FirebaseESP32.h>
#include "ledControl.h"
#include "moistDevice.h"
#include "deviceConfig.h"

#define FIREBASE_HOST "https://superbsf-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "vc351DndiRORfNozcY8vYfORz7IDO76AjD0cBrS0E"

FirebaseData fbData;
FirebaseAuth auth;
FirebaseConfig config;

void initializeFirebase() {
    config.host = FIREBASE_HOST;
    config.signer.tokens.legacy_token = FIREBASE_AUTH;
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
    
    // Set the size of the HTTP response buffer
    fbData.setBSSLBufferSize(1024, 1024);
    
    // Set the size of the response buffer
    fbData.setResponseSize(2048);
    
    Serial.println("Firebase initialized");
}

// Function to stream data from Firebase using WebSocket
void streamFirebaseData() {
    String configPath = getConfigPath();
    
    // Get brightness
    String brightnessPath = configPath;
    brightnessPath += String("/brightness");
    if (Firebase.getInt(fbData, brightnessPath)) {
        if (fbData.dataType() == "int") {
            int brightness = fbData.intData();
            Serial.print("Brightness from Firebase: ");
            Serial.println(brightness);
            setLEDBrightness(brightness);
        }
    }
    
    // Get moist device state
    String moistPath = configPath;
    moistPath += String("/moist_device");
    if (Firebase.getInt(fbData, moistPath)) {
        if (fbData.dataType() == "int") {
            int moistState = fbData.intData();
            Serial.print("Moist Device State from Firebase: ");
            Serial.println(moistState);
            controlMoistDevice(moistState);
        }
    }
    
    // Get compost state
    String compostPath = configPath;
    compostPath += String("/compost_state");
    if (Firebase.getInt(fbData, compostPath)) {
        if (fbData.dataType() == "int") {
            int compostState = fbData.intData();
            Serial.print("Compost State from Firebase: ");
            Serial.println(compostState);
            // Assuming you have a function to control compost state
            // controlCompostState(compostState);
        }
    }
}

#endif