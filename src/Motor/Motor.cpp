#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int ENA_PIN, int ENB_PIN, int IN_PIN, int ABS_V){
    ENA = ENA_PIN;
    ENB = ENB_PIN;
    IN = IN_PIN;
    ABS = ABS_V;
}

Motor::~Motor(){
    delete[] this;
}

void Motor::sendLow(){
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(IN, LOW);
}

void Motor::sendHigh(){
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(IN, HIGH);
}