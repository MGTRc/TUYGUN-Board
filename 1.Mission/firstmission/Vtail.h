#ifndef Vtail
#define Vtail
#include "PWM_OUT.h"
#include "PWM_IN.h"

#define Throttle (A2) // Throttle read pin Arduino (A2)//*********
#define Aileron (A3) //Aileron read pin Arduino (A3)
#define Elevator (A4) //Elevator read pin Arduino (A4)//PWM_IN kütüphanesinden gelen değerler
#define Rudder (A5) //Rudder read pin Arduino (A5)
#define Drop (A6) //Drop read pin Arduino (A6)
#define Flap (A7)//Flap read pin Arduino (A7)//*******************
#define stabil durum 1500 // Bunun Setup fonksiyonu içinde set edilmesi gerektiğini dokumanda yazmıştım.

// Kodlarama değişken adları boşluklu olmaz.
//PWM değerleri oluşturdupunun PWM_IN_HandleTypeDef PWM_In içerisinde oluşmaktadır. Bu değişken içerisinden bu değerleri almanız gerekiyor.
//Kütüphane oluştururkken , header dosyasına değişkenler ve fonksiyonları tanımlıyorduk. CPP kısmında ise içini dolduruyoruk.

int gelen deger,sonuc; 
if (stabil durum=Elevator && stabil durum=Rudder){
  |(gelen deger-1500)|*0.25=sonuc;  
  Elevator=1500-sonuc;
  Rudder=1500+sonuc;
}




//*******************************
//Functions for Vtail
//*******************************
Vtail_StatusTypeDef PWM_OUT_Vtail_Start(struct __Vtail_HandleTypeDef *Vtail);
Vtail_StatusTypeDef Vtail_Start(struct __PWM_IN_HandleTypeDef *PWM_In);
Vtail_StatusTypeDef Vtail_Start(struct __PWM_OUT_HandleTypeDef *PWM_Out);
Vtail_StatusTypeDef PWM_OUT_Vtail_Setup(struct __Vtail_HandleTypeDef *PWM_Out);


#endif Vtail
