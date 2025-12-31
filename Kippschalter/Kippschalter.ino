int ledPin = 13;
int sensorPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT_PULLUP);
}

void loop() {
  int wert = digitalRead(sensorPin);
  
  // An (Kugel hat Kontakt)
  if (wert == LOW) {
    digitalWrite(ledPin, HIGH); 
  } 

  // Aus (Kugel hat kein Kotakt)
  else {
    digitalWrite(ledPin, LOW); 
  }
}