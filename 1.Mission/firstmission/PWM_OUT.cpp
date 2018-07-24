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
  
  Aileron_Left.attach(Aileron_1);   
  Aileron_Right.attach(Aileron_2);          
  Flap_Left.attach(Flap_1);
  Flap_Right.attach(Flap_2);
  Vtail_Left.attach(Vtail_1);             
  Vtail_Right.attach(Vtail_2);
  Cover_1.attach(Drop_1);
  Cover_2.attach(Drop_2);
  Landing_Gear.attach(Rudder_1);
  Throttle.attach(Throttle_1);
  return PWM_Out_OK;
}

// Buarada hata al�yorum.
PWM_OUT_StatusTypeDef PWM_OUT_PWM_Write(struct __PWM_OUT_HandleTypeDef *PWM_Out){
  Aileron_Left.writeMicroseconds(PWM_Out->PWM_Aileron_Left); //�pucu bu de�iken PWM_Out'in i�inde tan�ml�. K�saca referans g�stermelisiniz.
  Aileron_Right.writeMicroseconds(PWM_Out->PWM_Aileron_Right);  // biz burayı yine anlamadik
  Flap_Left.writeMicroseconds(PWM_Out->PWM_Flap_Left);   
  Flap_Right.writeMicroseconds(PWM_Out->PWM_Flap_Right);
  Vtail_Left.writeMicroseconds(PWM_Out->PWM_VTail_Left);
  Vtail_Right.writeMicroseconds(PWM_Out->PWM_VTail_Right);
  Cover_1.writeMicroseconds(PWM_Out->PWM_Cover_1);
  Cover_2.writeMicroseconds(PWM_Out->PWM_Cover_2);
  Landing_Gear.writeMicroseconds(PWM_Out->PWM_Landing_Gear);
  Throttle.writeMicroseconds(PWM_Out->PWM_Throttle);
	return PWM_Out_OK;
}
