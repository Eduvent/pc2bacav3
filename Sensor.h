#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
  // Pure virtual methods - must be implemented by derived classes
  virtual void begin() = 0;        // Initialize sensor hardware
  virtual bool isTriggered() = 0;  // Check if sensor threshold exceeded
  virtual float getReading() = 0;  // Get raw sensor value
};

#endif