#ifndef PWM_IN
#define PWM_IN
//TUYGUN Pin Configuration 

#include <Arduino.h>

#define Throttle (A2) // Throttle read pin Arduino (A2)
#define Aileron (A3) //Aileron read pin Arduino (A3)
#define Elevator (A4) //Elevator read pin Arduino (A4)
#define Rudder (A5) //Rudder read pin Arduino (A5)
#define Shot (A6) //Shot read pin Arduino (A6)
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
  uint16_t	TUYGUN_Throttle;
  uint16_t	TUYGUN_Aileron;
  uint16_t	TUYGUN_Elevator;
  uint16_t	TUYGUN_Rudder;
  uint16_t	TUYGUN_Shot;
  uint16_t	TUYGUN_Flap;
  uint16_t	TUYGUN_Reverse;
}TUYGUN_HandleTypeDef;

//***********************************
//Functions for TUYGUN
//***********************************
TUYGUN_StatusTypeDef TUYGUN_setup_pin(struct __TUYGUN_HandleTypeDef *TUYGUN);
#endif 
