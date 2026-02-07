// 1. Bibliotheken einbinden
#include "DHT.h"

// 2. Einstellungen
#define DHTPIN 2     // An welchem Pin hängt der Sensor?
#define DHTTYPE DHT11   // Welchen Sensor haben wir? (Es gibt auch DHT22)

// Sensor-Objekt erstellen
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Test gestartet...");

  // WICHTIG: Den Sensor starten!
  dht.begin();
}

void loop() {
  // Das Auslesen dauert ca. 250 Millisekunden
  // Wir machen aber eine Pause von 2 Sekunden, da der DHT11 langsam ist
  delay(2000);

  // Werte lesen
  float luftfeuchte = dht.readHumidity();
  float temperatur = dht.readTemperature();

  // Prüfen, ob das Lesen geklappt hat (nan = not a number)
  if (isnan(luftfeuchte) || isnan(temperatur)) {
    Serial.println("Fehler beim Lesen vom DHT Sensor!");
    return; // Abbruch für diese Runde
  }

  // Werte im Monitor ausgeben
  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(luftfeuchte);
  Serial.print(" %  |  ");
  
  Serial.print("Temperatur: ");
  Serial.print(temperatur);
  Serial.println(" °C");

    delay(200000);

}
