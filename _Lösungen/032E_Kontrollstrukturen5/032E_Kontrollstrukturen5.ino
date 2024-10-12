
const int redLedPin = D10; // Pinnummer der roten LED
const int greenLedPin = D11; // Pinnummer der grünen LED
const int blueLedPin = D12; // Pinnummer der blauen LED

void setup()
{
Serial.begin(9600); // Starte die serielle Kommunikation mit einer Baudrate von 9600

pinMode(redLedPin, OUTPUT); // Setze den Pin der roten LED als Ausgang
pinMode(greenLedPin, OUTPUT); // Setze den Pin der grünen LED als Ausgang
pinMode(blueLedPin, OUTPUT); // Setze den Pin der blauen LED als Ausgang
}

void loop()
{
  while (!Serial.available())
  {
  // Warte, bis Daten über den seriellen Monitor verfügbar sind
  }

  String input = Serial.readStringUntil('\n'); // Lese die Eingabe des Benutzers bis zum Zeilenumbruch

  if (input.length() > 0) // Gebe die Länge des STrings input zurück...ist diese größer als 0 ...dann...
  {
    switch (input[0])// Schaue dir nur das erste Element an b für blau, g für grün und r für rot
    {
      case 'r':
      digitalWrite(redLedPin, HIGH); // Schalte die rote LED ein
      digitalWrite(greenLedPin, LOW); // Schalte die grüne LED aus
      digitalWrite(blueLedPin, LOW); // Schalte die blaue LED aus
      break;
      case 'g':
      digitalWrite(redLedPin, LOW); // Schalte die rote LED aus
      digitalWrite(greenLedPin, HIGH); // Schalte die grüne LED ein
      digitalWrite(blueLedPin, LOW); // Schalte die blaue LED aus
      break;
      case 'b':
      digitalWrite(redLedPin, LOW); // Schalte die rote LED aus
      digitalWrite(greenLedPin, LOW); // Schalte die grüne LED aus
      digitalWrite(blueLedPin, HIGH); // Schalte die blaue LED ein
      break;
      default:
      digitalWrite(redLedPin, LOW); // Schalte die rote LED aus
      digitalWrite(greenLedPin, LOW); // Schalte die grüne LED aus
      digitalWrite(blueLedPin, LOW); // Schalte die blaue LED aus
      break;
    }
  }
}