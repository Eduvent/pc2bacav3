#ifndef SENSOR_MQ2_H
#define SENSOR_MQ2_H

#include "Sensor.h"

class SensorMQ2 : public Sensor {
private:
  int analogPin;      // Analog input pin number
  float threshold;    // Detection threshold value

public:
  // Constructor with default threshold
  SensorMQ2(int pin, float threshold = 600.0);
  
  // Inherited virtual methods implementation
  void begin() override;
  bool isTriggered() override;
  float getReading() override;
};

#endif