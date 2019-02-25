#include <Servo.h>

Servo FL_HIP; 
Servo FL_FOOT;
Servo FR_HIP;
Servo FR_FOOT;
Servo BL_HIP; 
Servo BL_FOOT;
Servo BR_HIP;
Servo BR_FOOT;

Servo armShoulder;
Servo armElbow;
Servo armWrist;
Servo armFist;

const int trigPin = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor

void setup() { 
  FL_HIP.attach(4); 
  FL_FOOT.attach(5);
  FR_HIP.attach(6);
  FR_FOOT.attach(7);
  BL_HIP.attach(8);
  BL_FOOT.attach(9);
  BR_HIP.attach(10);
  BR_FOOT.attach(11);

  armShoulder.attach(3);
  armElbow.attach(2);
  armWrist.attach(1);
  armFist.attach(0);
  
  homePos();

  homePosArm();
}

void loop() 
{
  grabHorizontalFront();
  delay(1000);
  homePosArm();
  delay(1000);
  grabHorizontalBack();
  delay(1000);
  homePosArm();
  delay(1000);
  
//  int distance = getDistance();
//  homePosArm();
//  if(distance < 6)
//  {
//    turnLeft();
//    int leftDistance = getDistance();
//    delay(500);
//    for(int i = 0; i <= 1; i++){
//      turnRight();
//    }
//    int rightDistance = getDistance();
//    if(leftDistance > rightDistance)
//    {
//      for(int i = 0; i <= 4; i++)
//      {
//        turnLeft();
//        grabHorizontalFront();
//      }
//    }
//    else
//    {
//      for(int i = 0; i <= 3; i++)
//      {
//        turnRight();
//        grabHorizontalFront();
//      }
//    }
//  }
//  else
//  {
//    walkForward();
//  }
} 

void leanDemo()
{
  leanLeft();
  delay(1000);
  homePos();
  delay(1000);
  leanRight();
  delay(1000);
  homePos();
  delay(1000);
}

void leanRight()
{
 FL_FOOT.write(15);
 FR_FOOT.write(15);
 BL_FOOT.write(140);
 BR_FOOT.write(140);
}

void leanLeft()
{
 FL_FOOT.write(140);
 FR_FOOT.write(140);
 BL_FOOT.write(15);
 BR_FOOT.write(15);
}

void homePos()
{
 FL_HIP.write(40);
 FL_FOOT.write(110);
 FR_HIP.write(130);
 FR_FOOT.write(70);
 BL_HIP.write(130);
 BL_FOOT.write(70);
 BR_HIP.write(40);
 BR_FOOT.write(110);
}

void bow()
{
 FL_FOOT.write(140);
 FR_FOOT.write(15);
 BL_FOOT.write(130);
 BR_FOOT.write(30);
}

void turnLeft()
{
  // Front left and back right leg
  // raises the foot in air
  FL_FOOT.write(130);
  BR_FOOT.write(130);

  delay(200);

  // turns the hip around
  FL_HIP.write(0);
  BR_HIP.write(0);

  delay(200);

  // puts the foot down again
  FL_FOOT.write(110);
  BR_FOOT.write(110);

  delay(200);

  // puts the hip back in original place
  FL_HIP.write(40);
  BR_HIP.write(40);

  delay(200);

  // Front Right and Back Left Leg
  // raises the foot in air
  FR_FOOT.write(50);
  BL_FOOT.write(50);

  delay(200);

  // turns the hip around
  FR_HIP.write(180);
  BL_HIP.write(180);

  delay(200);

  // puts the foot down again
  FR_FOOT.write(70);
  BL_FOOT.write(70);

  delay(200);

  // puts the hip back in original place
  FR_HIP.write(130);
  BL_HIP.write(130);
}

void turnRight()
{
  // Front left and back right leg
  //raises the foot in air
  FL_FOOT.write(130);
  BR_FOOT.write(130);

  delay(200);

  // turns the hip around
  FL_HIP.write(10);
  BR_HIP.write(10);

  delay(200);

  // puts the foot down again
  FL_FOOT.write(110);
  BR_FOOT.write(110);

  delay(200);

  // puts the hip back in original place
  FL_HIP.write(40);
  BR_HIP.write(40);

  delay(200);

  // Front Right and Back Left Leg
  // raises the foot in air
  FR_FOOT.write(50);
  BL_FOOT.write(50);

  delay(200);

  // turns the hip around
  FR_HIP.write(80);
  BL_HIP.write(80);

  delay(200);

  // puts the foot down again
  FR_FOOT.write(70);
  BL_FOOT.write(70);

  delay(200);

  // puts the hip back in original place
  FR_HIP.write(130);
  BL_HIP.write(130);
}

void walkForward()
{ 
 FR_FOOT.write(50);
 BL_FOOT.write(50);

 delay(200);
  
 FR_HIP.write(150);
 BL_HIP.write(110);
 FL_HIP.write(60);
 BR_HIP.write(20);

 delay(200);

 FR_FOOT.write(70);
 BL_FOOT.write(70);

 delay(200);

 FL_FOOT.write(130);
 BR_FOOT.write(130);

 delay(200);

 FL_HIP.write(20);
 BR_HIP.write(60);
 FR_HIP.write(110);
 BL_HIP.write(150);

 delay(200);

 FL_FOOT.write(110);
 BR_FOOT.write(110);

 delay(200);
 
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

int getDistance()
{
   long duration, inches, cm;
   pinMode(trigPin, OUTPUT);
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
   return cm;
}

void homePosArm()
{
  homePos();
  armShoulder.write(160);
  armElbow.write(0);
  armWrist.write(90);
  armFist.write(0);
}

void grabHorizontalFront()
{
  bow();
  armFist.write(90);
  armShoulder.write(170);
  armElbow.write(130);
  armWrist.write(90);
  delay(1000);
  armFist.write(0);
  
}

void grabHorizontalBack()
{
  homePos();
  armShoulder.write(40);
  armElbow.write(0);
  armWrist.write(90);
  armFist.write(0);
}
