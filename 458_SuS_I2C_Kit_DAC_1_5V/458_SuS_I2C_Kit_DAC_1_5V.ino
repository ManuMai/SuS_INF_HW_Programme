#include <Wire.h>

// I2C Adresse des TC1321
const int i2cAddr_TC1321 = 0b1001000; // Adresse des TC1321 (0x90)

// Zielwert für 1,5 V bei 2,5 V Referenzspannung
const int targetValue = 614;

void setup() {
  Wire.begin(); // Initialisiert die I2C-Schnittstelle
  setDACOutput(targetValue); // Setzt den DAC-Ausgang auf 1,5 V
}

void loop() {
  // Keine kontinuierliche Aktion erforderlich
}

// Funktion zum Setzen der DAC-Ausgabe
void setDACOutput(int value) {
  // >>>>>>>>>>>>>>>> Programm - Code für I2C Kommunikation ergänzen <<<<<<<<<<<<<<<<<<<<<<

  
}
