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

else
{
   Serial.println("Sinyal bozuk");
}
for(int i=9; i > 0; i--){

      Ultrasonic-> ErrayTemp[i-1]=Ultrasonic->ErrayDist[i];

        }

   Ultrasonic->ErrayDist[10]=Ultrasonic->Distance;

for(int i=8; i >= 0; i--){

        Ultrasonic->ErrayDist[i]=Ultrasonic->ErrayTemp[i];

      }
  Serial.println(Ultrasonic->ErrayDist[1]);
  return Ultrasonic_OK;
};

