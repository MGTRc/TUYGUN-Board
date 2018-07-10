#include "PWM_OUT.h"
#include "Servo.h"
#define servkont
TUYGUN_StatusTypeDef TUYGUN_Setup_Pin(struct __TUYGUN_HandleTypeDef *TUYGUN){
	pinMode(Aileron1, OUTPUT);
  pinMode(Aileron2, OUTPUT);
  pinMode(Vtail1, OUTPUT);
  pinMode(Vtail2, OUTPUT);
  pinMode(Rudder1, OUTPUT);
	pinMode(Flap1, OUTPUT);
  pinMode(Flap2, OUTPUT);
	pinMode(Drop1, OUTPUT);
  pinMode(Drop2, OUTPUT);
  pinMode(Rudder1, OUTPUT);
  pinMode(Throttle1, OUTPUT);
  servkont.attach(5);
  
	return TUYGUN_OK;
}
TUYGUN_StatusTypeDef TUYGUN_PWM_Write(struct __TUYGUN_HandleTypeDef *TUYGUN){
  
 return TUYGUN_OK;

}

