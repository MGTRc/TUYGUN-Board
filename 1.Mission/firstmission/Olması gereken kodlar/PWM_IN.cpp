#include "../lib/PWM_IN.h"

PWM_IN_StatusTypeDef PWM_In_Setup(struct __PWM_IN_HandleTypeDef *PWM_IN){
  //Main Channels
  pinMode(Aileron_IN,INPUT);
  pinMode(Elevator_IN,INPUT);
  pinMode(Throttle_IN,INPUT);
  pinMode(Rudder_IN,INPUT);
  //Aux Channels
  pinMode(AUX_1_IN,INPUT);
  pinMode(AUX_2_IN,INPUT);
  pinMode(AUX_3_IN,INPUT);
  pinMode(AUX_4_IN,INPUT);
  return PWM_IN_OK;
};

PWM_IN_StatusTypeDef PWM_IN_Read(struct __PWM_IN_HandleTypeDef *PWM_IN){
  //Main Channels
  PWM_IN->PWM_Aileron   = pulseIn(Aileron_IN,HIGH);
  PWM_IN->PWM_Elevator  = pulseIn(Elevator_IN,HIGH);
  PWM_IN->PWM_Throttle  = pulseIn(Throttle_IN,HIGH);
  PWM_IN->PWM_Rudder    = pulseIn(Rudder_IN,HIGH);
  //Aux Channels
  PWM_IN->PWM_AUX_1 = pulseIn(AUX_1_IN,HIGH);
  PWM_IN->PWM_AUX_2 = pulseIn(AUX_2_IN,HIGH);
  PWM_IN->PWM_AUX_3 = pulseIn(AUX_3_IN,HIGH);
  PWM_IN->PWM_AUX_4 = pulseIn(AUX_4_IN,HIGH);
  return PWM_IN_OK;
};
