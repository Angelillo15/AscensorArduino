#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class Motor {
private:
    int ENA;
    int ENB;
    int IN;
    int ABS;
public:
    Motor(int ENA_PIN, int ENB_PIN, int IN_PIN, int ABS_V);
    ~Motor();
    void sendLow();
    void sendHigh();
};



#endif