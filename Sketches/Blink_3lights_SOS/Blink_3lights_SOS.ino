// initialize the led output ports:
int led11 = 11;
int led12 = 12;
int led13 = 13;

// the setup routine runs once when you press reset:
void setup() {               
  // initialize the digital pin as an output.
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
pinMode(led13, OUTPUT); 
}

// loop routine should display 3 short blinks followed by 3 long blinks on each LED, 
// one LED at a time.
void loop() {
  for (int x = 11; x < 14; x++) {   // looping through each LED, starting at led11
      for (int sh = 0; sh < 3; sh++) {  // three short blinks
      digitalWrite("led" + x, LOW);
      delay(100);
      digitalWrite("led" + x, HIGH);
      delay(100);
      digitalWrite("led" + x, LOW);
      delay(100);
      }

      for (int lo = 0; lo < 3; lo++) {  // three long blinks
      digitalWrite("led" + x, LOW);
      delay(300);
      digitalWrite("led" + x, HIGH);
      delay(400);
      digitalWrite("led" + x, LOW);
      delay(300);
      }   
  }
}
