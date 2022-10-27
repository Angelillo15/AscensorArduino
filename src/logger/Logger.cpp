#include "HardwareSerial.h"
#include "Logger.h"
#include <Arduino.h>

Logger::Logger(bool setDebug) {
  isDebug = setDebug;
}

Logger::Logger(){
  isDebug = false;
}

bool Logger::isInDebug(){
  return (bool) isDebug;
}

void Logger::debug(String message){
  if(isDebug) Serial.println("[DEBUG] "+message);
}

void Logger::info(String message){
  Serial.println("[Info] "+message);
}

void Logger::warn(String message){
  Serial.println("[Info] "+message);
}

void Logger::error(String message){
  Serial.println("[Info] "+message);
}