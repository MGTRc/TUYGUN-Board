#ifndef Vtail
#define Vtail
#include "PWM_OUT.h"
#include "PWM_IN.h"
#define Vtail_Elevator  
#define Vtail_Rudder  
#define Vtail_Aileron 


 typedef enum Vtail_StatusTypeDef
{
 Vtail_ERROR,
 Vtail_OK,
 Vtail_BUSY,
 Vtail_TIMEOUT,
 
}Vtail_StatusTypeDef;

typedef struct  __Vtail_HandleTypeDef{
  uint16_t PWM_Vtail_Elevator;
  uint16_t PWM_Vtail_Aileron;
  uint16_t stabil_durum=1500;                  
  uint16_t gelen_deger;
  uint16_t sonuc;




//*******************************
//Functions for Vtail
//*******************************
Vtail_StatusTypeDef Vtail_Start(struct __Vtail_HandleTypeDef *Vtail);
Vtail_StatusTypeDef Vtail_Setup(struct __Vtail_HandleTypeDef *Vtail);
Vtail_StatusTypeDef Vtail_Start(struct __PWM_IN_HandleTypeDef *PWM_In);
Vtail_StatusTypeDef Vtail_Start(struct __PWM_OUT_HandleTypeDef *PWM_Out);


#endif Vtail

