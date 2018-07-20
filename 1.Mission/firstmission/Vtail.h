#ifndef Vtail
#define Vtail
#include "PWM_OUT.h"
#include "PWM_IN.h"
#define Vtail_Elevator  
#define Vtail_Rudder  
#define Vtail_Aileron 


 typedef enum Vtail_StatusTypeDef
{
 Vtail_OK,
}Vtail_StatusTypeDef;



//*******************************
//Functions for Vtail
//*******************************
Vtail_StatusTypeDef PWM_OUT_Vtail_Start(struct __Vtail_HandleTypeDef *Vtail);
Vtail_StatusTypeDef Vtail_Start(struct __PWM_IN_HandleTypeDef *PWM_In);
Vtail_StatusTypeDef Vtail_Start(struct __PWM_OUT_HandleTypeDef *PWM_Out);
Vtail_StatusTypeDef PWM_OUT_Vtail_Setup(struct __Vtail_HandleTypeDef *Vtail);

#endif Vtail
