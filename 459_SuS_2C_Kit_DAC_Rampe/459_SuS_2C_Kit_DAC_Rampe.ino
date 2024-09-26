#include <Wire.h>

const int i2cAddr_MCP9800 = 0x48; // I2C-Adresse des MCP9800

void setup() {
  Wire.begin(); // Initialisiert die I2C-Schnittstelle
  Serial.begin(9600); // Initialisiert die serielle Kommunikation
}

void loop() {
  Wire.beginTransmission(i2cAddr_MCP9800);
  Wire.write(0x00); // Temperaturregister lesen
  Wire.endTransmission();
  
  Wire.requestFrom(i2cAddr_MCP9800, 2);
  if (Wire.available() == 2) {
    int temp = Wire.read() << 8 | Wire.read();
    float temperature = temp / 16.0; // Temperaturwert berechnen
    Serial.println(temperature); // Temperaturwert ausgeben
  }
  
  delay(1000); // Wartezeit von 1 Sekunde
}
