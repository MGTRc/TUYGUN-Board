#include <Arduino.h>
#include "PWM_IN.h"
#include "PWM_OUT.h"
#include "Vtail.h"

PWM_IN_HandleTypeDef PWM_IN;
PWM_OUT_HandleTypeDef PWM_OUT;
Vtail_HandleTypeDef Vtail;

void setup() {
    PWM_In_Setup(&PWM_IN);
    Serial.begin(9600);
    PWM_OUT_Setup(&PWM_OUT);
}

void loop() {
    PWM_IN_Read(&PWM_IN);



    PWM_OUT_Write(&PWM_OUT);
}
