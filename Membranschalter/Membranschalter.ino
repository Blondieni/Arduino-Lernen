#include <Keypad.h>

// Zeilen und Spalten definieren
const byte ROWS = 4; 
const byte COLS = 4; 

// Mapping
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pin Belegung 
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

// Objekt erzeugen
Keypad meinKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Variablen definieren
String masterPasswort = "1337";
String eingabe = "";

// Hier hast du den Namen festgelegt: "istGesperrt"
bool istGesperrt = true; 

void setup(){
  // Serielle Kommunikation starten
  Serial.begin(9600);
  Serial.println("SYSTEM GESPERRT.");
  Serial.println("Bitte PIN eingeben (4 Stellen):");
}
  
void loop(){
  char taste = meinKeypad.getKey();
  
  // KORREKTUR 1: Wir benutzen den Namen der Variable
  // Und wir nutzen == zum Vergleichen (nicht = zum Zuweisen)
  if (istGesperrt == true) {
    
    // Wenn eine Taste gedrückt wurde
    if (taste){
      eingabe = eingabe + taste;
      Serial.print("*");
      
      // Die Eingabe ist 4 Zeichen lang
      if (eingabe.length() == 4) {
        Serial.println(); 
        
        // Wenn das Passwort richtig ist
        if (eingabe == masterPasswort) {
          Serial.println(">> ZUGRIFF ERLAUBT! <<");
          Serial.println("Schloss öffnet sich...");
          
          // Die Variable auf falsch setzen
          istGesperrt = false; 
        } 
        
        // falsches Passwort
        else {
          Serial.println(">> ZUGRIFF VERWEIGERT! <<");
          Serial.println("Alarm!");
          eingabe = ""; 
          Serial.println("\nNeuer Versuch:");
        }
      }
    }
  }
}