#define LED1 10 // Definiert den Pin für die erste LED
#define LED2 11 // Definiert den Pin für die zweite LED
#define LED3 12 // Definiert den Pin für die dritte LED

void setup() {
  pinMode(LED1, OUTPUT); // Setzt den LED1-Pin als Ausgang
  pinMode(LED2, OUTPUT); // Setzt den LED2-Pin als Ausgang
  pinMode(LED3, OUTPUT); // Setzt den LED3-Pin als Ausgang
  Serial.begin(9600); // Startet die serielle Kommunikation mit 9600 Baud
}

void loop() {
  if (Serial.available() > 0) { // Prüft, ob Daten im seriellen Puffer verfügbar sind
    char input = Serial.read(); // Liest das nächste Zeichen aus dem seriellen Puffer
    if (input == 'q') { // Prüft, ob das Zeichen 'q' ist
      Serial.println("Programm beendet"); // Gibt eine Nachricht auf dem seriellen Monitor aus
      while (true); // Endlosschleife, um das Programm zu stoppen
    }
  }

  digitalWrite(LED1, HIGH); // Schaltet die erste LED ein
  delay(500); // Wartet 500 Millisekunden
  digitalWrite(LED1, LOW); // Schaltet die erste LED aus

  digitalWrite(LED2, HIGH); // Schaltet die zweite LED ein
  delay(500); // Wartet 500 Millisekunden
  digitalWrite(LED2, LOW); // Schaltet die zweite LED aus

  digitalWrite(LED3, HIGH); // Schaltet die dritte LED ein
  delay(500); // Wartet 500 Millisekunden
  digitalWrite(LED3, LOW); // Schaltet die dritte LED aus
}
