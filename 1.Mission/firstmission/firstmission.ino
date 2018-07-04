#include "PWM_IN.h"

struct __TUYGUN_HandleTypeDef *TUYGUN;

void setup() {
  // put your setup code here, to run once:
  TUYGUN_setup_pin(TUYGUN);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(A2)==HIGH){
      Serial.println("Kutuphane bas");
    }
}
