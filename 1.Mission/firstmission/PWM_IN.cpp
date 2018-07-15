#include "PWM_IN.h"

PWM_IN_StatusTypeDef PWM_IN_setup_pin(struct __TPWM_IN_HandleTypeDef *PWM_In){
pinMode(Throttle, INPUT);
pinMode(Aileron, INPUT);
pinMode(Elevator, INPUT);
pinMode(Rudder, INPUT);
pinMode(Drop, INPUT);
pinMode(Flap, INPUT);
//pinMode(Reverse, INPUT);
return PWM_In_OK;
}

PWM_IN_StatusTypeDef PWM_IN_PWM_Read(struct __PWM_IN_HandleTypeDef *PWM_In){
  PWM_In->PWM_In_Throttle = pulseIn(Throttle,HIGH);
  PWM_In->PWM_In_Aileron   = pulseIn(Aileron,HIGH);
  PWM_In->PWM_In_Elevator   = pulseIn(Elevator,HIGH);
  PWM_In->PWM_In_Rudder   = pulseIn(Rudder,HIGH);
  PWM_In->PWM_In_Flap       = pulseIn(Flap,HIGH); 
  return PWM_In_OK;
}

