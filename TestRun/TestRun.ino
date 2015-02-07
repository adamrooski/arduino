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
    double sensor1, sensor2, sensor3, sensor4;

//SETUP FUNCTION
  void setup()
  {
    //INITIALIZE SERVO OBJECTS
    initialize();
   //GREETING AND CALIBRATION
    calibrate();
    greeting();  
  }

//LOOP FUNCTION
  void loop()
  {
   panTwitch();
   panCheck();
   tiltTwitch();
   tiltCheck();
   trace();
  }

  void greeting()
  {
   panServo.write(panPos);
   Serial.print("Greetings");
   Serial.println();
   Serial.print("Current light level is:");
   Serial.print(sensor1);
   Serial.println();
   Serial.print("Current position is:");
   Serial.print(panPos);
   Serial.println();
   delay(5000);
  }

  //SERVO CALIBRATION
  void calibrate()
  {
   Serial.print("Calibrating...");
   Serial.println();
   Serial.print("Testing 0");
   Serial.println();
   panPos = 0;
   tiltPos = 0;
   panServo.write(panPos);
   tiltServo.write(tiltPos);
   delay(5000);
   Serial.print("Testing 180");
   Serial.println();
   panPos = 180;
   tiltPos = 180;
   panServo.write(panPos);
   tiltServo.write(tiltPos);
   delay(5000);
   Serial.print("Testing 90");
   panPos = 90;
   tiltPos = 90;
   panServo.write(panPos);
   tiltServo.write(tiltPos);
   delay(5000);
  }

  void initialize()
  {
    //ATTACH PAN AND TILT SERVOS
    panServo.attach(panPin);
    tiltServo.attach(tiltPin);
    
    //INITIALIZE SERIAL @ 9600
    Serial.begin(9600);
  }  
 /* void update()
  {
   //READ LIGHT LEVEL FROM PHOTORESISTOR
    sensor1 = analogRead(lightPin);                                       
    //MAP TAKES HIGH AND LOW INPUT VALUES FROM THE PHOTORESISTOR AND MAPS THEM TO A SCALE OF 0-180
    panPos = map(sensor1, 0, 900 , 0 , 180); 
    //CONSTRAIN VALUES FOR SERVO OPERATION
    panPos = constrain(panPos, 0, 180);  
  }*/

  void trace()
  {
   Serial.println();
   Serial.print("Light:"); 
   Serial.print(sensor1);
   Serial.println();
   Serial.print("Pan Position:");
   Serial.print(panPos);
   Serial.println();
   Serial.print("Tilt Position:");
   Serial.print(tiltPos);
   Serial.println();
  }
  void panTwitch()
  {
    sensor1 = analogRead(lightPin);   
    panServo.write(panPos + littlestep);  
    delay(200);   
    sensor2 = analogRead(lightPin);  
    panServo.write(panPos);
    delay(200);
  }
  void tiltTwitch()
  {
    sensor3 = analogRead(lightPin);
    tiltServo.write(tiltPos + littlestep);
    delay(200); 
    sensor4 = analogRead(lightPin);
    tiltServo.write(tiltPos);
    delay(200);
  }
  void panCheck()
  {
   if (sensor1 > sensor2 )
   {
     if (panPos >= 170)
     {
      panPos = 15;
      panServo.write(panPos); 
     }
     else
     {
     panPos += bigstep;
     panServo.write(panPos);
     }
   }
   else if (sensor1 < sensor2)
   {
     if (panPos <= 10)
     {
      panPos = 165;
      panServo.write(panPos); 
     }
     else
     {
     panPos -= bigstep;
     panServo.write(panPos);
     }
   }
  }
  
  void tiltCheck()
  {
   if (sensor3 > sensor4 )
   {
     if (tiltPos >= 170)
     {
      tiltPos = 15;
      tiltServo.write(tiltPos);
     }
     else
     {
     tiltPos += bigstep;
     tiltServo.write(tiltPos);
     }
   }
   else if (sensor3 < sensor4)
   {
     if (tiltPos <=10)
     {
      tiltPos = 165;
      tiltServo.write(tiltPos);
     }
     else
     {
     tiltPos -= bigstep;
     tiltServo.write(tiltPos);
     }
   }
  }
