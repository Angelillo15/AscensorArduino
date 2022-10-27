#ifndef ProximitySensor_h
#define ProximitySensor_h

#include <HCSR04.h>
#include <Arduino.h>

class ProximitySensor {
  private: 
    int echoPin;
    int triggerPin;
  public:
    ProximitySensor(int Echo, int Trigger);
    int getDistance(); 
};

#endif