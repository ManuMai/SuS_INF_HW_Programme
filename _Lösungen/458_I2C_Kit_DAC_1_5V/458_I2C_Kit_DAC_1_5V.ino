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
  Wire.beginTransmission(i2cAddr_TC1321);
  Wire.write(0x00); // Registeradresse vom Command Byte (Registerpointer / Zeiger)
  Wire.write(value >> 2); // Höhere 8 Bits des 10-Bit-Wertes
  Wire.write((value & 0x03) << 6); // Niedrigere 2 Bits des 10-Bit-Wertes
  Wire.endTransmission();
}
