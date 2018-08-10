#include <SD.h>
#include <SPI.h>

File myFile;

int pinCS = 10; 
void setup() {
    
  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);
  
  // SD Card Initialization
  if (SD.begin())
    {
    Serial.println("SD card is ready to use.");
    } 
  
  else
    {
    Serial.println("SD card initialization failed");
    return;
    }
    
}
void loop() {
 
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) 
    {    
    myFile.println(Ultrasonic->Distance);
    myFile.close(); // close the file
    }
  // if the file didn't open, print an error:
  else 
    {
    Serial.println("error opening test.txt");
    }
  
}
