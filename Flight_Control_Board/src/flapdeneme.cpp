#include "../lib/Servo/src/Servo.h"

Servo myservo;

void setup()
{
  myservo.attach(9);
  myservo.writeMicroseconds(1500);  // set servo to mid-point
}

void loop() {}