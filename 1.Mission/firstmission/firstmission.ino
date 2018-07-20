#include "PWM_IN.h"
#include "PWM_OUT.h"

PWM_IN_HandleTypeDef PWM_In;   
PWM_OUT_HandleTypeDef PWM_Out; 
                               
void setup() {
Serial.begin(9600);
}

void loop() {
  PWM_IN_PWM_Read(&PWM_In);
  Serial.print("Throttle:");
  Serial.println(PWM_In.PWM_In_Throttle);
  Serial.print("Aileron:");
  Serial.println(PWM_In.PWM_In_Aileron);
  Serial.print("Elevator:");
  Serial.println(PWM_In.PWM_In_Elevator);
  Serial.print("Rudder:");
  Serial.println(PWM_In.PWM_In_Rudder);
 
PWM_OUT_PWM_Write(&PWM_Out);
PWM_Out.Aileron_Left.writeMicroseconds (500); // PWM_ıWrite Çalşınca buda çalısıyor.

}
