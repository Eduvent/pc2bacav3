#ifndef LED_ACTUATOR_H
#define LED_ACTUATOR_H

#include "Actuator.h"

class LedActuator : public Actuator {
private:
  int pin;  // Digital output pin number

public:
  // Constructor
  LedActuator(int pin);
  
  // Inherited virtual methods implementation
  void begin() override;
  void activate() override;
  void deactivate() override;
};

#endif
