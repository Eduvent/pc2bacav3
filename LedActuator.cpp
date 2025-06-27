#include "LedActuator.h"
#include <Arduino.h>

// Constructor - sets pin number
LedActuator::LedActuator(int pin) : pin(pin) {
}

// Initialize LED pin as output and turn off initially
void LedActuator::begin() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  Serial.print("LED Actuator initialized on pin ");
  Serial.println(pin);
}

// Turn on LED for visual alert
void LedActuator::activate() {
  digitalWrite(pin, HIGH);
  Serial.println("*** LED ALERT ACTIVATED ***");
}

// Turn off LED when alert is cleared
void LedActuator::deactivate() {
  digitalWrite(pin, LOW);
  Serial.println("LED Alert deactivated");
}