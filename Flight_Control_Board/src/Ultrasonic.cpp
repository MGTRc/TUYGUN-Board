#include "../lib/Ultrasonic.h"

Ultrasonic_Statustypedef Ultrasonic_Setup(struct __Ultrasonic_HandleTypeDef *Ultrasonic){
  Ultrasonic-> Interval = 400;
  Ultrasonic-> isCompleted = 0;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pinCS, OUTPUT);

  if (SD.begin())
    {
    Serial.println("SD Kart basariyla okundu.");
    }

  else
    {
    Serial.println("SD Kartta bir sikinti var.");
    return;
    }

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

  Ultrasonic->myFile = SD.open("log1.txt", FILE_WRITE);
  if (Ultrasonic->myFile)
    {
    Ultrasonic->myFile.println(Ultrasonic->Distance,3);
    Ultrasonic->myFile.close(); // close the file
    }
  // if the file didn't open, print an error:
  else
    {
    Serial.println("error opening test.txt");
    }

  Ultrasonic->isCompleted = 1;
  Ultrasonic->LastTime = millis();
 }

 else if(Ultrasonic->isCompleted == 1 && (millis()-Ultrasonic->LastTime >= Ultrasonic->Interval)){
  Ultrasonic->isCompleted = 0 ;
 }
}
else
{
   Serial.println("No Signal");
}

  return Ultrasonic_OK;

};
