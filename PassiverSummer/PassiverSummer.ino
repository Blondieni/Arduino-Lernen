int summerPin = 8;

void setup() {
  pinMode (summerPin, OUTPUT);
}

// tatuu- tataa
void loop() {
  tone(summerPin, 1000);
  delay(500);
  tone(summerPin, 900);
  delay(500);
}

// LKW beim rueckwaertefahren
//void loop() {
//  tone(summerPin, 1000);
//  delay(500);
//  noTone(summerPin);
//  delay(500);
// }