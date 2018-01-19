/*
  Blink
  Conner Hunihan
  https://github.com/connerhunihan/arduino/tree/master/Sketches/Blink/Blink

  This sketch blinks an S-O-S pattern on a single LED light. This consists of 
  three long blinks followed by three short blinks.
  
  This sketch is a modification of the example code in the public domain at:
  http://www.arduino.cc/en/Tutorial/Blink
  
*/
int led = 9;          // set the ouput pin
int brightness = 0;   // set the initial LED brightness
int fadeAmount = 5;   // set the brightness delta

// setup function to initialize led output 
void setup() {
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{
  analogWrite(led, brightness);

  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 225) {
    fadeAmount = -fadeAmount;
  }

  delay(30);
}
  
 /*
  for (int x = 9; x < 10; x + 0) 
  {     
      for (int short_blink = 0; short_blink < 3; short_blink++)   // three short blinks
      {  
      digitalWrite("led" + x, LOW);
      delay(100);
      digitalWrite("led" + x, HIGH);
      delay(100);
      digitalWrite("led" + x, LOW);
      delay(100);
      }

      for (int long_blink = 0; long_blink < 3; long_blink++)  // three long blinks
      {  
      digitalWrite("led" + x, LOW);
      delay(300);
      digitalWrite("led" + x, HIGH);
      delay(400);
      digitalWrite("led" + x, LOW);
      delay(300);
      }   
  }
}
*/

