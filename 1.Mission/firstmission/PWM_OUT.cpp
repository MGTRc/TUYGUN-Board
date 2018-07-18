#include "PWM_OUT.h"
#include "Servo.h"
  
PWM_OUT_StatusTypeDef PWM_OUT_Setup_Pin(struct __PWM_OUT_HandleTypeDef *PWM_Out){
	pinMode(Aileron_1, OUTPUT);
  pinMode(Aileron_2, OUTPUT);
  pinMode(Vtail_1, OUTPUT);
  pinMode(Vtail_2, OUTPUT);
  pinMode(Rudder_1, OUTPUT);
	pinMode(Flap_1, OUTPUT);
  pinMode(Flap_2, OUTPUT);
	pinMode(Drop_1, OUTPUT);
  pinMode(Drop_2, OUTPUT);
  pinMode(Rudder_1, OUTPUT);
  pinMode(Throttle_1, OUTPUT);
  
  Aileron_Left.attach(2);   //  Aileron_Left.attach(Aileron_1) şeklinde olucak;
  Aileron_Right.attach(3);          
  Flap_Left.attach(4);
  Flap_Right.attach(5);
  Vtail_Left.attach(6);             
  Vtail_Right.attach(7);
  Cover_1.attach(8);
  Cover_2.attach(9);
  Landing_Gear.attach(10);
  Throttle.attach(11);
  return PWM_Out_OK;
}


PWM_OUT_StatusTypeDef PWM_OUT_PWM_Write(struct __PWM_OUT_HandleTypeDef *PWM_Out){
  Aileron_Left.writeMicroseconds(PWM_Out->PWM_Aileron_Left); // Bizim toplamda 8-10 tane çıkısımız var.
	return PWM_Out_OK;
}

