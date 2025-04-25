#include <Arduino.h>
#include "connectWiFi.h"
#include "firebaseHandler.h"
#include "ledControl.h"
#include "moistDevice.h"
#include "dhtsensor.h"
#include "sendData.h"
#include "lightsensor.h"
#include "loadCell.h"
#include "deviceConfig.h"
#include "deviceRegistration.h"
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
    Serial.begin(115200);
    connectToWiFi();  // Connect to Wi-Fi
    initializeFirebase();  // Initialize Firebase
    
    // Register device in Firebase
    registerDevice();
    
    // Setup devices
    setupLED();  // Setup LED control
    setupMoistDevice();
    setupLightSensor();  // Setup light sensor
    setupSensor();  // Setup temperature and humidity sensor
    setupLoadCell();  // Setup load cell sensor
    
    // Initialize LCD
    lcd.init();                      
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Device: ");
    lcd.print(DEVICE_ID);
    lcd.setCursor(0, 1);
    lcd.print("Initialized");  
    
    Serial.print("Device ");
    Serial.print(DEVICE_ID);
    Serial.println(" initialized");
}

void loop() {
    // Stream data from Firebase using WebSocket
    streamFirebaseData(); 

    // Read real sensor data
    float temperature = readTemperature();
    float humidity = readHumidity();
    float light = readLightIntensity();
    float compostLevel = readCompostLevel();  // Read compost level from load cell

    // Send sensor data to Firebase
    sendSensorData(temperature, humidity, light); 
    sendCompostLevelData(compostLevel);

    // Display temperature and humidity on the first line of the LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");

    // Display humidity and compost level on the second line of the LCD
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(humidity);
    lcd.print(" %");
    lcd.print(" Cmp:");
    lcd.print(compostLevel);
    lcd.print("%");

    delay(5000);  // Wait for 5 seconds before sending new data
}