#include "../lib/PWM_OUT.h"
#include "../lib/Servo/src/Servo.h"

PWM_OUT_StatusTypeDef PWM_OUT_Setup(struct __PWM_OUT_HandleTypeDef *PWM_OUT){

  //Ailerons
  PWM_OUT->Aileron_Left.attach(Aileron_Left_OUT);
  PWM_OUT->Aileron_Right.attach(Aileron_Right_OUT);
  //V-Tail
  PWM_OUT->Vtail_Left.attach(VTail_Left_OUT);
  PWM_OUT->Vtail_Right.attach(VTail_Right_OUT);
  //Flaps
  PWM_OUT->Flap_Left.attach(Flap_Left_OUT);
  PWM_OUT->Flap_Right.attach(Flap_Right_OUT);
  //Others
  PWM_OUT->Throttle.attach(Throttle_OUT);
  PWM_OUT->Landing_Gear.attach(Landing_Gear_OUT);
  PWM_OUT->Cover_1.attach(Cover_1_OUT);
  PWM_OUT->Cover_2.attach(Cover_2_OUT);

  return PWM_OUT_OK;
};

PWM_OUT_StatusTypeDef PWM_OUT_Write(struct __PWM_OUT_HandleTypeDef *PWM_OUT){
  for(int o=2; o > 0; o--){

       PWM_OUT-> ErrayTemp_1[o-1] = PWM_OUT->ErrayDist_1[o];
       PWM_OUT-> ErrayTemp_2[o-1] = PWM_OUT->ErrayDist_2[o];
       }

  PWM_OUT->ErrayDist_1[2]=PWM_OUT->PWM_VTail_Left;
  PWM_OUT->ErrayDist_2[2]=PWM_OUT->PWM_VTail_Right;

   for(int p=1; p >= 0; p--){

       PWM_OUT->ErrayDist_1[p]=PWM_OUT->ErrayTemp_1[p];
       PWM_OUT->ErrayDist_2[p]=PWM_OUT->ErrayTemp_2[p];
       }

  PWM_OUT->PWM_VTail_Left =
      (uint16_t)(PWM_OUT->ErrayDist_1[2]*0.33  + PWM_OUT->ErrayDist_1[1]*0.33 + PWM_OUT->ErrayDist_1[0]*0.33);
  PWM_OUT->PWM_VTail_Right =
      (uint16_t)(PWM_OUT->ErrayDist_2[2]*0.33  + PWM_OUT->ErrayDist_2[1]*0.33 + PWM_OUT->ErrayDist_2[0]*0.33);
  //Ailerons
  PWM_OUT->Aileron_Left.writeMicroseconds(PWM_OUT->PWM_Aileron_Left);
  PWM_OUT->Aileron_Right.writeMicroseconds(PWM_OUT->PWM_Aileron_Right);
  //V-Tail
  PWM_OUT->Vtail_Left.writeMicroseconds(PWM_OUT->PWM_VTail_Left);
  PWM_OUT->Vtail_Right.writeMicroseconds(PWM_OUT->PWM_VTail_Right);
  //Flaps
  PWM_OUT->Flap_Left.writeMicroseconds(PWM_OUT->PWM_Flap_Left);
  PWM_OUT->Flap_Right.writeMicroseconds(PWM_OUT->PWM_Flap_Right);
  //Others
  PWM_OUT->Throttle.writeMicroseconds(PWM_OUT->PWM_Throttle);
  PWM_OUT->Landing_Gear.writeMicroseconds(PWM_OUT->PWM_Landing_Gear);
  PWM_OUT->Cover_1.writeMicroseconds(PWM_OUT->PWM_Cover_1);
  PWM_OUT->Cover_2.writeMicroseconds(PWM_OUT->PWM_Cover_2);
  return PWM_OUT_OK;

};

PWM_OUT_StatusTypeDef PWM_OUT_Default_Values(struct __PWM_OUT_HandleTypeDef *PWM_OUT){
  PWM_OUT->PWM_Aileron_Left   = 1500;
  PWM_OUT->PWM_Aileron_Right  = 1500;
  PWM_OUT->PWM_VTail_Left     = 1500;
  PWM_OUT->PWM_VTail_Right    = 1500;
  PWM_OUT->PWM_Throttle       = 1000;
  PWM_OUT->PWM_Flap_Left      = 1000;
  PWM_OUT->PWM_Flap_Right     = 1000;
  PWM_OUT->PWM_Landing_Gear   = 1500;
  PWM_OUT->PWM_Cover_1        = 1500;
  PWM_OUT->PWM_Cover_2        = 1500;
  return PWM_OUT_OK;
};
