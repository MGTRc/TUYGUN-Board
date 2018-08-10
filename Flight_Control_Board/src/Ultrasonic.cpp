#include "../lib/Ultrasonic.h"
#include "../lib/PWM_IN.h"

#include <Arduino.h>

Ultrasonic_Statustypedef Ultrasonic_Setup(struct __Ultrasonic_HandleTypeDef *Ultrasonic){
  Ultrasonic-> Interval = 400;
  Ultrasonic-> isCompleted = 0;
  Ultrasonic->myFile;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pinCS, OUTPUT);
 for(int j=0 ; j<9 ; j++ )
  {
    Ultrasonic->ErrayDist[j]=0;
  }

 for(int k=0 ; k<8 ; k++ )
  {
    Ultrasonic->ErrayTemp[k]=0;
  }



Ultrasonic->myFile = SD.open("SDlog.txt", FILE_WRITE);

if (SD.begin())
    {
    Serial.println(Ultrasonic->Distance);
    }

  else
    {
    Serial.println("SD card initialization failed");
    return;
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


   if (Ultrasonic->myFile)
       {
       myFile.println(Ultrasonic->Distance);
       myFile.close();
       }

     else
       {
       Serial.println("error opening SDlog.txt");
       }


}

else
{
   Serial.println("No Signal");
}

  return Ultrasonic_OK;

};
