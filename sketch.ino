#include "Device.h"
#include "SensorMQ2.h"
#include "LedActuator.h"
#include "EventHandler.h"
#include "CommandHandler.h"

// Pin configuration constants
#define MQ2_PIN 36  // VP pin - Analog input for MQ-2 sensor
#define LED_PIN 15  // Digital output pin for LED actuator

// Create sensor and actuator instances
SensorMQ2 mq2Sensor(MQ2_PIN);
LedActuator ledActuator(LED_PIN);
EventHandler eventHandler;
CommandHandler commandHandler;

// Create main device instance
Device smokeDetectorDevice(&mq2Sensor, &ledActuator, &eventHandler, &commandHandler);

/*
 * Arduino setup function - runs once at startup
 * Initializes the smoke detector device
 */
void setup() {
  Serial.begin(115200);  
  // Initialize the device with all components
  smokeDetectorDevice.initialize();
}

/*
 * Arduino main loop function - runs continuously
 * Updates device state and processes sensor readings every 2 seconds
 */
void loop() {
  // Update device state and handle sensor data
  smokeDetectorDevice.update();
  
  // Wait 2 seconds before next reading
  delay(2000);
}
