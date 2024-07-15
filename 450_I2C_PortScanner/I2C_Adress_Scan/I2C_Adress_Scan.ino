#include <Wire.h> //include Wire.h library

void setup()
{
  Wire.begin(); // Wire communication begin
  Serial.begin(9600); // The baudrate of Serial monitor is set in 9600
  while (!Serial); // Waiting for Serial Monitor
  Serial.println("\nI2C Scanner");
}

void loop()
{
  byte error, address; //variable for error and I2C address
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  
  for (address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission(); // endTransmission() --> https://www.arduino.cc/reference/en/language/functions/communication/wire/endtransmission/

    if (error == 0) // 0 bedeutet erfolgreiche Datenübertragung auf dem I2C Bus
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
      Serial.print("0");
     // address = address << 1; // wenn auskommentiert scanned er nach allen Adressen 0 bis 127 -> Ausgabe falsch
      Serial.print(address, BIN);
      Serial.print(",  0x");
      Serial.print(address, HEX);
      Serial.println("  !");
      nDevices++;
      delay(10);
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(2000); // wait 5 seconds for the next I2C scan
}
