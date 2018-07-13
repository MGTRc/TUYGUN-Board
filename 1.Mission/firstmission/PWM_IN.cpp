#include "PWM_IN.h"

TUYGUN_StatusTypeDef TUYGUN_setup_pin(struct __TUYGUN_HandleTypeDef *TUYGUN){
pinMode(Throttle, INPUT);
pinMode(Aileron, INPUT);
pinMode(Elevator, INPUT);
pinMode(Rudder, INPUT);
pinMode(Drop, INPUT);
pinMode(Flap, INPUT);
//pinMode(Reverse, INPUT);
return TUYGUN_OK;
}

TUYGUN_StatusTypeDef TUYGUN_PWM_Read(struct __TUYGUN_HandleTypeDef *TUYGUN){
  TUYGUN->PWM_In_Throttle = pulseIn(Throttle,HIGH);
  TUYGUN->PWM_In_Aileron   = pulseIn(Aileron,HIGH);
  TUYGUN->PWM_In_Elevator   = pulseIn(Elevator,HIGH);
  TUYGUN->PWM_In_Rudder   = pulseIn(Rudder,HIGH);
  TUYGUN->PWM_In_Flap       = pulseIn(Flap,HIGH); 
  return TUYGUN_OK;
}

