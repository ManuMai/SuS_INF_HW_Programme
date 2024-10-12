// INFO: Beim Testen musst du den im seriellen Monitor auf "Neue Zeile" neben der Baudrate setzen,
// sonst funktioniert die Abfrage nach \n nicht

#define LED D13  // Definiert den Pin für die LED

int new_value;    // Variable zur Speicherung des neuen Wertes
int auswahl_var;  // Variable zur Auswahl des Falles

void setup() {
  pinMode(LED, OUTPUT);  // Setzt den LED-Pin als Ausgang
  Serial.begin(9600);    // Startet die serielle Kommunikation mit 9600 Baud
}

void loop() {
  if (Serial.available() > 0)  // Prüft, ob Daten im seriellen Puffer verfügbar sind
  {
    new_value = Serial.parseInt();  // Liest die nächste Ganzzahl aus dem seriellen Puffer
  
    if (Serial.read() == '\n')  // Prüft, ob das nächste Zeichen ein Zeilenumbruch (ENTER) ist    
    {
      auswahl_var = new_value;    // Setzt die Auswahlvariable auf den neuen Wert
      
      switch (auswahl_var)  // Schaltet je nach Wert der Auswahlvariable
      {
        case 0:
          digitalWrite(LED, LOW);  // Schaltet die LED aus
          Serial.println("LED aus");
          break;
        case 1:
          digitalWrite(LED, HIGH);  // Schaltet die LED ein
          Serial. println("LED an");
          break;
        case 2:
          Serial.println("LED - Blinken");
          digitalWrite(LED, HIGH);  // Schaltet die LED ein
          delay(1000);              // Wartet 1 Sekunde
          digitalWrite(LED, LOW);   // Schaltet die LED aus
          delay(1000);              // Wartet 1 Sekunde
          digitalWrite(LED, HIGH);  // Schaltet die LED ein
          delay(1000);              // Wartet 1 Sekunde
          digitalWrite(LED, LOW);   // Schaltet die LED aus
          delay(1000);              // Wartet 1 Sekunde
          digitalWrite(LED, HIGH);  // Schaltet die LED ein
          delay(1000);              // Wartet 1 Sekunde
          digitalWrite(LED, LOW);   // Schaltet die LED aus
        default:
          Serial.println("default");
          break;  // Standardfall, falls keiner der obigen Fälle zutrifft
      }

      Serial.print("aktueller Wert:\t");  // Gibt den Text "aktueller Wert:" aus
      Serial.println(new_value, DEC);     // Gibt den aktuellen Wert in BINärdarstellung aus
      delay(250);  // Wartet 250 Millisekunden
    }
  }
}//Ende loop