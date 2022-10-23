#ifndef ProximitySensor_h
#define ProximitySensor_h

#include <Arduino.h>

class ProximitySensor {
  private: 
    int sensorPin;
  public:
    ProximitySensor(int); 
};

#endif