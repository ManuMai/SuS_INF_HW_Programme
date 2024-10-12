// Pin für die LED
const int ledPin = 13;
int speed_var = 0;

void setup() {
  // Initialisierung der seriellen Kommunikation
  Serial.begin(9600);

  // Setzen des LED-Pins als Ausgang
  pinMode(ledPin, OUTPUT);
  Serial.println("Geben Sie >>schnell<< für eine schnelle Blinkfrequenz und >>langsam<< für eine langsame Frequenz. >>aus<< stopp das blinken");
}

void loop() {
  // Überprüfen, ob Daten auf dem seriellen Monitor verfügbar sind
  
  blink(speed_var);

  if (Serial.available()) {
    // Lesen der Eingabe des Benutzers
    String input = Serial.readString();

    // Überprüfen der Eingabe und Anpassen der Blinkfrequenz entsprechend
    if (input == "schnell") {
      speed_var = 100; //100 ms an und 100 ms aus
      
    } else if (input == "langsam") {
      speed_var = 500; //500 ms an /aus

      } else {
      speed_var = 0; //LED bleibt aus
      
    }
  }
}

// Funktion zum Blinken der LED mit einer bestimmten Frequenz
void blink(int frequency) {
  Serial.print("aktueller Speed:\t");
  Serial.println(frequency);
  digitalWrite(ledPin, HIGH);  // LED einschalten
  delay(frequency / 2);        // Halbe Frequenz warten
  digitalWrite(ledPin, LOW);   // LED ausschalten
  delay(frequency / 2);        // Halbe Frequenz warten
}