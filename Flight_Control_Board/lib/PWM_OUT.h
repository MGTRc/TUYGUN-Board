#ifndef _PWM_OUT_H
#define _PWM_OUT_H

#include <Arduino.h>
#include "../lib/Servo/src/Servo.h"

#define Aileron_Left_OUT  (12)
#define Aileron_Right_OUT (13)
#define VTail_Left_OUT    (4)
#define VTail_Right_OUT   (5)
#define Flap_Left_OUT     (6)
#define Flap_Right_OUT    (7)
#define Throttle_OUT      (8)
#define Landing_Gear_OUT  (9)
#define Cover_1_OUT       (10)
#define Cover_2_OUT       (11)

typedef enum PWM_OUT_StatusTypeDef{
  PWM_OUT_OK,
  PWM_OUT_ERROR,
  PWM_OUT_BUSY,
  PWM_OUT_TIMEOUT,
}PWM_OUT_StatusTypeDef;

typedef struct __PWM_OUT_HandleTypeDef{
  //Ailerons
  uint16_t PWM_Aileron_Left;
  uint16_t PWM_Aileron_Right;
  //V-Tail
  uint16_t PWM_VTail_Left;
  uint16_t PWM_VTail_Right;
  //Flaps
  uint16_t PWM_Flap_Left;
  uint16_t PWM_Flap_Right;
  //Others
  uint16_t PWM_Throttle;
  uint16_t PWM_Landing_Gear;
  uint16_t PWM_Cover_1;
  uint16_t PWM_Cover_2;

  uint16_t hafiza1;
  uint16_t hafiza2;

  //Servos
  Servo Aileron_Left,Aileron_Right;
  Servo Vtail_Left,Vtail_Right;
  Servo Flap_Left,Flap_Right;
  Servo Throttle,Landing_Gear;
  Servo Cover_1,Cover_2;

}PWM_OUT_HandleTypeDef;

//Functions
PWM_OUT_StatusTypeDef PWM_OUT_Setup(struct __PWM_OUT_HandleTypeDef *PWM_OUT);
PWM_OUT_StatusTypeDef PWM_OUT_Write(struct __PWM_OUT_HandleTypeDef *PWM_OUT);
PWM_OUT_StatusTypeDef PWM_OUT_Memory(struct __PWM_OUT_HandleTypeDef *PWM_OUT,struct __PWM_IN_HandleTypeDef *PWM_IN);
PWM_OUT_StatusTypeDef PWM_OUT_Default_Values(struct __PWM_OUT_HandleTypeDef *PWM_OUT);
#endif
