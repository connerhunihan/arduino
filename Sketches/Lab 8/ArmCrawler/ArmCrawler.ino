/*
Conner Hunihan
Gabe Nicholas 

Crawler Arm
Tangible User Interface
UC Berkeley School of Information
Fall 2017

adapted from "http://itp.nyu.edu/physcomp/Labs/Servo"
Shout out to StackOverflow for the getValue() help
https://arduino.stackexchange.com/questions/1013/how-do-i-split-an-incoming-string
 */
 
#include <Servo.h>

int servoPin1 = 7; // pin for the servo motor
int servoPin2 = 8; // pin for the servo motor

Servo myservo1;    // create servo object to control a servo
Servo myservo2;    // create servo object to control a servo
int pos1;     // the position we want to move servo1 to
int pos2;     // the position we want to move servo2 to

String val;          // variable used to store data from serial port

void setup() {
  myservo1.attach(servoPin1); // attaches the servo on pin servoPin to the servo object
  myservo2.attach(servoPin2); // attaches the servo on pin servoPin to the servo object
  Serial.begin(9600);
  Serial.println("Servo control program ready");
}

// Shout out to StackOverflow for this one
// https://arduino.stackexchange.com/questions/1013/how-do-i-split-an-incoming-string
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}


void loop() {
  movement();
//  debug();
}

void movement() {
  int up[] = {70, 58};
  int extend[] = {20, 90};
  int pull[] = {48, 180};

  int i = 0;
  int delayVal = 100;
  while (true) {
    if (i == 0) {
      myservo2.write(up[1]);
      delay(delayVal);
      myservo1.write(up[0]);
    } else if (i == 1) {
      myservo2.write(extend[1]);
      delay(delayVal);
      myservo1.write(extend[0]);
    } else if (i == 2) {
      myservo2.write(pull[1]);
      delay(delayVal);
      myservo1.write(pull[0]);
    }
    i = (i+1)%3;
    delay(1000);
  }

  
}


void debug() {
   while (Serial.available()) {
    val = Serial.readString();
    if (val != "" ) {
      Serial.println();Serial.println();

      pos1 = getValue(val, '.', 0).toInt();
      pos2 = getValue(val, '.', 1).toInt();
      Serial.print("pos1 = ");Serial.println(pos1);
      Serial.print("pos2 = ");Serial.println(pos2);

      // tell the servo to go to the position
      myservo2.write(pos2);
      myservo1.write(pos1);

      // wait a few milliseconds so we don't overload the servo with too many commands all at once
      delay(15); 
    }
  } 
}


