const int buttonPin = 2;  // Pin für die Taste S2
char buttonState = 0;      // Variable für den Zustand der Taste

void setup() {
  Serial.begin(9600);     // Serielle Kommunikation starten
  pinMode(buttonPin, INPUT);  // Pin D2 als Eingang festlegen
}

void loop() {
  

buttonState = digitalRead(buttonPin);
Serial.println((int)buttonState);

  delay(100);  // Kurze Verzögerung, um das Polling zu verlangsamen
}
