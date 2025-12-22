void setup() {
  pinMode(9, OUTPUT);      // Wir wecken Pin 9 auf
}

void loop() {
  digitalWrite(9, HIGH);   // Strom AN (Licht an)
  delay(1000);             // 1 Sekunde warten
  digitalWrite(9, LOW);    // Strom AUS (Licht aus)
  delay(1000);             // 1 Sekunde warten
}
 
