#include "ProximitySensor.h"

ProximitySensor::ProximitySensor(int Echo, int Trigger){
  echoPin = Echo;
  triggerPin = Trigger;
}

ProximitySensor::getDistance(){
  /*
  int Distance_test()   
  digitalWrite(triggerPin, LOW);   
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);  
  delayMicroseconds(20);
  digitalWrite(triggerPin, LOW);   
  float Fdistance = pulseIn(echoPin, HIGH);  
  Fdistance= Fdistance/58;       
  return (int)Fdistance;
  */
  return 0;
    
}