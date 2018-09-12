#include "../lib/Reverse.h"

Reverse_Statustypedef Reverse_Setup(struct __Reverse_HandleTypeDef *Reverse){

Reverse->Throttle_min = 1000;
 Reverse -> IntervalRev1 = 6000;
 Reverse -> IntervalRev2 = 12000;
 Reverse->y =1 ;
 Reverse->z =1;

Reverse->isCompletedRev = false;

  return Reverse_OK;
};
long Switchmap (long x, long in_min, long in_max, long out_min, long out_max){

  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
};

Reverse_Statustypedef Reverse_Start(
struct __Reverse_HandleTypeDef *Reverse,
struct __PWM_IN_HandleTypeDef *PWM_IN, struct __PWM_OUT_HandleTypeDef *PWM_OUT){

Reverse->Reverse_coef = PWM_IN->PWM_AUX_3;

if(Reverse->Reverse_coef<1500) {

if(PWM_IN->PWM_Throttle<Reverse->Throttle_min) {
  Reverse->Throttle_min = PWM_IN->PWM_Throttle ;
}

Reverse->Reverse_Throttle= Switchmap (PWM_IN->PWM_Throttle,Reverse->Throttle_min,2000,1500,2000);

Reverse->Reverse_Throttle= constrain(Reverse->Reverse_Throttle, Reverse->Throttle_min, 2000);

PWM_OUT->PWM_Throttle = Reverse->Reverse_Throttle ;
Serial.print("Giris:");
Serial.println(PWM_IN->PWM_Throttle);
Serial.print("Cikis:");
Serial.println(PWM_OUT->PWM_Throttle);
}
else {
  if(Reverse->isCompletedRev == 0) {
      Reverse->isCompletedRev = true;
      Reverse->LastTimeRev = millis();
    }
    else if ( millis()  >= 6000 && Reverse->y ==1) {
    PWM_OUT->PWM_Throttle = 1500;
    Serial.print("First: ");
    Serial.println(millis());
    Reverse->y = 0 ;

  }
  else if (millis() >= 12000 && Reverse->z ==1) {
    PWM_OUT->PWM_Throttle = 1000;
    Serial.print("Second: ");
    Serial.println(millis());
    Reverse->z =0;
  }
}

  Serial.println(  PWM_OUT->PWM_Throttle);

  return  Reverse_OK ;

};
