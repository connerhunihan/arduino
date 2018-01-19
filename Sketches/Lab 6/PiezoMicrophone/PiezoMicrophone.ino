int outputPin = 8;
int knockSensor = A2;
int thresholdHIGH = 120;
int thresholdLOW = 70;

const int secretKnockLength = 3;
const int secretKnock[secretKnockLength] = {0, 0, 1};

int secretCounter = 0;
int sensorReading = 0;

void setup ()
{
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorReading = analogRead(knockSensor);
  
  if (sensorReading >= thresholdHIGH)
  {
    if (secretKnock[secretCounter] == 1)
    {
      secretCounter++;
      Serial.println("Correct");        
    }
    else
    {
      secretCounter = 0;
      Serial.println("Fail");
      digitalWrite(outputPin, LOW);
    }
    delay(100);
  }
  else if (sensorReading >= thresholdLOW)
  {
    if (secretKnock[secretCounter] == 0)
    {
      secretCounter++;
      Serial.println("Correct");
    }
    else 
    {
      secretCounter = 0;
      Serial.println("Fail");
    }
    delay(100);
  }
  if (secretCounter == (secretKnockLength))
  {
    Serial.println("Welcome");
    digitalWrite(outputPin, HIGH);
    secretCounter = 0;
  }
}

