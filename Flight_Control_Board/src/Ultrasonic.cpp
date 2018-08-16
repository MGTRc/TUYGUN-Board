#include "../lib/Ultrasonic.h"

Ultrasonic_Statustypedef Ultrasonic_Setup(struct __Ultrasonic_HandleTypeDef *Ultrasonic){
  Ultrasonic-> Interval = 400;
  Ultrasonic-> isCompleted = false;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

 for(int j=0 ; j<9 ; j++ )
  {
    Ultrasonic->ErrayDist[j]=0;
  }

 for(int k=0 ; k<8 ; k++ )
  {
    Ultrasonic->ErrayTemp[k]=0;
  }
  return Ultrasonic_OK;
};

Ultrasonic_Statustypedef Ultrasonic_Start(
struct __Ultrasonic_HandleTypeDef *Ultrasonic,
struct __PWM_IN_HandleTypeDef *PWM_IN, struct __PWM_OUT_HandleTypeDef *PWM_OUT){
/*
Ultrasonic->pwmx = PWM_IN->PWM_AUX_1;

if(Ultrasonic->pwmx>1500){

if(Ultrasonic->isCompleted == 0){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Ultrasonic->Duration = pulseIn(echoPin, HIGH );
  Ultrasonic->Distance =Ultrasonic->Duration/29.10/2 ;
  Serial.println(Ultrasonic->Distance,3);

  for(int o=9; o > 0; o--){

       Ultrasonic-> ErrayTemp[o-1]=Ultrasonic->ErrayDist[o];

       }

    Ultrasonic->ErrayDist[9]=Ultrasonic->Distance;

   for(int p=8; p >= 0; p--){

       Ultrasonic->ErrayDist[p]=Ultrasonic->ErrayTemp[p];

       }

  Ultrasonic->isCompleted = true;
  Ultrasonic->LastTime = millis();
 }
 else if((Ultrasonic->isCompleted == true) && (millis()-Ultrasonic->LastTime >= Ultrasonic->Interval)){
  Ultrasonic->isCompleted = false;
 }
}
else
{
   Serial.println("No Signal");
}
  return Ultrasonic_OK;
*/
  PWM_OUT->PWM_Aileron_Left = 2000;
};
