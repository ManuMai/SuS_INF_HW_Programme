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
  // >>>>>>>>>>>>>>>> Programmcode ergänzen - I2C Kommunikation <<<<<<<<<<<<<<<<<<<<<<



}
