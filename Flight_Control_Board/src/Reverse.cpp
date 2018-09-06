
#include "../lib/Reverse.h"

Reverse_Statustypedef Reverse_Setup(struct __Reverse_HandleTypeDef *Reverse){


  return Reverse_OK;
};

Reverse_Statustypedef Reverse_Start(
struct __Reverse_HandleTypeDef *Reverse,
struct __PWM_IN_HandleTypeDef *PWM_IN, struct __PWM_OUT_HandleTypeDef *PWM_OUT){

Reverse->Reverse_coef = PWM_IN->PWM_AUX_2;

Serial.println(PWM_IN->PWM_Throttle);



  return Reverse_OK;

};
