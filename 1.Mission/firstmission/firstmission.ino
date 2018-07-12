#include "PWM_IN.h"
#include "PWM_OUT.h"

TUYGUN_HandleTypeDef TUYGUN;

void setup() {
Serial.begin(9600);
}

void loop() {
  TUYGUN_PWM_Read(&TUYGUN);
  Serial.print("Throttle:");
  Serial.println(TUYGUN.TUYGUN_Throttle);
  Serial.print("Aileron:");
  Serial.println(TUYGUN.TUYGUN_Aileron);
  Serial.print("Elevator:");
  Serial.println(TUYGUN.TUYGUN_Elevator);
  Serial.print("Rudder:");
  Serial.println(TUYGUN.TUYGUN_Rudder);
  
  TUYGUN_PWM_Write(&TUYGUN);
  TUYGUN.servo1.write (180);

    // bu kısmı anlamadık. Yukarıdaki read fonksiyonuna structı çağırdığımız gibi write fonksiyonu için de struct çağırmamız 
    //gerektiğini düşündük ama sen maine servo ile ilgili hiçbir şey olmasın dedin o yüzden birçok değişiklik yaptık kodda ama
    // hatasız derleyemedik sıkıntıyı çözemedik. Koddaki sıkıntıya bir de sen bakar mısın
  
}
