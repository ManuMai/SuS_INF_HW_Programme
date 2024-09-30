/*
Erklärung:
setup(): Initialisiert die serielle Kommunikation und den I2C-Bus. Schreibt 5 Beispielwerte in das EEPROM und liest sie anschließend aus.
loop(): Wartet auf eine Eingabe über die serielle Schnittstelle und schreibt den eingegebenen Wert in die nächste freie Adresse.
writeEEPROM(): Unterprogramm zum Schreiben eines Wertes in eine bestimmte Adresse des EEPROM.
readEEPROM(): Unterprogramm zum Lesen eines Wertes aus einer bestimmten Adresse des EEPROM.
 */
 
#include <Wire.h>

#define EEPROM_I2C_ADDRESS 0x50

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Schreibe 5 Werte in fortlaufende Adressen
  for (int i = 0; i < 5; i++) {
    writeEEPROM(i, i + 10); // Beispielwerte: 10, 11, 12, 13, 14
  }

  // Lese die 5 Werte aus und gib sie am seriellen Monitor aus
  for (int i = 0; i < 5; i++) {
    int value = readEEPROM(i);
    Serial.print("Adresse: ");
    Serial.print(i);
    Serial.print(" Wert: ");
    Serial.println(value);
  }
}

void loop() {
  // Warte auf Eingabe über die serielle Schnittstelle
  if (Serial.available() > 0) {
    int value = Serial.parseInt();
    static int address = 5; // Beginne nach den ersten 5 Adressen
    writeEEPROM(address, value);
    address++;
    Serial.print("Geschriebener Wert: ");
    Serial.print(value);
    Serial.print(" an Adresse: ");
    Serial.println(address - 1);
  }
}

// Unterprogramm zum Schreiben in das EEPROM
void writeEEPROM(int address, int data) {
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write((int)(address)); // Adresse
  Wire.write(data); // Daten
  Wire.endTransmission();
  delay(5); // Wartezeit für den Schreibvorgang
}

// Unterprogramm zum Lesen aus dem EEPROM
int readEEPROM(int address) {
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);
  Wire.write((int)(address)); // Adresse
  Wire.endTransmission();
  
  Wire.requestFrom(EEPROM_I2C_ADDRESS, 1);
  if (Wire.available()) {
    return Wire.read(); // Daten lesen
  }
  return -1; // Fehlerfall
}
