/*`*Erklärung:**
1. **Bibliothek einbinden:** Die Wire-Bibliothek wird für die I2C-Kommunikation benötigt.
2. **Konstante definieren:** Die Adresse des MCP3221 wird definiert. Da die Wire-Bibliothek 7-Bit-Adressen verwendet, wird die Adresse 0x9A auf 0x4D (0x9A >> 1) geändert.
3. **Setup-Funktion:** Initialisiert die serielle Kommunikation und die I2C-Kommunikation.
4. **Loop-Funktion:** 
   - Liest den analogen Wert vom MCP3221.
   - Wandelt den digitalen Wert in eine Spannung um.
   - Gibt den digitalen Wert und die Spannung über die serielle Schnittstelle aus.
   - Wartet eine Sekunde, bevor der Vorgang wiederholt wird.
5. **Funktion `readMCP3221()`:** 
   - Fordert 2 Bytes vom MCP3221 an.
   - Liest die beiden Bytes und fügt sie zu einem 16-Bit-Wert zusammen.

Falls du noch weitere Fragen hast oder Anpassungen benötigst, lass es mich wissen! */


#include <Wire.h> // Einbinden der Wire-Bibliothek für die I2C-Kommunikation

const int MCP3221_ADDRESS = 0x4D; // 0x9A >> 1, da die Wire-Bibliothek 7-Bit-Adressen verwendet

void setup() {
  Serial.begin(9600); // Initialisierung der seriellen Kommunikation mit 9600 Baud
  Wire.begin(); // Initialisierung der I2C-Kommunikation
}

void loop() {
  uint16_t analogValue = readMCP3221(); // Aufruf der Funktion zum Auslesen des MCP3221
  float val_voltage = analogValue * (5.0 / 4096.0); // Umrechnung des digitalen Wertes in eine Spannung (0-5V Bereich, 12-Bit ADC)
  Serial.print("Analog Value: "); // Ausgabe des Textes "Analog Value: " über die serielle Schnittstelle
  Serial.print(analogValue); // Ausgabe des ausgelesenen digitalen Wertes
  Serial.print("\tVoltage: "); // Ausgabe des Textes "Voltage: " über die serielle Schnittstelle
  Serial.println(val_voltage); // Ausgabe der berechneten Spannung und Zeilenumbruch
  delay(1000); // Wartezeit von 1 Sekunde
}

uint16_t readMCP3221()
{
  Wire.requestFrom(MCP3221_ADDRESS, 2,true); // Anforderung von 2 Bytes vom MCP3221 ...und anschließend ein true --> bus release
  while (Wire.available() < 2); // Warten, bis 2 Bytes verfügbar sind
  uint8_t highByte = Wire.read(); // Lesen des ersten Bytes (höherwertiges Byte)
  uint8_t lowByte = Wire.read(); // Lesen des zweiten Bytes (niederwertiges Byte)
  return (highByte << 8) | lowByte; // Zusammenfügen der beiden Bytes zu einem 16-Bit-Wert
  //alternativ return 256*highByte+lowByte;
} //Ende UP

