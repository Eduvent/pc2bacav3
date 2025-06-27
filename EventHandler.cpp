#include "EventHandler.h"
#include <Arduino.h>

// Handle smoke detection event
void EventHandler::onSmokeDetected() {
  Serial.println("========================================");
  Serial.println("*** EMERGENCY ALERT: SMOKE DETECTED ***");
  Serial.println("========================================");
  Serial.println("Activating emergency protocols...");
  Serial.println("Visual alert: LED ON");
  Serial.println("Sending alert to remote monitoring...");
  Serial.println();
}

// Handle air quality clear event
void EventHandler::onClear() {
  Serial.println("=======================================");
  Serial.println("*** AIR QUALITY RESTORED TO NORMAL ***");
  Serial.println("=======================================");
  Serial.println("Emergency protocols deactivated");
  Serial.println("Visual alert: LED OFF");
  Serial.println("Sending clear status to remote monitoring...");
  Serial.println();
}
