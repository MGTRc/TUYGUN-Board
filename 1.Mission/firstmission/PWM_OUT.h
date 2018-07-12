#ifndef _PWM_OUT
#define _PWN_OUT
#ifndef _Servo
#define _Servo

//TUYGUN Pin Configuration 

#include <Arduino.h>
#include <Servo.h>


#define Aileron1 (2)
#define Aileron2 (3)
#define Flap1    (4)
#define Flap2    (5)
#define Vtail1   (6) 
#define Vtail2   (7) 
#define Drop1    (8)
#define Drop2    (9)
#define Rudder1   (10) 
#define Throttle1 (11) 
#define servo1 //  buraya servoyu Tanımladığımızda ise daha ilginç bir hata veriyor onun çözümünü de bulamadık.
  


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
  uint16_t	TUYGUN_Aileron1;
  uint16_t	TUYGUN_Aileron2;
  uint16_t	TUYGUN_Elevator1;
  uint16_t	TUYGUN_Elevator2;
  uint16_t	TUYGUN_Rudder;
  uint16_t	TUYGUN_Drop1;
  uint16_t	TUYGUN_Drop2;
  uint16_t	TUYGUN_Flap1;
  uint16_t	TUYGUN_Flap2;
  
  Servo  servo1;
  Servo servo2;
  Servo servo3;
  Servo servo4;
  Servo servo5;
  Servo servo6;
  Servo servo7;
  Servo servo8;
  Servo servo9;
  Servo servo10;
  

}TUYGUN_HandleTypeDef;

//***********************************
//Functions for TUYGUN
//***********************************
TUYGUN_StatusTypeDef TUYGUN_Setup_Pin(struct __TUYGUN_HandleTypeDef *TUYGUN);
TUYGUN_StatusTypeDef TUYGUN_PWM_Write(struct __TUYGUN_HandleTypeDef *TUYGUN);




#endif
#endif
