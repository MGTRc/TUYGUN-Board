
#include "../lib/Reverse.h"

Reverse_Statustypedef Reverse_Setup(struct __Reverse_HandleTypeDef *Reverse){


  return Reverse_OK;
};

Reverse_Statustypedef Reverse_Start(
struct __Reverse_HandleTypeDef *Reverse,
struct __PWM_IN_HandleTypeDef *PWM_IN, struct __PWM_OUT_HandleTypeDef *PWM_OUT){

Reverse->Reverse_coef = PWM_IN->PWM_AUX_2;

if(Reverse->Reverse_coef>1500) {
Serial.println(PWM_IN->PWM_Throttle);

Reverse->Reverse_Throttle= map(PWM_IN->PWM_Throttle,1500,2000,1000,2000);

}

  return Reverse_OK;

};
