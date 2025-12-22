int rot = 6;
int gruen = 5;
int blau = 3;

void setup() {
  pinMode(rot, OUTPUT);
  pinMode(gruen, OUTPUT);
  pinMode(blau, OUTPUT);
}

void loop() {

  //Rot leuchten 1sek.
  digitalWrite(gruen, LOW);
  digitalWrite(blau, LOW);
  digitalWrite(rot, HIGH);
  delay(1000);
  
  //Gruen leuchten 1sek.
  digitalWrite(rot,LOW);
  digitalWrite(gruen,HIGH);
  digitalWrite(blau,LOW);
  delay(1000);

  //Blau leuchten 1sek.
  digitalWrite(rot,LOW);
  digitalWrite(gruen,LOW);
  digitalWrite(blau,HIGH);
  delay(1000);

}
