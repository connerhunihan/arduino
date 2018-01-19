int potPin = A0;
int FSRpin = A1;

int ledRed = 10;
int ledGreen = 11;
int ledBlue = 9;

int sensorValue;
int potValue;
int FSRValue;

int LED_red;
int LED_blue;
int LED_green;

void setup()
{
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loop()
{  
  potValue = analogRead(potPin);
  sensorValue = analogRead(FSRpin);
  Serial.println(potValue);
 
  LED_blue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(ledBlue, LED_blue);

  sensorValue = analogRead(FSRpin);
  LED_red = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(ledRed, LED_red);

  sensorValue = analogRead(FSRpin);
  LED_green = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(ledGreen, LED_green);
}

  
