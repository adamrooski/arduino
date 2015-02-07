#include <Servo.h>

//GLOBAL VARIABLES
  //SERVO OBJECT
    Servo panServo;
    Servo tiltServo;
  //SERVO POSITION
    int panPos, tiltPos;
    const int littlestep(5);
    const int bigstep(10);
  //PINS
    const int lightPin = 0; 
    const int panPin = 9;
    const int tiltPin = 3;
  //DATA
    int lightData[181];
    
void setup()
{
  
}


void loop()
{
  
}

void initialize()
{
  //ATTACH PAN AND TILT SERVOS
  panServo.attach(panPin);
  tiltServo.attach(tiltPin);
  
  //INITIALIZE SERIAL @ 9600
  Serial.begin(9600);
}  

void scan()
{
 panPos = 0;
 tiltPos = 30;
 panServo.write(panPos);
 tiltServo.write(tiltPos);
 for ( panPos = 0; panPos <= 180; panPos++)
 {
  
 
 }


