#ifndef FIREBASEHANDLER_H
#define FIREBASEHANDLER_H

#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://superbsf-default-rtdb.firebaseio.com"  // Replace with your Firebase Database URL
#define FIREBASE_AUTH "c351DndiRORfNozcY8vYfORz7IDO76AjD0cBrS0E"          // Replace with your Firebase Database Secret

FirebaseData fbData;
FirebaseAuth auth;
FirebaseConfig config;

void initializeFirebase() {
    config.host = FIREBASE_HOST;
    config.signer.tokens.legacy_token = FIREBASE_AUTH;
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
}

int getBrightness() {
    if (Firebase.getInt(fbData, "/IOT2/brightness")) {
        if (fbData.dataType() == "int") {
            return fbData.intData();
        }
    } else {
        Serial.print("Firebase Error: ");
        Serial.println(fbData.errorReason());
    }
    return -1; // Return -1 if data retrieval fails
}

#endif

int getMistState() {
    if (Firebase.getInt(fbData, "/IOT2/mist")) {
        if (fbData.dataType() == "int") {
            return fbData.intData();
        }
    } else {
        Serial.print("Firebase Error: ");
        Serial.println(fbData.errorReason());
    }
    return -1; // Error retrieving data
}