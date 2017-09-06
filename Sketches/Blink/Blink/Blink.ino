/*
  Blink

  This sketch blinks an SOS pattern on a single LED light. THis consists of 
  three long blinks followed by three short blinks.
  
  This sketch is a modification of the example code in the public domain at:
  http://www.arduino.cc/en/Tutorial/Blink
  
*/

// initialize led output at pin 13
int led13 = 13;

// setup function to run when you press reset or power the board
void setup() {
  // initialize pin 13 as the output.
  pinMode(led13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{
  for (int x = 13; x < 14; x + 0) 
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
