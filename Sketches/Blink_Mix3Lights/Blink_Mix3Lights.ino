/*
  Color Mixzer
  Conner Hunihan

  This sketch allows the user to mix colors of light by changing 
  
  This sketch is a modification of the example code in the public domain at:
  http://www.arduino.cc/en/Tutorial/Blink

  Serial.print("brightnessGreen "); Serial.println(brightnessGreen);
  
*/
int greenLED = 10;          // set the ouput pins to color-coded variables
int blueLED = 9;
int redLED = 11;

// set the fade delta for each color
int fadeAmount_Green = 2;
int fadeAmount_Blue = 2;
int fadeAmount_Red = 2;

// set the initial brightness of each color
int brightnessGreen = 127.5;  
int brightnessBlue = 0;   
int brightnessRed = 255;   

// setup function to initialize led output 
void setup() 
{
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{  
  for (int x = 0; x < 1; x++) 
  {
    if (brightnessGreen <= 0) // reset brightness to minimum if value drops into negative range
    {
      brightnessGreen = 0;
      fadeAmount_Green = -fadeAmount_Green;
    }
    else if (brightnessGreen >= 255) // reset brightness to maximum if value drops above maximum range
    {
      brightnessGreen = 255;
      fadeAmount_Green = -fadeAmount_Green;
    }
    analogWrite(greenLED, brightnessGreen);
    brightnessGreen += fadeAmount_Green;
    
    Serial.print("brightnessGreen "); Serial.println(brightnessGreen);
  } 

  for (int y = 0; y < 1; y++) 
  {
    if (brightnessBlue <= 0)
    {
      brightnessBlue = 0;
      fadeAmount_Blue = -fadeAmount_Blue;
    }
    else if (brightnessBlue >= 255) // set max range to multiple of fade amount 
    {
      brightnessBlue = 255;
      fadeAmount_Blue = -fadeAmount_Blue;
    }
    analogWrite(blueLED, brightnessBlue);
    brightnessBlue += fadeAmount_Blue;
        
    // Serial.print("brightnessBlue "); Serial.println(brightnessBlue);
  } 
  
  for (int z = 0; z < 1; z++) 
  {
    if (brightnessRed <= 0)
    {
      brightnessRed = 0;
      fadeAmount_Red = -fadeAmount_Red;
    }
    else if (brightnessRed >= 255) // set max range to multiple of fade amount 
    {
      brightnessRed = 255;
      fadeAmount_Red = -fadeAmount_Red;
    }
    analogWrite(redLED, brightnessRed);
    brightnessRed += fadeAmount_Red;
    
    // Serial.print("brightnessRed "); Serial.println(brightnessRed);
  } 
}
