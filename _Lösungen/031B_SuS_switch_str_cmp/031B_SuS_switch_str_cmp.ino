/*Programm zur Übung der switch - case Anweisung. Ergänze die switch case Anweisungen für die entsprechenden Fälle. 
 * Die DAten werden über die serielle Schnittstelle eingelesen. Hierzu dient der Befehl parseInt();
 * Kommentiere weiterhin die Befehle, die mit einem Pfeil --> markiert sind
 * 
 */

int auswahl_var = 0; // Variable zur Auswahl des Falles

void setup()
{  
  pinMode(13, OUTPUT); // Setzt den Pin 13 als Ausgang
  Serial.begin(115200); // Startet die serielle Kommunikation mit 115200 Baud
}

void loop()
{
  // wenn auswahl_var gleich 1 --> LED an
  // wenn auswahl_var gleich 0 --> LED aus
  // wenn auswahl_var gleich 2 --> LED blinkt
 
   String string_in = Serial.readString();  // Liest den seriellen Eingabepuffer bis zum Timeout (Standard 1000ms)
   string_in.trim(); // Entfernt alle vorangestellten oder nachgestellten Leerzeichen oder Returns

   if(string_in == "an") // String-Vergleich mit Zuweisung eines Wertes für auswahl_var
   {
    auswahl_var = 1; // Setzt auswahl_var auf 1
    Serial.println("zuweisung an"); // Gibt "zuweisung an" auf dem seriellen Monitor aus
   } // Ende if "an"

   if(string_in == "aus") // String-Vergleich mit Zuweisung eines Wertes für auswahl_var
   {
    auswahl_var = 0; // Setzt auswahl_var auf 0
    Serial.println("Zuweisung aus"); // Gibt "Zuweisung aus" auf dem seriellen Monitor aus
   } // Ende if "aus"
      
  switch (auswahl_var) // switch-Anweisung mit Vergleichsvariablen auswahl_var
  {
    case 1: // Fall: eine 1 wurde über den seriellen Monitor eingelesen
      digitalWrite(13, HIGH); // Schaltet die LED an
      Serial.println("an"); // Gibt "an" auf dem seriellen Monitor aus
    break; // Fall zu Ende --> Springe an das Ende der switch-Verzweigung

    case 0: // Fall: eine 0 wurde über den seriellen Monitor eingelesen
      digitalWrite(13, LOW); // Schaltet die LED aus
      Serial.println("aus"); // Gibt "aus" auf dem seriellen Monitor aus
    break;

    case 2: // Fall: eine 2 wurde über den seriellen Monitor eingelesen
      Serial.println("Blinki"); // Gibt "Blinki" auf dem seriellen Monitor aus
      for(int i = 0; i <= 2; i++) // Schleife, die 3-mal durchläuft
      {
        digitalWrite(13, HIGH); // Schaltet die LED an
        delay(500); // Wartet 500 Millisekunden
        digitalWrite(13, LOW); // Schaltet die LED aus
        delay(500); // Wartet 500 Millisekunden
      }
      break;

    default: // Fall, wenn keine der obigen cases/Fälle zutrifft
      // nix passiert
    break;
  } // Ende switch()
   
  delay(100); // Wartet 100 Millisekunden

} // Ende loop()


Ich hoffe, das hilft dir weiter! Gibt es noch etwas, bei dem ich dir helfen kann? 😊