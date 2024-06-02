
/*  ************ einleitender KOMMENTAR wurde KI generiert und punktuell verändert *********
Dieses Arduino-Programm ist für die serielle Kommunikation konzipiert. Es liest Daten von einem seriellen Port, sendet sie an einen anderen seriellen Port und gibt sie dann auf dem seriellen Monitor aus.

Es definiert eine globale Variable `incomingByte` für eintreffende Daten und initialisiert `Serial1` für die Kommunikation über die Pins PA10 (D2, Receive) und PA9 (D8, Transmit).

Im `setup()` wird die serielle Kommunikation für den seriellen Monitor und `Serial1` mit einer Baudrate von 115200 gestartet.

Die `loop()`-Funktion läuft kontinuierlich und überprüft, ob Daten auf den seriellen Ports verfügbar sind. Wenn Daten auf `Serial` verfügbar sind, liest es die Daten, sendet sie an `Serial1`. Wenn Daten auf `Serial1` verfügbar sind, liest es die Daten und gibt sie auf dem seriellen Monitor aus.

*/
char incomingByte; //globale Variable für eintreffende Daten
HardwareSerial Serial1(PA10, PA9); //PA10 --> D2 (Receive) und PA9 --> D8 (Transmit)

void setup() {

 // pinMode(Board_LED, OUTPUT);
  Serial.begin(115200); //Start des seriellen Monitors mit der Baudrate 115200
  Serial1.begin(115200); // Pins 
} //Ende setup()

void loop() {

  while(Serial.available()>0)
  {
    incomingByte = Serial.read(); //Liest die Eingabe am seriellen Monitor
  
    Serial1.write(incomingByte);
  }
  
  while(Serial1.available()>0)
  {
  incomingByte = Serial1.read();
  Serial.println("neue Nachricht: ");
  Serial.print(incomingByte);
  
  }
  
  delay(200);
}// Ende loop()
