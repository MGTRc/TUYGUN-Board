#include <Arduino.h>
#include "../lib/PWM_IN.h"
#include "../lib/PWM_OUT.h"
#include "../lib/Ultrasonic.h"
#include "../lib/Flap.h"
#include "../lib/Vtail.h"
#include "../lib/Switch.h"
#include "../lib/Reverse.h"

PWM_IN_HandleTypeDef PWM_IN;
PWM_OUT_HandleTypeDef PWM_OUT;
Ultrasonic_HandleTypeDef Ultrasonic;
Flap_HandleTypeDef Flap;
Vtail_HandleTypeDef Vtail;
Switch_HandleTypeDef Switch;
Reverse_HandleTypeDef Reverse;

PWM Elevator(2);
PWM Rudder(3);
//PWM Aileron(19);
PWM Throttle(18);

void setup() {
    PWM_In_Setup(&PWM_IN);
    PWM_OUT_Setup(&PWM_OUT);
    //Ultrasonic_Setup(&Ultrasonic);
    Ultrasonic_Setup(&Ultrasonic);
    Switch_Setup(&Switch);
    //Flap_Setup(&Flap,&PWM_OUT);
    Vtail_Setup(&Vtail);
    Reverse_Setup(&Reverse);
    Elevator.begin(true);
    //Aileron.begin(true);
    Throttle.begin(true);
    Rudder.begin(true);
    Serial.begin(9600);
}

void loop() {
    PWM_IN_Read(&PWM_IN);  // Read PWM Values from PIXHAWK 2.4.8
    PWM_IN.PWM_Elevator = Elevator.getValue();
    PWM_IN.PWM_Rudder  = Rudder.getValue();
    //PWM_IN.PWM_Aileron = Aileron.getValue() ;
    //PWM_IN.PWM_Throttle =Throttle.getValue() ;

    //Vtail_Start(&Vtail,&PWM_OUT,&PWM_IN);
    PWM_IN.PWM_Throttle =Throttle.getValue() ;
    //PWM_IN.PWM_Rudder  = Rudder.getValue();

    //Vtail_Start(&Vtail,&PWM_OUT,&PWM_IN);
    //Switch_Write(&Switch,&PWM_IN,&PWM_OUT);
    //Ultrasonic_Start(&Ultrasonic,&PWM_IN, &PWM_OUT);
    //Flap_Start(&Flap,&PWM_OUT,&PWM_IN);
    Reverse_Start(&Reverse,&PWM_IN,&PWM_OUT);
    PWM_OUT_Write(&PWM_OUT);

}
