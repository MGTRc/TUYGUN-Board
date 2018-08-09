#include "Ultrasonic.h"
#include "PWM_IN.h"

#include <Arduino.h>

Ultrasonic_Statustypedef Ultrasonic_Setup(struct __Ultrasonic_HandleTypeDef *Ultrasonic){
  Ultrasonic-> Interval = 400;
  Ultrasonic-> isCompleted = 0;
  Ultrasonic->ErrayDist[10];
  Ultrasonic->ErrayTemp[9];
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
struct __PWM_IN_HandleTypeDef *PWM_IN){

Ultrasonic->x = PWM_IN->PWM_AUX_1;

if(Ultrasonic->x>1500){

if(Ultrasonic->isCompleted == 0){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Ultrasonic->Duration = pulseIn(echoPin, HIGH );
  Ultrasonic-> Distance =Ultrasonic->Duration/29.10/2 ;

 // Serial.println(Ultrasonic->Distance,3);
  Ultrasonic->isCompleted = 1;
  Ultrasonic->LastTime = millis();
 }

 else if(Ultrasonic->isCompleted == 1 && (millis()-Ultrasonic->LastTime >= Ultrasonic->Interval)){
  Ultrasonic->isCompleted = 0 ;
 }

 for(int o=9; o > 0; o--){

       Ultrasonic-> ErrayTemp[o-1]=Ultrasonic->ErrayDist[o];

         }

    Ultrasonic->ErrayDist[9]=Ultrasonic->Distance;

 for(int p=8; p >= 0; p--){

         Ultrasonic->ErrayDist[p]=Ultrasonic->ErrayTemp[p];

       }
 for(int n=9; n >= 0; n--){
   Serial.println(Ultrasonic->ErrayDist[n]);
 }





}

else
{
   Serial.println("Sinyal bozuk");
}

  return Ultrasonic_OK;

};
