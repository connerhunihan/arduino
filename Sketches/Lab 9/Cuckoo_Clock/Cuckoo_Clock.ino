// TESTING DUCK WIGGLE
int duckPin = 8; // LED connected to digital pin 13
int testDuck;

void setup()
{
  pinMode(duckPin, OUTPUT);      // sets the digital pin as output
}

void loop()
{
  digitalWrite(duckPin, HIGH);   // sets the LED on
  delay(1000);                  // waits for a second
  digitalWrite(duckPin, LOW);    // sets the LED off
  delay(1000);                  // waits for a second
}

///*
//Conner Hunihan
//
// */
// 
//#include <Servo.h>
//
//int servoPin = 7; // pin for the servo motor
//int duckPin = 8;
//
//Servo myservo;    // create servo object to control a servo
//int pos;     // the position we want to move servo1 to
//int duck;
//
//int val;          // variable used to store data from serial port
//
//void setup() {
//  myservo.attach(servoPin); // attaches the servo on pin servoPin to the servo object
//  pinMode(duckPin, OUTPUT);
//  Serial.begin(9600);
//  Serial.println("Servo control program ready");
//}
//
//void loop() {
//  while (Serial.available()) {
//    val = Serial.read();
//    if (val >= '1' && val <= '9' ) {
//      Serial.println();Serial.println();
//      // interpret the user's input to get a number from 1 to 9
//      val = val - '0'; // convert val from character variable to number variable
//                       // (see http://forum.arduino.cc/index.php?topic=103511.0 for a forum discussing more about this)
//      Serial.print("val = ");Serial.println(val);
//      
//      // calculate the position that we should move the servo to
//      pos = map(val, 1, 9, 0, 180); // (see https://www.arduino.cc/en/Reference/Map)    
//      Serial.print("pos = ");Serial.println(pos);
//
//      if (val == '9'){
//        digitalWrite(duckPin, HIGH);
//      }
//      else if (val <= '8'){
//        digitalWrite(duckPin, LOW);
//      }
//      
//      // tell the servo to go to the position
//      myservo.write(pos);
//      // wait a few milliseconds so we don't overload the servo with too many commands all at once
//      delay(15);
//    }
//  }
//}
