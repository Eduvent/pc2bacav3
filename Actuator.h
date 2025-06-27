#ifndef ACTUATOR_H
#define ACTUATOR_H

class Actuator {
public:
  // Pure virtual methods - must be implemented by derived classes
  virtual void begin() = 0;      // Initialize actuator hardware
  virtual void activate() = 0;   // Turn on/activate actuator
  virtual void deactivate() = 0; // Turn off/deactivate actuator
};

#endif