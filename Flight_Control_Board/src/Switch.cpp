#include "../lib/Switch.h"


Switch_StatusTypeDef Switch_Setup(struct __Switch_HandleTypeDef *Switch){
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  digitalWrite(22, HIGH);
  digitalWrite(23, LOW);
return Switch_OK;
};

Switch_StatusTypeDef Switch_Write(struct __Switch_HandleTypeDef *Switch,
struct __PWM_IN_HandleTypeDef *PWM_IN,struct __PWM_OUT_HandleTypeDef *PWM_OUT){

  Switch->Switchx = PWM_IN -> PWM_AUX_3;
Serial.println(PWM_IN -> PWM_AUX_3);
if (Switch->Switchx>1500) {
  digitalWrite(22, LOW);
  digitalWrite(23, HIGH);
  PWM_OUT->PWM_VTail_Left = 1234 ;
}
else {
  digitalWrite(22, HIGH);
  digitalWrite(23, LOW);

}

return Switch_OK;
};
