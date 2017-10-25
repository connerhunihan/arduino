/* Theremin that allows user to control the length
 *  of the note with a force resistor
 *  
 * --------
 *
 * Created 20 October 2017
 * Conner Hunihan
 */

int photocellPin = A0;
int FSRpin = A1;
int speakerPin = 7;

int pitch = 0;
int toneVal;
int timing;

// try changing the noteDuration to hear how that changes the sound
int noteDuration; // ms

void setup() {
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{  
  // read the value from the sensor
  pitch = analogRead(FSRpin);
  timing = analogRead(photocellPin);
  timing = map(timing, 0, 1023, 0, 255);
  noteDuration = timing;
  Serial.print("FSR Input: "); Serial.println(pitch);
  
  tone(speakerPin, pitch, noteDuration); 
  int pauseBetweenNotes = noteDuration * 1.3;
  delay(pauseBetweenNotes);
  noTone(8);
}
