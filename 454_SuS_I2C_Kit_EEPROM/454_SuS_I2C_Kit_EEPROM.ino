/* Ergänze den Programmcode beim TAB read_write_Funktionen */

#include <Wire.h> // Bibliothek für I2C-Kommunikation

#define EEPROM_ADDR 0x50 // I2C-Adresse des 24LC02B EEPROM

void setup() {
  Serial.begin(9600); // Serielle Kommunikation starten
  Wire.begin(); // I2C-Kommunikation starten

  // Werte in EEPROM schreiben
  for (int i = 0; i < 5; i++) {
    writeEEPROM(i, i * 10); // Beispielwerte: 0, 10, 20, 30, 40
  }

  // Kurze Verzögerung, um sicherzustellen, dass die Daten geschrieben wurden
  delay(100);

  // Werte aus EEPROM lesen und anzeigen
  for (int i = 0; i < 5; i++) {
    int value = readEEPROM(i);
    Serial.print("Adresse: ");
    Serial.print(i);
    Serial.print(" Wert: ");
    Serial.println(value);
  }
}

void loop()
{
  // Nichts zu tun im loop
}



