#include <Arduino.h>
#include "../lib/PWM_IN.h"
#include "../lib/PWM_OUT.h"
#include "../lib/Ultrasonic.h"
#include "../lib/Flap.h"

PWM_IN_HandleTypeDef PWM_IN;
PWM_OUT_HandleTypeDef PWM_OUT;
Ultrasonic_HandleTypeDef Ultrasonic;
Flap_HandleTypeDef Flap;

void setup() {
    PWM_In_Setup(&PWM_IN);
    PWM_OUT_Setup(&PWM_OUT);
    Ultrasonic_Setup(&Ultrasonic);
    Flap_Setup(&Flap,&PWM_OUT);
  Serial.begin(9600);
}

void loop() {
    PWM_IN_Read(&PWM_IN);  // Read PWM Values from PIXHAWK 2.4.8

    Serial.println(PWM_IN.PWM_AUX_2);
    //Ultrasonic_Start(&Ultrasonic,&PWM_IN, &PWM_OUT);
    Flap_Start(&Flap,&PWM_OUT,&PWM_IN);

    PWM_OUT_Write(&PWM_OUT);
}
