/*
 * 
This sketch is designed to run with the three LED lights
illuminating inside a cylinder of frosted Mylar paper. 

The code is modified from Nisha Pathak's Mini Glacier project, as it 
is documented at:
http://blogs.ischool.berkeley.edu/i262/category/labs/lab02/

*/

char serInString[100]; // array that will hold the different bytes of the string. 100=100characters;
// -> you must state how long the array will be else it won’t work properly
char colorCode;
int colorVal;

int redVal;
int greenVal;
int blueVal;

int redPin = 11; // Red LED, connected to digital pin 11
int greenPin = 10; // Green LED, connected to digital pin 10
int bluePin = 9; // Blue LED, connected to digital pin 9

void setup() 
{
pinMode(redPin, OUTPUT); // sets the pins as output
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
Serial.begin(9600);
analogWrite(redPin, 0); // set initial brightness to 0
analogWrite(greenPin, 0); // set initial brightness to 0
analogWrite(bluePin, 0); // set initial brightness to 0
Serial.println("Enter color values using 'r', 'b', or 'g' letters, each of which adds another 1/3 of brightness.");
Serial.println("For example, try mixing colors like yellow by using ‘rrrggg’.");
}

void loop () 
{
// clear the string
memset(serInString, 0, 100);
//read the serial port and create a string out of what you read
readSerialString(serInString);

// initialize all back to zero for each loop
redVal = 0;
greenVal = 0;
blueVal = 0;

colorCode = serInString[0];
if( colorCode == 'r' || colorCode == 'g' || colorCode == 'b') 
{
// increment each color according to the combination of letters the user entered
for (int i = 0; i < strlen(serInString); i++) 
{
  switch(serInString[i]) 
  {
    case 'r':
      redVal += 85;
      break;
    case 'g':
      greenVal += 85;
      break;
    case 'b':
      blueVal += 85;
      break;
  }
}

Serial.print("Setting color ");
Serial.println();
Serial.print("red to ");
Serial.print(redVal);
Serial.println();
Serial.print("green to ");
Serial.print(greenVal);
Serial.println();
Serial.print("blue to ");
Serial.print(blueVal);
Serial.println();
serInString[0] = 0; // indicates we’ve used this string
analogWrite(redPin, redVal);
analogWrite(greenPin, greenVal);
analogWrite(bluePin, blueVal);
}
delay(100); // wait a bit, for serial data
}
//read a string from the serial and store it in an array
//you must supply the array variable
void readSerialString (char *strArray) {
int i = 0;
if(!Serial.available()) {
return;
}
while (Serial.available()) {
strArray[i] = Serial.read();
i++;
}
}
