#include <Servo.h>

//GLOBAL VARIABLES
  //SERVO OBJECT
    Servo lightServo;
  //SERVO POSITION
    int pos1;
    const int littlestep(15);
    const int bigstep(30);
  //PINS
    const int lightPin = 0; 
    const int servoPin = 9;
    double lightLevel, lightLevel2, lightLevel3;

//SETUP FUNCTION
  void setup()
  {
    //INITIALIZE SERVO OBJECTS
    initialize();
   //GREETING AND CALIBRATION
    update();
    greeting();
    calibrate(); 
  }

//LOOP FUNCTION
  void loop()
  {
   twitch();
   check();
   trace();
  }

  void greeting()
  {
   lightServo.write(pos1);
   Serial.print("Greetings");
   Serial.println();
   Serial.print("Current light level is:");
   Serial.print(lightLevel);
   Serial.println();
   Serial.print("Current position is:");
   Serial.print(pos1);
   Serial.println();
   delay(5000);
  }

  void calibrate()
  {
   Serial.print("Calibrating...");
   Serial.println();
   Serial.print("Testing 0");
   Serial.println();
   //SERVO CALIBRATION
   lightServo.write(0);
   delay(5000);
   Serial.print("Testing 180");
   lightServo.write(180);
   delay(5000);
  }

  void initialize()
  {
    //ATTACH LIGHTSERVO
    lightServo.attach(servoPin);
    //INITIALIZE SERIAL @ 9600
    Serial.begin(9600);
  }  
  void update()
  {
   //READ LIGHT LEVEL FROM PHOTORESISTOR
    lightLevel = analogRead(lightPin);                                       
    //MAP TAKES HIGH AND LOW INPUT VALUES FROM THE PHOTORESISTOR AND MAPS THEM TO A SCALE OF 0-180
    pos1 = map(lightLevel, 0, 900 , 0 , 180); 
    //CONSTRAIN VALUES FOR SERVO OPERATION
    pos1 = constrain(pos1, 0, 180);  
  }

  void trace()
  {
   Serial.println();
   Serial.print("Light:"); 
   Serial.print(lightLevel);
   Serial.println();
   Serial.print("Position:");
   Serial.print(pos1);
   Serial.println();
  }
  void twitch()
  {
    lightServo.write(pos1-littlestep);
    delay(1000);
    lightLevel = analogRead(lightPin);
    lightServo.write(pos1);
    delay(1000);
    lightLevel2 = analogRead(lightPin);
    lightServo.write(pos1+littlestep);
    delay(1000);
    lightLevel3 = analogRead(lightPin);
    lightServo.write(pos1);
  }
  void check()
  {
   if (lightLevel > lightLevel3 && lightLevel > lightLevel2 )
   {
     pos1 += bigstep;
     lightServo.write(pos1);
   }
   else if (lightLevel3 > lightLevel && lightLevel3 > lightLevel2)
   {
     pos1 -= bigstep;
     lightServo.write(pos1);
   }
  }
