#ifndef PWM_IN
#define PWM_IN
//TUYGUN Pin Configuration 

#include <Arduino.h>

#define Throttle (A2) // Throttle read pin Arduino (A2)
#define Aileron (A3) //Aileron read pin Arduino (A3)
#define Elevator (A4) //Elevator read pin Arduino (A4)
#define Rudder (A5) //Rudder read pin Arduino (A5)
#define Drop (A6) //Drop read pin Arduino (A6)
#define Flap (A7)//Flap read pin Arduino (A7)
//#define Reverse (A8)//Reverse read pin Arduino (A8)

//***********************************
// TUYGUN Software Status Definitions          			        
//***********************************

typedef enum TUYGUN_StatusTypeDef
{
  TUYGUN_ERROR,
  TUYGUN_OK,
  TUYGUN_BUSY,
  TUYGUN_TIMEOUT,
}
TUYGUN_StatusTypeDef;

//***********************************
// TUYGUN Handle Struct
//***********************************
typedef struct __TUYGUN_HandleTypeDef
{
  uint16_t	PWM_In_Throttle;
  uint16_t	PWM_In_Aileron;
  uint16_t	PWM_In_Elevator;
  uint16_t	PWM_In_Rudder;
  uint16_t	PWM_In_Drop;
  uint16_t	PWM_In_Flap;
  uint16_t	PWM_In_Reverse;
}TUYGUN_HandleTypeDef;

//***********************************
//Functions for TUYGUN
//***********************************
TUYGUN_StatusTypeDef TUYGUN_setup_pin(struct __TUYGUN_HandleTypeDef *TUYGUN);
TUYGUN_StatusTypeDef TUYGUN_PWM_Read(struct __TUYGUN_HandleTypeDef *TUYGUN);
#endif 
