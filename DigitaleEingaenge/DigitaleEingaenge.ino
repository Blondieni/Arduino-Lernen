// PIN definieren
int rot = 5;
int tasterOben = 9;
int tasterUnten = 8;

void setup(){
  
  // Einstellungen
  pinMode (rot, OUTPUT);
  pinMode (tasterOben, INPUT_PULLUP);
  pinMode (tasterUnten, INPUT_PULLUP);
}

void loop(){

  // Druecke obere Taste Licht an
  if(digitalRead(tasterOben) == LOW){
    digitalWrite(rot, HIGH);
  }

  // Druecke untere Taste Licht aus
  if(digitalRead(tasterUnten) == LOW){
    digitalWrite(rot, LOW);
  }
}

