#include <Wire.h> //Einbinden der I2C Bibliothek

#define address 0b0100000 //0x40 - Port Expander

char Bitmuster,i; //Deklaration des zu verschiebenden Bitmusters und der Zählvar i
Bitmuster = 0b0000001; // Bitmuster für die LEDs

void setup()
{
 
  Serial.begin(115200);  
  /* einmalige Einstellung (Setup) der MCP23008 - Register */
  Serial.println("Ende Setup");
  Wire.begin();  //Startet Wire Bibliothek --> Alternatives PinMapping: Wire.begin(SDA, SCL); 
  Wire.beginTransmission(address); // beginnt mit dem Slave-Gerät zu sprechen (Write Modus)
  Wire.write (0x00); // Auswahl des Adress IO-Direction register (1 Byte) --> Registeradresse
  Wire.write (0x00); // Value Dies setzt alle GPIO als Ausgänge (1 Byte) -->  Daten ins REgister 0x00
  Wire.endTransmission(); // hört auf, mit dem Gerät zu sprechen --> Stop Bit

  
}

void loop()
{
  
  for(i=0;i<8;i++)
  {
  I2C_MCP23008_test();

  if(Bitmuster < 0xFF )
  {
     Bitmuster = Bitmuster << 1; //Schiebeoperator - eins nach links
  }
  else {
  Bitmuster
  }
   delay(1000);
  }
  
}
