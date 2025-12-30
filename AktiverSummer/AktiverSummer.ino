// Summer an Pin 8
int summerPin = 12; 


void setup() {
  pinMode(summerPin, OUTPUT);
}

void loop() {

  // 1 sek piepen
  digitalWrite(summerPin, HIGH); 
  delay(1000);                   

  // 1 sek Pause
  digitalWrite(summerPin, LOW);  
  delay(1000);
}