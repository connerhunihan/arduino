int potPin_red = 0;
int potPin_green = 1;
int potPin_blue = 2;

int ledRed = 9;
int ledGreen = 10;
int ledBlue = 11;

int potValue_brightness_red;
int potValue_brightness_blue;
int potValue_brightness_green;

void setup()
{
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
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
}

  
