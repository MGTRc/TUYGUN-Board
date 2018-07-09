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
  TUYGUN->TUYGUN_Throttle = pulseIn(Throttle,HIGH);
  TUYGUN->TUYGUN_Aileron   = pulseIn(Aileron,HIGH);
  TUYGUN->TUYGUN_Elevator   = pulseIn(Elevator,HIGH);
  TUYGUN->TUYGUN_Rudder   = pulseIn(Rudder,HIGH);
  TUYGUN->TUYGUN_Flap       = pulseIn(Flap,HIGH); 
  return TUYGUN_OK;
}

