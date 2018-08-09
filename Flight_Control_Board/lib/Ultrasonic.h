#ifndef _Ultrasonic_H
#define _Ultrasonic_H

#include <Arduino.h>

#define trigPin (12)
#define echoPin (13)

typedef enum Ultrasonic_Statustypedef {
 Ultrasonic_OK,
 Ultrasonic_ERROR,
} Ultrasonic_Statustypedef;


typedef struct __Ultrasonic_HandleTypeDef{
int x;
long Duration ;
int Distance;
 long Interval;
unsigned long Msecond_1;
unsigned long Msecond_2;

}Ultrasonic_HandleTypeDef;


Ultrasonic_Statustypedef Ultrasonic_Setup(struct __Ultrasonic_HandleTypeDef *Ultrasonic);
Ultrasonic_Statustypedef Ultrasonic_Start(struct __Ultrasonic_HandleTypeDef *Ultrasonic,
struct __PWM_IN_HandleTypeDef *PWM_IN);


#endif
