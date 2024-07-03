

// Bibliothek für SPI-Kommunikation einbinden
#include <SPI.h>

// Definition der Pin-Belegung
#define CS  D10          // Chip-Select für MAX7219
#define PIN_LED D13      // LED-Pin auf dem Board
#define UserButton_state  PC13  // Zustand des Benutzerknopfes

//>>>>>>>>>>>>>>>>>>>> Ergänzen der Tabellen  


volatile int toggle = 0; //Variable für Anzeige togglen 0 = zeige 0 an, toggle = 1 zeige X an

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

  attachInterrupt(digitalPinToInterrupt(UserButton_state), ext_ISR, FALLING);

}

void ext_ISR(void)
{
  toggle = !toggle; //invertiere toggle Variable
}

// Hauptprogrammschleife
void loop() 
{  
  if(toggle == 1)
  {
    for(int adr=1; adr<=8; adr++) //Gehe alle Zeilen durch (DIGITS 0x01 bis 0x08)
    {
     send_data(adr,tabelle_X[adr-1]);      //MSB --> Adresse der Zeile, Array - Wert für LEDs
     Serial.println("Anzeige: X");
    }
  }
  else
  {
    for(int adr=1; adr<=8; adr++) //Gehe alle Zeilen durch (DIGITS 0x01 bis 0x08)
    {
      send_data(adr,tabelle_O[adr-1]);      //MSB --> Adresse der Zeile, Array - Wert für LEDs
      Serial.println("Anzeige: O");
    }
  }
  
}//Ende loop()