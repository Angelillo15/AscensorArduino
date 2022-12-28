#include "src/HCSR04/HCSR04.h"
#include "src/logger/Logger.h"
#include "src/IRremote/IRremote.h"
#include <util/delay.h>

extern "C" {
  #include <os.h>
}

spinlock_t testLock;

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
void(* resetFunc) (void) = 0; //declare reset function @ address 0

int RECV_PIN = 12;
int distance = 6;
decode_results results;
unsigned long val;
int ENA=5; 
int IN1=6;
int IN2=7;
int ENB=11; 
int IN3=8;
int IN4=9;

bool stoping = false;
bool debug = true;
IRrecv irrecv(RECV_PIN);

HCSR04 sensor(A5, A4);
Logger logger(debug);

void setup() {
  Serial.begin(9600);
  logger.info("Conexion inizializada");
  irrecv.enableIRIn();  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  digitalWrite(ENA,HIGH);  
  digitalWrite(ENB,LOW);
 
  delay(10);
  os_init();
}

void move_down(void *arg){
  digitalWrite(IN1,HIGH);      
  digitalWrite(IN2,LOW);         
  digitalWrite(IN3,LOW);      
  digitalWrite(IN4,HIGH);   

  os_schedule_task(checkTask, NULL, 0);
  while (distance < 15)
  {
    digitalWrite(ENB, HIGH);
    

    os_sleep(10);

    digitalWrite(ENB, LOW);      

    os_sleep(30);
    if(stoping){
      stoping = !stoping;
      break;
    }
  }
  digitalWrite(ENB, LOW);
  resetFunc();
  os_exit_task();
}

void move_up(void *arg){
  digitalWrite(IN1, LOW);      
  digitalWrite(IN2, HIGH);         
  digitalWrite(IN3, HIGH);      
  digitalWrite(IN4, LOW);   
  
  os_schedule_task(checkTask, NULL, 0);
  while (distance > 4)
  {
    digitalWrite(ENB, HIGH);
    

    os_sleep(10);

    digitalWrite(ENB, LOW);      

    os_sleep(30);
    if(stoping){
      stoping = !stoping;
      break;
    }
  }
  digitalWrite(ENB, LOW);
  resetFunc();
  os_exit_task();

}


void irTask(void *arg){
  while (1) {
    distance = sensor.dist();
    logger.debug((String) distance);
    if (irrecv.decode(&results)){ 
    val = results.value;
    irrecv.resume();
    switch(val){
        case UP: 
        case UNKNOWN_UP: logger.info("UP");os_schedule_task(move_up, NULL, 0);break;
        case DOWN: 
        case UNKNOWN_DOWN: logger.info("DOWN"); os_schedule_task(move_down, NULL, 0);  break;
        case L: 
        case UNKNOWN_L: logger.info("LEFT");   os_schedule_task(checkTask, NULL, 0); break;
        case R: 
        case UNKNOWN_R: logger.info("RIGHT");break;
        case STOP: 
        case UNKNOWN_STOP: logger.info("STOP");stop(); break;
        default:logger.info((String)val);
      }
    }

    os_sleep(1000);
  } 
}


void checkTask(void *arg){
  while (true) {
    distance = sensor.dist();
    logger.debug((String) distance);
    os_sleep(500);
  }
}


void stop(){
  stoping = true;
}

void loop() {  
    spinlock_init(&testLock);
    os_schedule_task(irTask, NULL, 0);
    os_loop();
}


void testDistance(){
  for (size_t i = 0; i < 10; i++)
  {
    distance = sensor.dist();
    logger.debug((String) distance);
    delay(1000);
  }
  
  
}