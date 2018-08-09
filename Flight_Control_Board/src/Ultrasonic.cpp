#include "../lib/Ultrasonic.h"
#include "../lib/PWM_IN.h"

#include <Arduino.h>

Ultrasonic_Statustypedef Ultrasonic_Setup(struct __Ultrasonic_HandleTypeDef *Ultrasonic){
  Ultrasonic-> Interval = 5000;
  Ultrasonic-> Msecond_1 = 0;
  Ultrasonic->Msecond_2 = millis();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  return Ultrasonic_OK;
};

Ultrasonic_Statustypedef Ultrasonic_Start(
struct __Ultrasonic_HandleTypeDef *Ultrasonic,
struct __PWM_IN_HandleTypeDef *PWM_IN){

Ultrasonic->x = PWM_IN->PWM_AUX_1;

Ultrasonic->x = PWM_IN->PWM_AUX_1;

if (Ultrasonic->x > 1500) {
if(Ultrasonic->Msecond_2 - Ultrasonic->Msecond_1 >= Ultrasonic->Interval){
 Ultrasonic->Msecond_1 = Ultrasonic->Msecond_2;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 Ultrasonic->Duration = pulseIn(echoPin, HIGH );
 Ultrasonic-> Distance = Ultrasonic->Duration/29.1/2 ;

  Serial.println(Ultrasonic->Distance);
 }
}
else
{
   Serial.println("Sinyal bozuk");
}
  return Ultrasonic_OK;
};
