#include "src/HCSR04/HCSR04.h"
#include "src/logger/Logger.h"

bool debug = true;

float distance[3];

HCSR04 sensor(A5, A4);
Logger logger(debug);

void setup() {
  Serial.begin(9600);
  logger.info("Conexion inizializada");
}

void loop() {
    logger.debug("Distancia: "+ (String) sensor.dist());
    delay(1000);   
}
