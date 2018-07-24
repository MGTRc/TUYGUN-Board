#include "Vtail.h"
#include  <math.h>

Vtail_StatusTypeDef Vtail_Start(struct __PWM_IN_HandleTypeDef *PWM_In){
 PWM_In->PWM_In_Elevator = PWM_Vtail_Elevator ;
 PWM_In->PWM_In_Rudder = PWM_Vtail_Rudder ;
 
  return Vtail_OK;
}
Vtail_StatusTypeDef Vtail_Start(struct __PWM_OUT_HandleTypeDef *PWM_Out){
 
if (PWM_Vtail_Elevator!=1500){
  fabs(PWM_Vtail_Elevator-1500)*0.25=Result;  
  Vtail_Right=1500-Result;
  Vtail_Left=1500+Result;
}
else if(PWM_Vtail_Rudder!=1500){
  fabs(PWM_Vtail_Rudder-1500)*0.25=Result;
  Vtail_Right=1500+Result;
  Vtail_Left=1500+Result;         // Spoiler in durumunu nasıl aktif edeceğimizi anlamadık
}

    return Vtail_OK;
}





