#ifndef PWM_IN
#define PWM_IN


//PWM_In Pin Configuration 

#include <Arduino.h>

#define Throttle (A2) // Throttle read pin Arduino (A2)
#define Aileron (A3) //Aileron read pin Arduino (A3)
#define Elevator (A4) //Elevator read pin Arduino (A4)
#define Rudder (A5) //Rudder read pin Arduino (A5)
#define Drop (A6) //Drop read pin Arduino (A6)
#define Flap (A7)//Flap read pin Arduino (A7)
//#define Reverse (A8)//Reverse read pin Arduino (A8)

//***********************************
// PWM_In Software Status Definitions          			        
//***********************************

typedef enum PWM_IN_StatusTypeDef
{
  PWM_In_ERROR,
  PWM_In_OK,
  PWM_In_BUSY,
  PWM_In_TIMEOUT,
}
PWM_IN_StatusTypeDef;

//***********************************
// TUYGUN Handle Struct
//***********************************
typedef struct __PWM_IN_HandleTypeDef
{
  uint16_t	PWM_In_Throttle;
  uint16_t	PWM_In_Aileron;
  uint16_t	PWM_In_Elevator;
  uint16_t	PWM_In_Rudder;
  uint16_t	PWM_In_Drop;
  uint16_t	PWM_In_Flap;
  uint16_t	PWM_In_Reverse;
}PWM_IN_HandleTypeDef;

//***********************************
//Functions for PWM_In
//***********************************
PWM_IN_StatusTypeDef PWM_IN_setup_pin(struct __PWM_IN_HandleTypeDef *PWM_In);
PWM_IN_StatusTypeDef PWM_IN_PWM_Read(struct __PWM_IN_HandleTypeDef *PWM_In);
#endif 
