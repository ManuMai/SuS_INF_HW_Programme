

// Bibliothek für SPI-Kommunikation einbinden
#include <SPI.h>

// Definition der Pin-Belegung
#define CS  D10          // Chip-Select für MAX7219
#define PIN_LED D13      // LED-Pin auf dem Board
#define UserButton_state  PC13  // Zustand des Benutzerknopfes

// Initialisierungsfunktion
void setup()
{
  pinMode(PIN_LED, OUTPUT);             // Setze LED-Pin als Ausgang
  pinMode(UserButton_state, INPUT_PULLUP); // Setze Benutzerknopf als Eingang mit Pullup-Widerstand
  pinMode(CS, OUTPUT);                  // Setze CS-Pin als Ausgang
  digitalWrite(CS, HIGH);               // Setze CS-Pin auf HIGH (deaktiviert)
  SPI.begin();                          // Starte SPI-Kommunikation
  SPI.setBitOrder(MSBFIRST);            // Setze Bitreihenfolge auf MSB zuerst
  SPI.setClockDivider(SPI_CLOCK_DIV32); // Setze Taktteiler für SPI
  SPI.setDataMode(SPI_MODE0);           // Setze Datenmodus für SPI
  delay(10);                            // Kurze Verzögerung
  Init_MAX7219();                       // Initialisiere MAX7219
  Serial.begin(115200);                 // Starte serielle Kommunikation mit 115200 Baud
  Serial.println("Ende Setup");         // Ausgabe in der Konsole
}

// Hauptprogrammschleife
void loop() 
{  
     send_data(0x01,0x01);   // Sende Daten an MAX7219, um LED zu steuern
     delay(2000);            // Warte 2 Sekunden
     Serial.println("Punkt(e)"); // Ausgabe in der Konsole
     delay(2000);            // Warte weitere 2 Sekunden
 }
