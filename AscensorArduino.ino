#include "src/HCSR04/HCSR04.h"
#include "src/logger/Logger.h"
#include "src/IRremote/IRremote.h"

#define UP 16736925
#define DOWN 16754775
#define L 16720605
#define R 16761405
#define STOP 16712445
#define UNKNOWN_UP 5316027
#define UNKNOWN_DOWN 2747854299
#define UNKNOWN_L 1386468383
#define UNKNOWN_R 553536955
#define UNKNOWN_STOP 3622325019

int RECV_PIN = 12;
decode_results results;
unsigned long val;

bool debug = false;
IRrecv irrecv(RECV_PIN);


HCSR04 sensor(A5, A4);
Logger logger(debug);

void setup() {
  Serial.begin(9600);
  logger.info("Conexion inizializada");
  irrecv.enableIRIn();  
}

void loop() {
  logger.debug("Distancia: "+ (String) sensor.dist());
  delay(1000);

  if (irrecv.decode(&results)){ 
    val = results.value;
    irrecv.resume();
    switch(val){
      case UP: 
      case UNKNOWN_UP: logger.info("UP");break;
      case DOWN: 
      case UNKNOWN_DOWN: logger.info("DOWN"); break;
      case L: 
      case UNKNOWN_L: logger.info("LEFT"); break;
      case R: 
      case UNKNOWN_R: logger.info("RIGHT");break;
      case STOP: 
      case UNKNOWN_STOP: logger.info("STOP"); break;
      default:break;
    }
  }   
}
