// Es wird immer ein Frame gesendet, der eingehalten werden muss

void I2C_MCP23008_read(void)
  {
    Wire.requestFrom(address, 1);    // 1 Byte vom Portexpander 

    // Solange Daten im Empfangspuffer vorhanden sind
    
    while(Wire.available())   //Solange Daten 
    {
    i2c_data = Wire.read();    // Received ein Byte und speichert es in i2c_data
    Serial.println(i2c_data);  
   
     }

  }
