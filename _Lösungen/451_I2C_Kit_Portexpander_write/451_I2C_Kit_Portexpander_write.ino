#include <Wire.h> // Einbinden der I2C-Bibliothek

#define ADDRESS 0b0100000 // 0x40 - Port Expander

uint8_t Bitmuster = 0b00000001; // Bitmuster für die LEDs

void setup()
{
  Serial.begin(115200);  
  Serial.println("Ende Setup");

  Wire.begin();  // Startet Wire-Bibliothek --> Alternatives Pin-Mapping: Wire.begin(SDA, SCL);
  Wire.beginTransmission(ADDRESS); // beginnt mit dem Slave-Gerät zu sprechen (Write-Modus)
  Wire.write(0x00); // Auswahl des Adress-IO-Direction-Register (1 Byte)
  Wire.write(0x00); // Setzt alle GPIO als Ausgänge (1 Byte)
  Wire.endTransmission(); // Stoppt die Kommunikation mit dem Gerät
}

void loop()
{
  for(uint8_t i = 0; i < 8; i++)
  {
    I2C_MCP23008_test(); // Stelle sicher, dass diese Funktion definiert ist!

    Bitmuster <<= 1; // Schiebeoperator - eins nach links

    if (Bitmuster == 0) 
    {
      Bitmuster = 0b00000001; // Setzt Bitmuster zurück
    }

    delay(1000);
  }
}
