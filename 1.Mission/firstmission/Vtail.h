#ifndef Vtail
#define Vtail
#include "PWM_OUT.h"
#include "PWM_IN.h"


#define Vtail_Elevator  //Elevator read pin Arduino (A4)//PWM_IN kütüphanesinden gelen değerler
#define Vtail_Rudder  //Rudder read pin Arduino (A5)
#define Vtail_Spoiler //Aileron read pin Arduino (A3)


 typedef enum Vtail_StatusTypeDef //return Vtail_OK yazabilmek için bunu ekledik.Doğru mu bilmiyoruz.
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
