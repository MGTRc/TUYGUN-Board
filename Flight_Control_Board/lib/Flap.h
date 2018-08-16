#ifndef _Flap_H
#define _Flap_H

#include <Arduino.h>
#include "../lib/PWM_OUT.h"
#include "../lib/PWM_IN.h"
#include "../lib/Servo/src/Servo.h"

typedef enum Flap_StatusTypeDef{
  Flap_OK,
  Flap_ERROR
}Flap_StatusTypeDef;

typedef struct __Flap_HandleTypeDef{
  uint16_t S0, S1, S2, S3, S4;
  uint16_t lastposition;
  uint16_t P1, P2, P3, P4;
  bool isCompleted;
  uint8_t Interval;
  unsigned long LastTime;
  uint16_t xyz;
}Flap_HandleTypeDef;


Flap_StatusTypeDef Flap_Setup(struct _Flap_HandleTypeDef *Flap,struct __PWM_OUT_HandleTypeDef *PWM_OUT );
Flap_StatusTypeDef Flap_Start(

  struct __Flap_HandleTypeDef *Flap ,
  struct __PWM_OUT_HandleTypeDef *PWM_OUT ,
  struct __PWM_IN_HandleTypeDef *PWM_IN);

uint16_t poscheck(uint16_t AUX);

#endif
