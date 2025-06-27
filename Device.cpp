#include "Device.h"
#include <Arduino.h>
#include <WiFi.h>

// Constructor - initializes device with component pointers
Device::Device(Sensor* s, Actuator* a, EventHandler* e, CommandHandler* c)
  : sensor(s), actuator(a), eventHandler(e), commandHandler(c), lastSmokeState(false) {
}

// Connects to WiFi network (Wokwi simulation network)
void Device::connectToWiFi() {
  const char* ssid = "Wokwi-GUEST";
  const char* password = "";

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  // Wait for connection with visual feedback
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("WiFi connected successfully!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

// Displays company and developer information at startup
void Device::printDeveloperInfo() {
  Serial.println("==============================================");
  Serial.println("  SafeHome Smoke Detector Smart Detection Unit");
  Serial.println("==============================================");
  Serial.println("Company: SafeHome Smoke Detector");
  Serial.println("Development Team: GreenWave Inc.");
  Serial.println("Developer: Victor Manuel Meneses Arevalo");
  Serial.println("Student ID: U202212191");
  Serial.println("Version: 1.0");
  Serial.println("Date: June 27, 2025");
  Serial.println("==============================================");
  Serial.println();
}

// Initializes all device components and establishes connections
void Device::initialize() {
  printDeveloperInfo();
  connectToWiFi();
  
  // Initialize sensor and actuator
  sensor->begin();
  actuator->begin();
  
  Serial.println("Device initialization completed!");
  Serial.println("Starting smoke detection monitoring...");
  Serial.println();
}

// Main update method - checks sensor and manages state changes
void Device::update() {
  bool smokeDetected = sensor->isTriggered();
  float sensorReading = sensor->getReading();
  
  // Display current sensor reading for monitoring
  Serial.print("Sensor Reading: ");
  Serial.print(sensorReading);
  Serial.print(" | Status: ");
  Serial.println(smokeDetected ? "SMOKE DETECTED" : "NORMAL");

  if (smokeDetected) {
    // Activate LED alert
    actuator->activate();
    
    // Only trigger events on state change (prevent spam)
    if (!lastSmokeState) {
      eventHandler->onSmokeDetected();
      commandHandler->sendAlert(true);
      lastSmokeState = true;
    }
  } else {
    // Deactivate LED alert
    actuator->deactivate();
    
    // Only trigger clear event on state change
    if (lastSmokeState) {
      eventHandler->onClear();
      commandHandler->sendAlert(false);
      lastSmokeState = false;
    }
  }
}