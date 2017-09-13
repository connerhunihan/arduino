/* 
This sketch asks the user to input, via the Serial Monitor, both the color and fade amount of three LED lights.
Each color will continue to fade in and out until updated.  
 */

char serInString[100];  // array that will hold the different bytes of the string. 100=100characters;
                        // -> you must state how long the array will be else it won't work properly
char colorCode;
int fadeVal = 0;            // set amount that the brightness will change by 

// set the digital pins
int redPin   = 11;   
int greenPin = 10;  
int bluePin  = 9;  

// set the initial fade value for each color
int fadeGreen = 0;
int fadeBlue = 0;
int fadeRed = 0;

// set the initial brightness of each color
int brightnessGreen = 225;  
int brightnessBlue = 225;   
int brightnessRed = 225; 

void setup() {
  pinMode(redPin,   OUTPUT);   // sets the pins as output
  pinMode(greenPin, OUTPUT);   
  pinMode(bluePin,  OUTPUT);
  Serial.begin(9600);
  analogWrite(redPin,   brightnessRed);   // set them all to mid brightness
  analogWrite(greenPin, brightnessGreen);   // set them all to mid brightness
  analogWrite(bluePin,  brightnessBlue);   // set them all to mid brightness
  Serial.println("Enter color (r, g, b) followed by how much (0-25) you want the color to pulse (e.g. r10):");  
}

void loop () 
{
  // clear the string
  memset(serInString, 0, 100);
  //read the serial port and create a string out of what you read
  readSerialString(serInString);

// control red
  if (brightnessRed <= 0)
  {
    brightnessRed = 0;
    fadeRed = -fadeRed;
  }
  else if (brightnessRed >= 255) // set max range to multiple of fade amount 
  {
    brightnessRed = 255;
    fadeRed = -fadeRed;
  }
  analogWrite(redPin, brightnessRed);
  brightnessRed += fadeRed;

// control green
  if (brightnessGreen <= 0)
  {
    brightnessGreen = 0;
    fadeGreen = -fadeGreen;
  }
  else if (brightnessGreen >= 255) // set max range to multiple of fade amount 
  {
    brightnessGreen = 255;
    fadeGreen = -fadeGreen;
  }
  analogWrite(greenPin, brightnessGreen);
  brightnessGreen += fadeGreen;

// control blue
  if (brightnessBlue <= 0)
  {
    brightnessBlue = 0;
    fadeBlue = -fadeBlue;
  }
  else if (brightnessBlue >= 255) // set max range to multiple of fade amount 
  {
    brightnessBlue = 255;
    fadeBlue = -fadeBlue;
  }
  analogWrite(bluePin, brightnessBlue);
  brightnessBlue += fadeBlue;

  
  colorCode = serInString[0];
  if( colorCode == 'r' || colorCode == 'g' || colorCode == 'b' ) {
    fadeVal = atoi(serInString+1);
    Serial.print("setting ");
    Serial.print(colorCode);
    Serial.print(" to fade ");
    Serial.print(fadeVal);
    Serial.print(" amount.");
    Serial.println();
    serInString[0] = 0;                   // indicates we've used this string
    if(colorCode == 'r') 
      fadeRed = fadeVal;
    else if(colorCode == 'g')
      fadeGreen = fadeVal;
    else if(colorCode == 'b')
      fadeBlue = fadeVal;
  }
  
  delay(100);  // wait a bit, for serial data
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
