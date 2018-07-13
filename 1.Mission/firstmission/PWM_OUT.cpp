#include "PWM_OUT.h"
#include "Servo.h"
  Servo servo1;
  Servo servo2;
  Servo servo3;
  Servo servo4;
  Servo servo5;
  Servo servo6;
  Servo servo7;
  Servo servo8;
  Servo servo9;
  Servo servo10;
TUYGUN_StatusTypeDef1 TUYGUN_Setup_Pin(struct __TUYGUN_HandleTypeDef1 *TUYGUN1){
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
  servo1.attach(1);       
  servo2.attach(2);    
  servo3.attach(3);
  servo4.attach(4);
  servo5.attach(5);
  servo6.attach(6);
  servo7.attach(7);
  servo8.attach(8);
  servo9.attach(9);
  servo10.attach(10);
  return TUYGUN_OK1;
}
  TUYGUN_StatusTypeDef1 TUYGUN_PWM_Write(struct __TUYGUN_HandleTypeDef1 *TUYGUN1){

  TUYGUN1->servo1;
  TUYGUN1->servo2;
  TUYGUN1->servo3;
  TUYGUN1->servo4;
  TUYGUN1->servo5;
  TUYGUN1->servo6;
  TUYGUN1->servo7;
  TUYGUN1->servo8;
  TUYGUN1->servo9;
  TUYGUN1->servo10;
 
     
	return TUYGUN_OK1;
}

