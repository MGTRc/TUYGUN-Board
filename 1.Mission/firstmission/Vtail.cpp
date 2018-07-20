#include "Vtail.h"
#include  <math.h>


Vtail_StatusTypeDef PWM_OUT_Vtail_Setup(struct __Vtail_HandleTypeDef *Vtail){
  
  uint16_t PWM_Vtail_Elevator;
  uint16_t PWM_Vtail_Aileron;
  int stabil_durum=1500;
  int gelen_deger,sonuc;
 
  PWM_In->PWM_In_Elevator = PWM_Vtail_Elevator ;
  PWM_In->PWM_In_Aileron = PWM_Vtail_Aileron ;
  
  
if (stabil_durum==PWM_In_Elevator && stabil_durum==PWM_In_Aileron){
  fabs(PWM_Vtail_Elevator-1500)*0.25=Sonuc;  
  PWM_Vtail_Elevator=1500-sonuc;
  PWM_Vtail_Aileron=1500+sonuc;
}

    return Vtail_OK
}

