void i2c_LCD_init(void)
{
  uint8_t error;

  Serial.begin(115200);

  while (!Serial); //Solange der serielle Monitor aktiv ist
  
  Serial.println("Versuche I2C Chip PCF8574 auf der Adresse 0x27 zu erreichen...");

  Wire.begin(); //Starte I2C Verbindung ...
  Wire.beginTransmission(0x27); //...sende Nachricht an Adresse 0x27
  error = Wire.endTransmission(); //Beende I2C Verbindung und speichere den Rückgabewert der Funktion ...kommt später noch genauer
  Serial.print("Error: ");
  Serial.print(error); //...gib den Fehler aus --> 0 entspricht erfolgreiche Verbindung (siehe Reference)

  if (error == 0) // Wenn kein Fehler... dann
  {
    Serial.println(": LCD gefunden.");
    mein_lcd.begin(16, 2);  // initialisiere das LCD
    mein_lcd.print("Hallo LCD");
    delay(2000);
    mein_lcd.setBacklight(127);
    mein_lcd.setCursor(0,0);
  } 
  else
  {
    Serial.println("LCD wurde nicht gefunden");
  }


}//Init beendet