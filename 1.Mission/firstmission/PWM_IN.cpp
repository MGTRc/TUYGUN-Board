#include "PWM_IN.h"

TUYGUN_StatusTypeDef TUYGUN_Setup_Pin(struct __TUYGUN_HandleTypeDef *TUYGUN){
	pinMode(Throttle, INPUT);
	pinMode(Aileron, INPUT);
	pinMode(Elevator, INPUT);
	pinMode(Rudder, INPUT);
	pinMode(Flap, INPUT);
	pinMode(Reverse, INPUT);
	return TUYGUN_OK;
}

TUYGUN_StatusTypeDef TUYGUN_PWM_Read(struct __TUYGUN_HandleTypeDef *TUYGUN){
  TUYGUN->TUYGUN_Aileron 	= pulseIn(Aileron,HIGH); 
  return TUYGUN_OK;
}

