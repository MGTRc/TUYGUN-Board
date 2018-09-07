#include "../lib/Reverse.h"

Reverse_Statustypedef Reverse_Setup(struct __Reverse_HandleTypeDef *Reverse){

Reverse->Throttle_min = 1000;

  return Reverse_OK;
};
long Switchmap (long x, long in_min, long in_max, long out_min, long out_max){

  return (x - in_min) * (out_max - out_min + 1) / (in_max - in_min + 1) + out_min;
};

Reverse_Statustypedef Reverse_Start(
struct __Reverse_HandleTypeDef *Reverse,
struct __PWM_IN_HandleTypeDef *PWM_IN, struct __PWM_OUT_HandleTypeDef *PWM_OUT){

Reverse->Reverse_coef = PWM_IN->PWM_AUX_3;

if(Reverse->Reverse_coef<1500) {

if(PWM_IN->PWM_Throttle<Reverse->Throttle_min) {
  Reverse->Throttle_min = PWM_IN->PWM_Throttle ;
}

Reverse->Reverse_Throttle= Switchmap (PWM_IN->PWM_Throttle,1500,2000,Reverse->Throttle_min,2000);
PWM_OUT->PWM_Throttle = PWM_IN->PWM_Throttle ;
Serial.println(Reverse->Reverse_Throttle);
}
else {




}

  return  Reverse_OK ;

};
