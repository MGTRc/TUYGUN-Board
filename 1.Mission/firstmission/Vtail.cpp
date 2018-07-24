#include "Vtail.h"
#include  <math.h>

Vtail_StatusTypeDef Vtail_Start(struct __PWM_IN_HandleTypeDef *PWM_In){
 PWM_In->PWM_In_Elevator = PWM_Vtail_Elevator ;
 PWM_In->PWM_In_Rudder = PWM_Vtail_Rudder ;
 // Word dosyasında 3 adet giriş olduğunu söyledim. Ancak okumaya zahmet göstermemissiniz.
 
  return Vtail_OK;
}

//Bu kısım komple yanlış. Word'de nasıl fonksiyonun oluşturulduğuna dikkatlı bir şekilde bakınız.
// Spoiler kısmı ise, pixhawkdan gelen AUX kanalı okumanız gerekiyor. Eğer bu değer 1500 altında ise normal V-tail matematiği çalışırken
// 1500 üstende ise maximum konumda çalıştırılacak. Örneğini Yunus ile yapmıştık.
// Burada 0.25 çarpanı Vtail_Setup fonksiyonundan istendiği zaman değiştirebilmelidir. -> PDF'e yazılmış bir ibare!!!!
Vtail_StatusTypeDef Vtail_Start(struct __PWM_OUT_HandleTypeDef *PWM_Out){
 
if (PWM_Vtail_Elevator!=1500){
  fabs(PWM_Vtail_Elevator-1500)*0.25=Result;  
  Vtail_Right=1500-Result;
  Vtail_Left=1500+Result;
}
else if(PWM_Vtail_Rudder!=1500){
  fabs(PWM_Vtail_Rudder-1500)*0.25=Result;
  Vtail_Right=1500+Result;
  Vtail_Left=1500+Result;         
}

    return Vtail_OK;
}





