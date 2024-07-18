// Es wird immer ein Frame gesendet, der eingehalten werden muss

void I2C_MCP23008_read(void)
  {
    Wire.beginTransmission(MCP23008_adress);
    Wire.write(GPIO_REGISTER);
    Wire.endTransmission();

    Wire.requestFrom(MCP23008_adress, 1);    // 1 Byte vom PortexpanderIC MCP23008
    
    // Solange Daten im Empfangspuffer vorhanden sind
    
    if(Wire.available()>0)   //Wenn Daten da sind... 
    {
    i2c_data = Wire.read();    // Received ein Byte und speichert es in i2c_data
    Serial.print("aktueller Wert: ");
    Serial.println(i2c_data,HEX);  
    }

  }
