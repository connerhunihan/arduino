/* S
RACECAR
Conner Hunihan

adapted from 
https://www.arduino.cc/en/Tutorial/Knob
and
https://bcourses.berkeley.edu/courses/1464145/assignments/7819014
 */
 
#include <Servo.h>
Servo myservo;  // create servo object to control a servo

int motorPin = 11;
int motor_potPin = A1;
int motor_potVal;
int motorCtrlVal;

int steering_PotPin = A0;
int steering_potVal;

void setup() 
{
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
  pinMode(motor_potPin, INPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  // Motor code
  motor_potVal = analogRead(motor_potPin);
  Serial.print("motor_potVal: ");Serial.println(motor_potVal);
  motorCtrlVal = map(motor_potVal, 0, 1024, 0, 255);
  Serial.print("motorCtrlVal: ");Serial.println(motorCtrlVal);
  analogWrite(motorPin, motorCtrlVal);
  
  // Servo code
  steering_potVal = analogRead(steering_PotPin);            // reads the value of the potentiometer (value between 0 and 1023)
  steering_potVal = map(steering_potVal, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(steering_potVal);                  // sets the servo position according to the scaled value
  Serial.print("steering_potVal: "); Serial.println(steering_potVal);
  delay(15);
}
