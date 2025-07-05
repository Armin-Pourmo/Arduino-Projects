#define CUSTOM_SETTINGS

#define INCLUDE_TERMINAL_MODULE

#include <Dabble.h>
#include <SoftwareSerial.h>
#include<Servo.h>

Servo myServo;
SoftwareSerial mySerial(7,8);

int Baud_Rate = 9600;

String Message = "";

void setup() {
  Serial.begin(9600);
 myServo.attach(6);
mySerial.begin(9600);
Dabble.begin(mySerial);
myServo.write(0);
}

void loop() {
Dabble.processInput();

if (Terminal.available())
{
 String Message = Terminal.readString();
Message.trim();
 if (Message=="open")
 {
  myServo.write(180);
 }
 else if (Message=="close")
 {
  myServo.write(0);
 }
}

}
