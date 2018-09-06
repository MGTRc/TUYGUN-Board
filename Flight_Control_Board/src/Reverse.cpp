
#include "../lib/Reverse.h"

Reverse_Statustypedef Reverse_Setup(struct __Reverse_HandleTypeDef *Reverse){

Reverse->Throttle_min = 1000;

  return Reverse_OK;
};

Reverse_Statustypedef Reverse_Start(
struct __Reverse_HandleTypeDef *Reverse,
struct __PWM_IN_HandleTypeDef *PWM_IN, struct __PWM_OUT_HandleTypeDef *PWM_OUT){

Reverse->Reverse_coef = PWM_IN->PWM_AUX_2;

if(Reverse->Reverse_coef>1500) {
Serial.println(PWM_IN->PWM_Throttle);

if(PWM_IN->PWM_Throttle<Reverse->Throttle_min)  {
  Reverse->Throttle_min = PWM_IN->PWM_Throttle ;
}
Reverse->Reverse_Throttle= map(PWM_IN->PWM_Throttle,1500,2000,Reverse->Throttle_min,2000);

}
else {




}

  return Reverse_OK;

};
