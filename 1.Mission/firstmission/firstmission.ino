#include "PWM_IN.h"


void setup() {
  
  Serial.begin(9600);
}

void loop() {
 
 pulseIn(Elevator,HIGH);
  
TUYGUN_HandleTypeDef Elevator;

 Serial.println(Elevator.TUYGUN_Elevator);
}