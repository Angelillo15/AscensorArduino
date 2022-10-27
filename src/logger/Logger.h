#ifndef Logger_h
#define Logger_h

#include <Arduino.h>

class Logger {
  private: 
    bool isDebug;
  public:
    Logger(bool debug);
    Logger();
    bool isInDebug();
    void debug(String message);
    void info(String message);
    void warn(String message);
    void error(String message);
};

#endif