#include "PWM_IN.h"

TUYGUN_HandleTypeDef TUYGUN;

void setup() {
  Serial.begin(9600);
}

void loop() {
  TUYGUN_PWM_Read(&TUYGUN);
  Serial.println(TUYGUN.TUYGUN_Aileron);
}
