#ifndef _Vtail_H
#define _Vtail_H

#include <Arduino.h>
#include "../lib/PWM_OUT.h"
#include "../lib/PWM_IN.h"
#include "../lib/Servo/src/Servo.h"

typedef enum Vtail_StatusTypeDef{
  Vtail_OK,
  Vtail_ERROR
} Vtail_StatusTypeDef;

typedef struct __Vtail_HandleTypeDef{
  uint16_t IN_Elevator;
  uint16_t IN_Spoiler;
  uint16_t IN_Rudder;
  uint16_t OUT_VTail_Left, OUT_VTail_Right;
  uint16_t Spoiler_Threshold;

  float elevator_coef;
  float rudder_coef;

} Vtail_HandleTypeDef;

//  Functions //
Vtail_StatusTypeDef Vtail_Setup(struct __Vtail_HandleTypeDef *Vtail);
Vtail_StatusTypeDef Vtail_Start(
  struct __Vtail_HandleTypeDef *Vtail ,
  struct __PWM_OUT_HandleTypeDef *PWM_OUT ,
  struct __PWM_IN_HandleTypeDef *PWM_IN);
uint16_t Vtail_Reverse(uint16_t PWM_Value , uint8_t reverse);

#endif
