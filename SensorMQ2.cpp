#include "SensorMQ2.h"
#include <Arduino.h>

// Constructor - sets pin and threshold
SensorMQ2::SensorMQ2(int pin, float threshold)
  : analogPin(pin), threshold(threshold) {
}

// Initialize sensor pin and display configuration
void SensorMQ2::begin() {
  pinMode(analogPin, INPUT);
  Serial.print("MQ-2 Gas Sensor initialized on pin ");
  Serial.println(analogPin);
  Serial.print("Detection threshold: ");
  Serial.println(threshold);
}

// Check if current reading exceeds threshold
bool SensorMQ2::isTriggered() {
  int value = analogRead(analogPin);
  return value > threshold;
}

// Get raw analog reading from sensor
float SensorMQ2::getReading() {
  return analogRead(analogPin);
}