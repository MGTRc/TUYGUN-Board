#include "PWM_IN.h"

TUYGUN_HandleTypeDef TUYGUN;

void setup() {
  Serial.begin(9600);
  if(TUYGUN_Setup_Pin(&TUYGUN)){
  	Serial.println("Setted PINS (OK)");
  }
}

void loop() {
  TUYGUN_PWM_Read(&TUYGUN);
  Serial.println(TUYGUN.TUYGUN_Aileron);
}
