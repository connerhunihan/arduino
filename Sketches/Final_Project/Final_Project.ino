/* ==========================================================
Project : Photocell that turns light off, if competely covered
Author: ScottC
Created: 25th June 2011
Description: This sketch will make the arduino read Photo resistor
             values on analog pin A0. The analog readings will
             be dependent on the amount of light reaching the
             sensor. The Analog readings will be sent to the
             computer via the USB cable using Serial communication.
==============================================================
*/

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin

int maximumRange = 10; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int photoPin = A0; 
int lightLevel;

int led = 3;
int led2 = 5;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
 // trigPin/echoPin cycle is used to determine the
 // distance of the nearest object by bouncing soundwaves off of it.
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;

// if/else for the ultrasonic sensor to detect if an object is within range.  
// light turns on if object is within range
 if (distance >= maximumRange || distance <= minimumRange)
 {
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 // Serial.println("-1");
 digitalWrite(led2, LOW); 
 }
 else 
 {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 // Serial.println(distance);
 digitalWrite(led2, HIGH); 
 }

 // reading from photocell
 lightLevel=analogRead(photoPin);
 // Serial.println(lightLevel);

 // threshold for photocell sensitivity.  
 if (lightLevel > 30)
 {
  analogWrite(led, 255);
 }
 else
 {
  analogWrite(led, 0);
 }
}
