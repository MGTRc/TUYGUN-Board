#include "../lib/Vtail.h"

Vtail_StatusTypeDef Vtail_Start(
  struct __Vtail_HandleTypeDef *Vtail ,
  struct __PWM_OUT_HandleTypeDef *PWM_OUT ,
  struct __PWM_IN_HandleTypeDef *PWM_IN){

  uint16_t cal_elevator;
  uint16_t cal_rudder;

  Vtail->IN_Elevator = PWM_IN->PWM_Elevator;
  Vtail->IN_Rudder = PWM_IN->PWM_Rudder;
  Vtail->IN_Spoiler = PWM_IN->PWM_AUX_2;

  if(Vtail->IN_Spoiler < Vtail->Spoiler_Threshold){
    cal_elevator  = Vtail->elevator_coef * abs( 1500 - (Vtail->IN_Elevator) );
    cal_rudder    = Vtail->rudder_coef * abs( 1500 - (Vtail->IN_Rudder) );

    PWM_OUT->PWM_VTail_Left = 1500
      + Vtail_Reverse(cal_elevator,0) + Vtail_Reverse(cal_rudder,0);

    PWM_OUT->PWM_VTail_Right = 1500
      + Vtail_Reverse(cal_elevator,1) + Vtail_Reverse(cal_rudder,0);
  }

  else if(Vtail->IN_Spoiler > Vtail->Spoiler_Threshold){
    PWM_OUT->PWM_VTail_Left = 1000;
    PWM_OUT->PWM_VTail_Right = 2000;
  }

  else{
    return Vtail_ERROR;
  }

  return Vtail_OK;
};

Vtail_StatusTypeDef Vtail_Setup(struct __Vtail_HandleTypeDef *Vtail){
  Vtail->elevator_coef = 0.25;
  Vtail->rudder_coef = 0.25;
  Vtail->Spoiler_Threshold = 1500;
  return Vtail_OK;
};

uint16_t Vtail_Reverse(uint16_t PWM_Value , uint8_t reverse){
  if(reverse == 1){
    return -1 * PWM_Value;
  }else{
    return PWM_Value;
  }
};
