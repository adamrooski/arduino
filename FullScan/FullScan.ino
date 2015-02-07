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
  initialize();
}
//LOOP FUNCTION
void loop()
{
  
}

//INITIALIZE SERIAL AND ATTACH SERVOS TO PINS
void initialize()
{
  //ATTACH PAN AND TILT SERVOS
  panServo.attach(panPin);
  tiltServo.attach(tiltPin);  
  //INITIALIZE SERIAL @ 9600
  Serial.begin(9600);
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

void scan()
{
  int i, j;
  double
   panPos = 0;
   tiltPos = 0;
   panServo.write(panPos);
   tiltServo.write(tiltPos);
   for (i = 0; i <= 180; i++)
   {
      for (j = 0; j <=180; j++) 
      {
        analogRead(lightPin);
      }
   }
