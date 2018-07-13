#ifndef _PWM_OUT
#define _PWN_OUT


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
// #define servo1 //  buraya servoyu Tanımladığımızda ise daha ilginç bir hata veriyor onun çözümünü de bulamadık.
  


//***********************************
// TUYGUN Software Status Definitions          			        
//***********************************

typedef enum TUYGUN_StatusTypeDef1
{
  TUYGUN_ERROR1,
  TUYGUN_OK1,
  TUYGUN_BUSY1,
  TUYGUN_TIMEOUT1,
}
TUYGUN_StatusTypeDef1;

//***********************************
// TUYGUN Handle Struct
//***********************************
typedef struct __TUYGUN_HandleTypeDef1
{
  uint16_t	PWM_Out_Throttle;
  uint16_t	PWM_Out_Aileron1;
  uint16_t	PWM_Out_Aileron2;
  uint16_t	PWM_Out_Elevator1;
  uint16_t	PWM_Out_Elevator2;
  uint16_t  PWM_Out_Rudder;
  uint16_t	PWM_Out_Drop1;
  uint16_t	PWM_Out_Drop2;
  uint16_t	PWM_Out_Flap1;
  uint16_t	PWM_Out_Flap2;
  
 Servo servo1;
 Servo servo2;
 Servo servo3;
 Servo servo4;
 Servo servo5;
 Servo servo6;
 Servo servo7;
 Servo servo8;
 Servo servo9;
 Servo servo10;
  
 
  

}TUYGUN_HandleTypeDef1;

//***********************************
//Functions for TUYGUN
//***********************************
TUYGUN_StatusTypeDef1 TUYGUN_Setup_Pin(struct __TUYGUN_HandleTypeDef1 *TUYGUN1);
TUYGUN_StatusTypeDef1 TUYGUN_PWM_Write(struct __TUYGUN_HandleTypeDef1 *TUYGUN1);



#endif
