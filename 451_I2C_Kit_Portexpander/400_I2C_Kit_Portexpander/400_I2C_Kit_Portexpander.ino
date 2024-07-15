#include <Wire.h> //Einbinden der I2C Bibliothek

#define address 0b0100000 //0x40

char Bitmuster,i; //Deklaration des zu verschiebenden Bitmusters und der Zählvar i

void setup()
{
 
  Serial.begin(115200);  
  /* einmalige Einstellung (Setup) der MCP23008 - Register */
  
  Wire.begin();  //Startet Wire Bibliothek --> Alternatives PinMapping: Wire.begin(SDA, SCL); 
  Wire.beginTransmission(address); // beginnt mit dem Slave-Gerät zu sprechen
  Wire.write (0x00); // Auswahl des Adress IO-Direction register (1 Byte) --> Registeradresse
  Wire.write (0x00); // Value Dies setzt alle GPIO als Ausgänge (1 Byte) -->  Daten ins REgister 0x00
  Wire.endTransmission(); // hört auf, mit dem Gerät zu sprechen --> Stop Bit

  Serial.println("Ende Setup");
}

void loop()
{
  Bitmuster = 0b0000001; // Bitmuster für die LEDs 
  for(i=0;i<8;i++)
  {
  I2C_MCP28003_test();
  Bitmuster = Bitmuster << 1; //Schiebeoperator - eins nach links
  delay(1000);
  }
  
}
