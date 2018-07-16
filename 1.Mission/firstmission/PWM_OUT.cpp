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
  Aileron_Left.attach(Aileron_1);    // Aileron 1 header dosyasında 2.pin olarak tanımlanmış ama burada 1 görünüyor.   
  Aileron_Right.attach(2);           // İkinci durum pinlerin kolay değişmesi için headerde define ettik.
  Vtail_Left.attach(3);             
  Vtail_Right.attach(4);
  Flap_Left.attach(5);
  Flap_Right.attach(6);
  Throttle.attach(7);
  Landing_Gear.attach(8);
  Cover_1.attach(9);
  Cover_2.attach(10);
  return PWM_Out_OK;
}
  PWM_OUT_StatusTypeDef PWM_OUT_PWM_Write(struct __PWM_OUT_HandleTypeDef *PWM_Out){

  PWM_Out->Aileron_Left;
  PWM_Out->Aileron_Right;
  PWM_Out->Vtail_Left;
  PWM_Out->Vtail_Right;
  PWM_Out->Flap_Left;
  PWM_Out->Flap_Right;
  PWM_Out->Throttle;
  PWM_Out->Landing_Gear;
  PWM_Out->Cover_1;
  PWM_Out->Cover_2;
  Aileron_Left.writeMicroseconds (PWM_OUT->PWM_Aileron_Left); // Burası hata veriyor ve sürekli değişken olucak.
	return PWM_Out_OK;
}

