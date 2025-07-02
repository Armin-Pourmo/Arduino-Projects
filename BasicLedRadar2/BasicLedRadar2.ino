#include <Servo.h>
#include <NewPing.h>

#define TRIG_PIN 12
#define ECHO_PIN 13
#define MAX_DISTANCE 20

const int leftLight=5;
const int forwardLight=6;
const int rightLight=11;
const int SERVOPIN = 2;




int turnPoint=0;
unsigned int distMapper = 0;

NewPing RWR(TRIG_PIN,ECHO_PIN,MAX_DISTANCE);
Servo Myservo;

void setup() {
Myservo.attach(SERVOPIN);
Myservo.write(0);
pinMode(leftLight,OUTPUT);
pinMode(forwardLight,OUTPUT);
pinMode(rightLight,OUTPUT);

}

void loop() {
  for (int turnPoint=0;turnPoint<61;turnPoint+=10)
{
  distMapper = RWR.ping_cm();
  if (distMapper > 0) {
  analogWrite(leftLight, map(distMapper, 0, MAX_DISTANCE, 255, 0));
} else {
  analogWrite(leftLight, 0);  // or some default value
}

  Myservo.write(turnPoint);
  delay(300);
}
  for (int turnPoint=61;turnPoint<121;turnPoint+=10)
{
  distMapper = RWR.ping_cm();
  if (distMapper > 0) {
  analogWrite(forwardLight, map(distMapper, 0, MAX_DISTANCE, 255, 0));
} else {
  analogWrite(forwardLight, 0);  // or some default value
}
  Myservo.write(turnPoint);
    delay(300);
}
  for (int turnPoint=121;turnPoint<181;turnPoint+=10)
{
  distMapper = RWR.ping_cm();
  if (distMapper > 0) {
  analogWrite(rightLight, map(distMapper, 0, MAX_DISTANCE, 255, 0));
} else {
  analogWrite(rightLight, 0);  // or some default value
}
  Myservo.write(turnPoint);
    delay(300);
  }
  turnPoint=0;
  delay(50);

  
  
}
