#include <Arduino.h>
#include "connectWiFi.h"
#include "firebaseHandler.h"
#include "ledControl.h"
#include "moistDevice.h"
#include "sensorHandler.h"
#include "sendData.h" // New file for sending data

void setup() {
    Serial.begin(115200);
    connectToWiFi();
    initializeFirebase();
    setupLED();
    setupMoistDevice();
    setupSensor();
}

void loop() {
    int brightness = getBrightness();
    if (brightness != -1) {
        setLEDBrightness(brightness);
    }

    int mistState = getMistState();
    if (mistState != -1) {
        controlMoistDevice(mistState);
    }

    float temperature = readTemperature();
    float humidity = readHumidity();
    sendSensorData(temperature, humidity); // Call function from sendData.h

    delay(5000); // Update every 5 seconds
}
