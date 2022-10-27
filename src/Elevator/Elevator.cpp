#include "Elevator.h"
#include <Arduino.h>

Elevator::Elevator(HCSR04 sensor){

}

Elevator::~Elevator() {
    delete[] this;
}