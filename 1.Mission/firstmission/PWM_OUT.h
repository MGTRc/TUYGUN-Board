#ifndef _PWM_OUT
#define _PWN_OUT


//PWM_Out Pin Configuration 

#include <Arduino.h>
#include <Servo.h>


#define Aileron_1 (2)
#define Aileron_2 (3)
#define Flap_1    (4)
#define Flap_2    (5)
#define Vtail_1   (6) 
#define Vtail_2   (7) 
#define Drop_1    (8)
#define Drop_2    (9)
#define Rudder_1   (10) 
#define Throttle_1 (11) 

//***********************************
// PWM_Out Software Status Definitions          			        
//***********************************

typedef enum PWM_OUT_StatusTypeDef
{
  PWM_Out_ERROR,
  PWM_Out_OK,
  PWM_Out_BUSY,
  TPWM_Out_TIMEOUT,
}PWM_OUT_StatusTypeDef;


typedef struct  __PWM_OUT_HandleTypeDef{
  //Ailerons
  uint16_t Aileron_1;
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

  //Servos
  Servo Aileron_1,Aileron_Right;
  Servo Vtail_Left,Vtail_Right;
  Servo Flap_Left,Flap_Right;
  Servo Throttle,Landing_Gear;
  Servo Cover_1,Cover_2;

}PWM_OUT_HandleTypeDef;
  
 

//***********************************
//Functions for PWM_Out
//***********************************
PWM_OUT_StatusTypeDef PWM_OUT_Setup_Pin(struct __PWM_OUT_HandleTypeDef *PWM_Out);
PWM_OUT_StatusTypeDef PWM_OUT_PWM_Write(struct __PWM_OUT_HandleTypeDef *PWM_Out);


#endif
