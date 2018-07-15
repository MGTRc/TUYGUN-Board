#include "PWM_IN.h"
#include "PWM_OUT.h"

TUYGUN_HandleTypeDef TUYGUN;   //PWM_IN_HandleTypeDef PWM_IN şekilde olması gerekiyor. Bir kişi ana sayfaya baktığı zaman bunun ne işe yaradığını anlamaz.
TUYGUN_HandleTypeDef1 TUYGUN1; //PWM_OUT_HandleTypeDef PWM_OUT şeklinde olması gerekiyor.
                               //Yanına 1 yazarak kolaya kaçmayın!!!!!
void setup() {
Serial.begin(9600);
}

void loop() {
  TUYGUN_PWM_Read(&TUYGUN);
  Serial.print("Throttle:");
  Serial.println(TUYGUN.PWM_In_Throttle);
  Serial.print("Aileron:");
  Serial.println(TUYGUN.PWM_In_Aileron);
  Serial.print("Elevator:");
  Serial.println(TUYGUN.PWM_In_Elevator);
  Serial.print("Rudder:");
  Serial.println(TUYGUN.PWM_In_Rudder);
  
TUYGUN_PWM_Write(&TUYGUN1);
TUYGUN1.servo1.writeMicroseconds (500); // writeMicroseconds Servo kütüphanesi ait bir özelliktir. Mainde kullanılmaması gerekiyor.
                                        // Bunun PWM_Write fonksiyonu içerisinde gerçekleşmesi gerekiyor.
                                        // PWM_OUT.PWM_Out_Throttle = 1500; yazdığımız zaman servoya sonuç ulaşmalıdır.
                                        // Bundan dolayı deger atamaları yapıldıktan sonra PWM_Write fonksiyonu ile servolara sinyal yollanmalıdır.
}
