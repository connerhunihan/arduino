char serInString[100];

int potPin_red = 0;
int potPin_green = 1;
int potPin_blue = 2;

int ledRed = 9;
int ledGreen = 10;
int ledBlue = 11;

int potValue_brightness_red;
int potValue_brightness_blue;
int potValue_brightness_green;

int fadeRed;
int fadeVal; 

char colorCode;

void setup()
{
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter color (r, g, b) followed by how much (0-25) you want the color to delay (e.g. r10):");  
}

void loop()
{  
  potValue_brightness_red = analogRead(potPin_red);
  potValue_brightness_red = map(potValue_brightness_red, 0, 1023, 0, 255);
  analogWrite(ledRed, potValue_brightness_red);
  
  potValue_brightness_blue = analogRead(potPin_blue);
  potValue_brightness_blue = map(potValue_brightness_blue, 0, 1023, 0, 255);
  analogWrite(ledBlue, potValue_brightness_blue);
  
  potValue_brightness_green = analogRead(potPin_green);
  potValue_brightness_green = map(potValue_brightness_green, 0, 1023, 0, 255);
  analogWrite(ledGreen, potValue_brightness_green);


  // clear the string
  memset(serInString, 0, 100);
  //read the serial port and create a string out of what you read
  readSerialString(serInString);

  colorCode = serInString[0];
  if( colorCode == 'r' )
  {
    fadeVal = atoi(serInString+1);
    serInString[0] = 0;                 
    for(int x=0; x < fadeVal; x++)
    {
      potValue_brightness_red += fadeVal;
      analogWrite(ledRed, potValue_brightness_red);
    } 
  }

}


//read a string from the serial and store it in an array
//you must supply the array variable
void readSerialString (char *strArray) 
{
  int i = 0;
  if(!Serial.available()) 
  {
    return;
  }
  while (Serial.available()) 
  {
    strArray[i] = Serial.read();
    i++;
  }
}

  
