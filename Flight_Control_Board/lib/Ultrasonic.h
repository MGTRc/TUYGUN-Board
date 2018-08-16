#ifndef _Ultrasonic_H
#define _Ultrasonic_H

#include <Arduino.h>
#include "../lib/PWM_IN.h"
#include "../lib/PWM_OUT.h"

#define trigPin (7)
#define echoPin (6)
#define pinCS   (10)

typedef enum Ultrasonic_Statustypedef {
 Ultrasonic_OK,
 Ultrasonic_ERROR,
} Ultrasonic_Statustypedef;


typedef struct __Ultrasonic_HandleTypeDef{
  int pwmx;
  long Duration ;
  float Distance;
  long Interval;
  unsigned long LastTime;
  bool isCompleted;
  float ErrayDist[10];
  float ErrayTemp[9];
}Ultrasonic_HandleTypeDef;


Ultrasonic_Statustypedef Ultrasonic_Setup(struct __Ultrasonic_HandleTypeDef *Ultrasonic);
Ultrasonic_Statustypedef Ultrasonic_Start(struct __Ultrasonic_HandleTypeDef *Ultrasonic,
struct __PWM_IN_HandleTypeDef *PWM_IN , struct __PWM_OUT_HandleTypeDef *PWM_OUT);


#endif
