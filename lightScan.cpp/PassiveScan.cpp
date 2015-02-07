//File Name: PassiveScan.cpp
//Authors: Adam Mejia
//Email: adamrooski@gmail.com
//Description: This program takes light level readings at 32,761 points in space and streams data to the serial port for processing.
//Last Modified: 12/05/2014


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
//SETUP FUNCTION
  void setup()
  {
    //INITIALIZE SERVO OBJECTS
    initialize();
   //SCAN
    scan();
  }
  
  void loop()
  {
  ;
  }
  
    void initialize()
  {
    //INITIALIZE SERIAL @ 9600
    Serial.begin(9600);
    //ATTACH PAN AND TILT SERVOS
    pinMode(panPin, OUTPUT);
    pinMode(tiltPin, OUTPUT);
    pinMode(lightPin, INPUT);
    panServo.attach(panPin);
    tiltServo.attach(tiltPin);
  }  
  
  void scan()
  {
   delay(5000);
   panPos = 0;
   tiltPos = 0;
   panServo.write(panPos);
   tiltServo.write(tiltPos);
   for (panPos = 0; panPos <= 180; panPos++)
   {
      panServo.write(panPos);
      delay(500);
      for (tiltPos = 0; tiltPos <= 180; tiltPos++)
       {
          tiltServo.write(tiltPos);
          delay(100);
          Serial.print(analogRead(lightPin));
          Serial.println();
       } 
   }
   
  }


