#include <Wire.h> //Einbinden der I2C Bibliothek

#define address 0b0100000 //0x40 -> Adresse des I2C Portexpander

char i2c_data; //Deklaration des zu verschiebenden Bitmusters und der Zählvar i

void setup()
{
 
  Serial.begin(115200);  
  
  /* einmalige Einstellung der MCP20083 - Register */
  
  Wire.begin();  //Alternatives PinMapping: Wire.begin(SDA, SCL); 
  Wire.beginTransmission(address); // beginnt mit dem Slave-Gerät zu sprechen
  Wire.write (0x00); // Adresse IO-Direction register (1 Byte) --> wird angesprochen
  Wire.write (0x80); // Daten für das IO-Register(1 Byte)--> 0b1000 0000 = 80h (GP7 Input)
  Wire.endTransmission(); // hört auf, mit dem Gerät zu sprechen --> Stop Bit

  Serial.println("Ende Setup");
}

void loop()
{
  Serial.print(millis()); // Gibt Millisekunden seit Start aus
  I2C_MCP23008_read(); // Aufruf UP I2C Daten lesen von MCP28003
 
  
}
