#include "PWM_OUT.h"
#include "Servo.h"

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
  return TUYGUN_OK;
}
  TUYGUN_StatusTypeDef TUYGUN_PWM_Write(struct __TUYGUN_HandleTypeDef *TUYGUN){

  servo1.attach(1);       // servoları kütüphaneye Servo değikeniyle deklare ettik ama burada tanımlamadığımızı söylüyor.
  servo2.attach(2);     // Servoları kutuphane de tanımlayınca da başka bir hata veriyor ama biz bi hata bulamadık kodda
  servo3.attach(3);
  servo4.attach(4);
  servo5.attach(5);
  servo6.attach(6);
  servo7.attach(7);
  servo8.attach(8);
  servo9.attach(9);
  servo10.attach(10);
  
    
     
	return TUYGUN_OK;
}

