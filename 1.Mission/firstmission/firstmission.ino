#include "PWM_IN.h"
#include "Servo.h"

TUYGUN_HandleTypeDef TUYGUN;
  Servo sg90;
int attach =9;
void setup() {
Serial.begin(9600);
sg90. attach(9);
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
  
  sg90.write (180);       // değiştirebiliriz sayıyı
  
  
}
