int trigPin = 11;
int echoPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // TriggerPin aus
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Ultraschall abfeuern
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo empfangen und Zeit messen
  long dauer = pulseIn(echoPin, HIGH);

  // Entfernung berechnen
  int distance =dauer*0.034 / 2;
  
  // Ergebnis ausgeben
  Serial.print("Entfernung: ");
  Serial.print(distance); 
  Serial.println(" cm");

  // kurze Pause
  delay(5000);
}
