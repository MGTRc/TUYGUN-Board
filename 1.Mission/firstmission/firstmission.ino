#include "PWM_IN.h"
#include "PWM_OUT.h"

TUYGUN_HandleTypeDef TUYGUN;
TUYGUN_HandleTypeDef1 TUYGUN1;
void setup() {
Serial.begin(9600);
}

void loop() {
  TUYGUN_PWM_Read(&TUYGUN);
  Serial.print("Throttle:");
  Serial.println(TUYGUN.PWM_In_Throttle);
  Serial.print("Aileron:");
  Serial.println(TUYGUN.PWM_In_Aileron);
  Serial.print("Elevator:");
  Serial.println(TUYGUN.PWM_In_Elevator);
  Serial.print("Rudder:");
  Serial.println(TUYGUN.PWM_In_Rudder);
  
TUYGUN_PWM_Write(&TUYGUN1);
TUYGUN1.servo1.writeMicroseconds (500);

  
  
}
