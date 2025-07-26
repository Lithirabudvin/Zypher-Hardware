# Smart BSF Farming ESP Controller & Firebase Integration

This repository contains the source code for the **ESP-based controller** that manages BSF farming hardware components, collects environmental sensor data, and interacts with a Firebase backend via WebSocket for real-time monitoring and control.

---

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Hardware Integration](#hardware-integration)
- [Communication Architecture](#communication-architecture)
- [Repository Structure](#repository-structure)
- [Setup & Usage](#setup--usage)
- [Development & Contribution](#development--contribution)
- [Acknowledgements](#acknowledgements)

---

## Project Overview

This project implements firmware for an ESP microcontroller (ESP32/ESP8266) that serves as the central unit to:

- Control farming components such as moisture devices, lighting, temperature control.
- Gather real-time sensor data (temperature, humidity, light intensity, compost level).
- Communicate bidirectionally with a Firebase backend using WebSocket for instant control commands and sensor updates.
- Support integration with a mobile app for monitoring and control within the Smart BSF Farming ecosystem.

---

## Features

- **Real-time Sensor Data Acquisition:** Reads multiple environmental sensors connected to the ESP.
- **Reliable WebSocket Communication:** Maintains a persistent connection with Firebase for efficient data exchange.
- **Unit Identification:** Supports unique IDs for breeding and compost units for multi-unit management.
- **Robust Error Handling:** WiFi reconnection, WebSocket retries, and fallback mechanisms.
- **Extensible Firmware Architecture:** Modular code design for easy addition of new sensors or control functions.

---

## Hardware Integration

The ESP board interfaces with the following modules:

| Component           | Function                                   | Interface         |
|---------------------|--------------------------------------------|-------------------|
| Temperature Sensor   | Measures ambient/larvae environment temperature | Digital pin |
| Humidity Sensor      | Measures relative humidity                 | Digital I/O       |
| Light Sensor        | Monitors light intensity                    | Analog Input      |
| Moisture Control    | Controls humidity regulation device         | Digital I/O       |
| Lighting Control     | Adjusts brightness of LED lamps            | PWM output        |
| Compost Level Sensor | Detects current level of compost           | Analog            |


---

## Communication Architecture

- The ESP device connects to a WiFi network and establishes a WebSocket connection to a Firebase Realtime Database.
- Sensor data is pushed to Firebase in real-time enabling app dashboards to update instantly.
- Control commands from the mobile app are received via Firebase WebSocket and executed on the ESP to actuate devices.
- Unique unit IDs distinguish different physical units (breeding and compost units), allowing multi-unit deployment.

---

## Repository Structure
```
esp-controller/
├── include/
│ ├── connectWifi.h 
│ ├── deviceConfig.h 
│ ├── deviceRegistration.h 
│ ├── dhtsensor.h 
│ ├── firbaseHandler.h 
│ ├──  ledControl.h
│ ├──  lightsensor.h
│ ├──  loadCell.h
│ ├──  sendData.h
│ └──  testData.h
├── src/
│ └── main.cpp
├── platformio.ini # Project configuration
├── README.md # Project documentation
└── LICENSE # License file

---
```
## Setup & Usage

### Requirements

- ESP32 or ESP8266 development board
- Sensors and actuators as per hardware integration section
- WiFi network for internet connectivity
- Firebase project with Realtime Database configured
- Development environment: Arduino IDE, PlatformIO, or ESP-IDF

### Installation & Configuration

1. Clone this repository:
   
git clone https://github.com/lithirabudvin/zypher-hardware.git

2. Open the project in your IDE.
3. Edit `config.h` to update:
 - WiFi SSID and password
 - Firebase Realtime Database URL and secret/API key
 - Unique unit ID for this device
4. Connect the ESP hardware and load the firmware.
5. Monitor serial console for connection status and debug info.
6. Ensure the mobile app linked to the Firebase project can send/receive commands and data.

### Development Notes

- The WebSocket connection uses Firebase’s realtime database WebSocket endpoint.
- Sensor data update frequency and control polling intervals are configurable.
- Code is modular for straightforward extension and maintenance.

---

## Development & Contribution

Contributions and improvements are welcome! Please follow these guidelines:

- Use consistent code style.
- Document new sensors or features you add.
- Test changes thoroughly on real hardware.
- Open issues with bug reports or feature requests.
- Submit pull requests with descriptive messages.

---

## Acknowledgements

This project is part of the Smart BSF Farming ecosystem developed collaboratively by Team Zypher, complementing the mobile app and hardware units.

---


