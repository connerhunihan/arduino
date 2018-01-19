int potPin_red = 1;
int potPin_green = 2;
int potPin_blue = 0;

int ledRed = 11;
int ledGreen = 10;
int ledBlue = 9;

int sensorValue_blue;
int potValue_brightness_red;
int potValue_brightness_blue;
int potValue_brightness_green;

void setup()
{
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loop()
{  
  sensorValue_blue = analogRead(potPin_blue);
  Serial.println(sensorValue_blue);
  delay(100);
  potValue_brightness_blue = (potValue_brightness_blue / 3);
  potValue_brightness_blue = map(sensorValue_blue, 0, 1023, 0, 255);
  // potValue_brightness_blue = potValue_brightness_blue - 10;
  analogWrite(ledBlue, potValue_brightness_blue);

  potValue_brightness_red = analogRead(potPin_red);
  potValue_brightness_red = map(potValue_brightness_red, 0, 1023, 0, 255);
  analogWrite(ledRed, potValue_brightness_red);
  
  potValue_brightness_green = analogRead(potPin_green);
  potValue_brightness_green = map(potValue_brightness_green, 0, 1023, 0, 255);
  analogWrite(ledGreen, potValue_brightness_green);
}

  
