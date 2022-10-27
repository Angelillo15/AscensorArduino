#ifndef Elevator_h
#define Elevator_h

#include <Arduino.h>

#include "../HCSR04/HCSR04.h"
#include "../Motor/Motor.h"


class Elevator {
private:
    /* data */
public:
    Elevator(HCSR04 sensor);
    ~Elevator();
};

#endif