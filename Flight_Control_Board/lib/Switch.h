#ifndef _Switch_H
#define _Switch_H

#include <Arduino.h>
#include "../lib/PWM_OUT.h"
#include "../lib/PWM_IN.h"


typedef enum Switch_StatusTypeDef{
  Switch_OK,
  Switch_ERROR
}Switch_StatusTypeDef;

typedef struct __Switch_HandleTypeDef{

int Switchx;

}Switch_HandleTypeDef;

Switch_StatusTypeDef Switch_Setup(struct __Switch_HandleTypeDef *Switch);
Switch_StatusTypeDef Switch_Write(struct __Switch_HandleTypeDef *Switch,
struct __PWM_IN_HandleTypeDef *PWM_IN,struct __PWM_OUT_HandleTypeDef *PWM_OUT);

#endif
