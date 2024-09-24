#include <Wire.h>

// I2C Adresse des TC1321
const int i2cAddr_TC1321 = 0b1001000; // Adresse des TC1321 (0x90)

void setup() {
  Wire.begin(); // Initialisiert die I2C-Schnittstelle
}

void loop() {
  for (int i = 0; i < 1024; i++) {
    setDACOutput(i);
    delay(10); // Wartezeit von 10 ms
  }
}

// Funktion zum Setzen der DAC-Ausgabe
void setDACOutput(int value) {
  Wire.beginTransmission(i2cAddr_TC1321);
  Wire.write(0x00); // Registeradresse
  Wire.write(value >> 2); // Höhere 8 Bits des 10-Bit-Wertes
  Wire.write((value & 0x03) << 6); // Niedrigere 2 Bits des 10-Bit-Wertes
  Wire.endTransmission();
}
