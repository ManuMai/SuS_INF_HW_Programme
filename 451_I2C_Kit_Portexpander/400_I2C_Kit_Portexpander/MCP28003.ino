// Es wird immer ein Frame gesendet, der eingehalten werden muss

void I2C_MCP28003_test(void)
  {
    Wire.beginTransmission(address);  //Adrese vom Teilnehmer - device(write - schreiben)
    Wire.write(0x09);                 //Adresse GPIO Register des device ansprechen
    Wire.write(Bitmuster);            //Bitmuster ausgeben in das GPIO - Register
    Wire.endTransmission();           //STOP  
  }
  
