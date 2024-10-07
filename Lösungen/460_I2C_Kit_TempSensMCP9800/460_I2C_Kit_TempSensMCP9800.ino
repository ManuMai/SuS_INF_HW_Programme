#include <Wire.h>

const int i2cAddr_MCP9800 = 0x49; // I2C-Adresse des MCP9800 (7BIT - Adresse)

void setup() {
  Wire.begin(); // Initialisiert die I2C-Schnittstelle
  Serial.begin(9600); // Initialisiert die serielle Kommunikation
}

void loop() {
  float temperature = readTemperature();
  Serial.print("Temperatur: ");
  Serial.print(temperature);
  Serial.println(" °C");
  delay(1000); // Wartezeit von 1 Sekunde
}

float readTemperature() {
  Wire.beginTransmission(i2cAddr_MCP9800);
  Wire.write(0x00); // Temperaturregister lesen (Registerpoint auf 0x00)
  Wire.endTransmission();
  
  Wire.requestFrom(i2cAddr_MCP9800, 2);
  if (Wire.available() == 2) {
    int temp = Wire.read() << 8 | Wire.read(); // | entspricht logischem ODER
    temp = temp >> 4; // Wir schieben die 12 BIT in die richtige Position im 16 BIT Register
    return (float)temp*0.0625; //multiplizere die Var temp mit 0,0625 --> bei 12BIT kleinste Auflösung pro BIT
                                // (float) dieser Befehl macht einen Typecast, dass es eine float Var wird
  }
  return 0.0; // Rückgabe 0.0 bei Fehler
}
