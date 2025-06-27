#ifndef DEVICE_H
#define DEVICE_H

#include "Sensor.h"
#include "Actuator.h"
#include "EventHandler.h"
#include "CommandHandler.h"

class Device {
private:
  Sensor* sensor;              // Pointer to sensor instance
  Actuator* actuator;          // Pointer to actuator instance
  EventHandler* eventHandler;  // Pointer to event handler instance
  CommandHandler* commandHandler; // Pointer to command handler instance
  bool lastSmokeState;         // Previous smoke detection state

  // Private methods
  void connectToWiFi();        // Establishes WiFi connection
  void printDeveloperInfo();   // Shows company and developer information

public:
  // Constructor
  Device(Sensor* s, Actuator* a, EventHandler* e, CommandHandler* c);
  
  // Public methods
  void initialize();           // Initializes all device components
  void update();              // Main update loop for device operations
};

#endif