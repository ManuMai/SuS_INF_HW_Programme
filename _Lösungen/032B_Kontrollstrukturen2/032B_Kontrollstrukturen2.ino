#define LED_PIN 13 // Definiert den Pin für die LED

void setup() {
  pinMode(LED_PIN, OUTPUT); // Setzt den LED-Pin als Ausgang
  Serial.begin(9600); // Startet die serielle Kommunikation mit 9600 Baud
}

void loop() {
  if (Serial.available() > 0) { // Prüft, ob Daten im seriellen Puffer verfügbar sind
    int input = Serial.parseInt(); // Liest die nächste Ganzzahl aus dem seriellen Puffer

    if (Serial.read() == '\n') { // Prüft, ob das nächste Zeichen ein Zeilenumbruch (ENTER) ist
      if (input > 5) { // Prüft, ob die eingegebene Zahl größer als 5 ist
        digitalWrite(LED_PIN, HIGH); // Schaltet die LED ein
        Serial.println("LED an"); // Gibt "LED an" auf dem seriellen Monitor aus
      } else {
        digitalWrite(LED_PIN, LOW); // Schaltet die LED aus
        Serial.println("LED aus"); // Gibt "LED aus" auf dem seriellen Monitor aus
      }
    }
  }
}
