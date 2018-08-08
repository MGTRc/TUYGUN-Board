#ifndef _PWM_IN_H
#define _PWM_IN_H

#include <Arduino.h>

//#define Aileron_IN  (A2)
//#define Elevator_IN (A3)
//#define Throttle_IN (A4)
//#define Rudder_IN   (A5)
#define AUX_1_IN    (A4)    //defined for Flap;
//#define AUX_2_IN    (A7)    //defined for Spoiler;
//#define AUX_3_IN    (A8)    //defined for Reverse Thrust;
//#define AUX_4_IN    (A9)    //Empty;

typedef enum PWM_IN_StatusTypeDef {
  PWM_IN_OK,
  PWM_IN_ERROR,
  PWM_IN_BUSY,
  PWM_IN_TIMEOUT,
} PWM_IN_StatusTypeDef;

typedef struct __PWM_IN_HandleTypeDef{
  uint16_t PWM_Aileron;
  uint16_t PWM_Elevator;
  uint16_t PWM_Throttle;
  uint16_t PWM_Rudder;
  uint16_t PWM_AUX_1;
  uint16_t PWM_AUX_2;
  uint16_t PWM_AUX_3;
  uint16_t PWM_AUX_4;
}PWM_IN_HandleTypeDef;

//Functions
PWM_IN_StatusTypeDef PWM_In_Setup(struct __PWM_IN_HandleTypeDef *PWM_IN);
PWM_IN_StatusTypeDef PWM_IN_Read(struct __PWM_IN_HandleTypeDef *PWM_IN);
#endif
