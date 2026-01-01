#include <Servo.h>

Servo meinMotor;
int trigPin = 11;
int echoPin = 12;

void setup() {
  meinMotor.attach(9);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  meinMotor.write(0);
}

void loop() {
  // TriggerPin aus
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Ultraschall abfeuern
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Zeit messen und berechnen
  long dauer = pulseIn(echoPin, HIGH);
  int distance = dauer * 0.034 / 2;

  // Ausgabe
  Serial.print("Abstand: ");
  Serial.println(distance);

  // Entfernung pruefen
  if (distance > 0 && distance < 10) {

    // Tor oeffnen
    for(int i = 0; i <= 90; i++){
      meinMotor.write(i);
      delay(15);
    }

    // Auto faehrt durch
    delay(6000);

    // Tor schliessen
    for(int i = 90; i >=0; i--){
      meinMotor.write(i);
      delay(15);
    }
  }

  // Pause
  else{
    delay(100);
  }

}
