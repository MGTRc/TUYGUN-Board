#include "PWM_IN.h"
#include "PWM_OUT.h"

TUYGUN_HandleTypeDef TUYGUN;

void setup() {
Serial.begin(9600);
}

void loop() {
  TUYGUN_PWM_Read(&TUYGUN);
  Serial.print("Throttle:");
  Serial.println(TUYGUN.TUYGUN_Throttle);
  Serial.print("Aileron:");
  Serial.println(TUYGUN.TUYGUN_Aileron);
  Serial.print("Elevator:");
  Serial.println(TUYGUN.TUYGUN_Elevator);
  Serial.print("Rudder:");
  Serial.println(TUYGUN.TUYGUN_Rudder);
  
  servkont.write (180);       // değiştirebiliriz sayıyı
  
  
}
