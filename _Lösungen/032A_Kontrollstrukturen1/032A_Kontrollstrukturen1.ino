#define LED_PIN 13 // Definiert den Pin für die LED

void setup() {
  pinMode(LED_PIN, OUTPUT); // Setzt den LED-Pin als Ausgang
  Serial.begin(9600); // Startet die serielle Kommunikation mit 9600 Baud
}

void loop() {
  if (Serial.available() > 0) { // Prüft, ob Daten im seriellen Puffer verfügbar sind
    char input = Serial.read(); // Liest das nächste Zeichen aus dem seriellen Puffer

    // Überprüft, ob das eingelesene Zeichen kein Zeilenumbruch ist
    if (input != '\n') {
      switch (input) { // switch-Anweisung mit der Eingabe als Vergleichsvariable
        case 'a': // Fall: der Benutzer hat 'a' eingegeben
          digitalWrite(LED_PIN, HIGH); // Schaltet die LED ein
          Serial.println("LED an"); // Gibt "LED an" auf dem seriellen Monitor aus
          break;

        default: // Standardfall: alle anderen Eingaben
          digitalWrite(LED_PIN, LOW); // Schaltet die LED aus
          Serial.println("LED aus"); // Gibt "LED aus" auf dem seriellen Monitor aus
          break;
      }
    }
  }
}
