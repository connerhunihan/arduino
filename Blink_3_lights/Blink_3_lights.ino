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

// the loop routine runs over and over again forever:
void loop() {
  for (int x = 11; x < 14; x++) {
      for (int sh = 0; sh < 3; sh++) {
      digitalWrite("led" + x, LOW);
      delay(100);
      digitalWrite("led" + x, HIGH);
      delay(100);
      digitalWrite("led" + x, LOW);
      delay(100);
      }

      for (int lo = 0; lo < 3; lo++) {
      digitalWrite("led" + x, LOW);
      delay(300);
      digitalWrite("led" + x, HIGH);
      delay(400);
      digitalWrite("led" + x, LOW);
      delay(300);
      }   
  }
}
