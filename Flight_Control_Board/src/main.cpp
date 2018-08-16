#include <Arduino.h>
#include "../lib/PWM_IN.h"
#include "../lib/PWM_OUT.h"
#include "../lib/Ultrasonic.h"

PWM_IN_HandleTypeDef PWM_IN;
PWM_OUT_HandleTypeDef PWM_OUT;
Ultrasonic_HandleTypeDef Ultrasonic;

void setup() {
    PWM_In_Setup(&PWM_IN);
    PWM_OUT_Setup(&PWM_OUT);
    Ultrasonic_Setup(&Ultrasonic);
  Serial.begin(9600);
}

void loop() {
    PWM_IN_Read(&PWM_IN);  // Read PWM Values from PİXHAWK 2.4.8


    Ultrasonic_Start(&Ultrasonic,&PWM_IN, &PWM_OUT);
    

    PWM_OUT_Write(&PWM_OUT);
}
