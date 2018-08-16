#include "../lib/Flap.h"

Flap_StatusTypeDef Flap_Start(
  struct __Flap_HandleTypeDef *Flap,
  struct __PWM_OUT_HandleTypeDef *PWM_OUT ,
  struct __PWM_IN_HandleTypeDef *PWM_IN){

Flap->AUX = PWM_IN->PWM_AUX_2;

if(Flap->lastposition > poscheck(Flap->AUX,Flap)){

      for(Flap->lastposition; Flap->lastposition > poscheck(Flap->AUX,Flap); ){
            if(Flap->isCompleted==false){
              PWM_OUT->PWM_Flap_Left = Flap->lastposition;
              Flap->lastposition-=10;
              Flap->isCompleted=true;
              Flap->LastTime=millis();
              }
            else if((Flap->isCompleted==true) && (millis() - Flap->LastTime > Flap->Interval)){
              Flap->isCompleted==false;
              }
      }
}

else if(Flap->lastposition < poscheck(Flap->AUX,Flap)){

      for(Flap->lastposition; Flap->lastposition < poscheck(Flap->AUX,Flap); ){
          if(Flap->isCompleted==false){
            PWM_OUT->PWM_Flap_Left = Flap->lastposition;
            Flap->lastposition+=10;
            Flap->isCompleted=true;
            Flap->LastTime=millis();
            }
          else if((Flap->isCompleted==true) && (millis() - Flap->LastTime >= Flap->Interval)){
            Flap->isCompleted=false;
            }
      }
}

else{
   Serial.println("Hata");
}




return Flap_OK;
}

Flap_StatusTypeDef  Flap_Setup(struct __Flap_HandleTypeDef *Flap, struct __PWM_OUT_HandleTypeDef *PWM_OUT){
  PWM_OUT->PWM_Flap_Left = 2000;
  Flap->lastposition = 2000;
  Flap->S0=850;
  Flap->S1=1100; Flap->P1=1000;
  Flap->S2=1500; Flap->P2=1350;
  Flap->S3=1800; Flap->P3=1700;
  Flap->S4=2000; Flap->P4=2000;
  Flap->isCompleted=false;
  Flap->Interval=30;

  return Flap_OK;
}


uint16_t poscheck(uint16_t AUX,struct __Flap_HandleTypeDef *Flap){
        if(AUX > Flap->S0 && AUX < Flap->S1){
          return Flap->P1;
        }
        else if(AUX > Flap->S1 && AUX < Flap->S2){
          return Flap->P2;
        }
        else if(AUX > Flap->S2 && AUX < Flap->S3){
          return Flap->P3;
        }
        else if(AUX > Flap->S3 && AUX < Flap->S4){
          return Flap->P4;
        }
        return Flap_OK;
}
