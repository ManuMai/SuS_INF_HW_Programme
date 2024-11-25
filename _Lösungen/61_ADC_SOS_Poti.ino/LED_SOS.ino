void LedSosFunktionKurz (uint16_t zeit_kurz) //Funktion !
{
  zeit_kurz = zeit_kurz *0.25; // blinkzeit kurzes Signal von "S" ist willkürlich auf die Hälfte festgelegt
  for (Zaehlvariable = 1; Zaehlvariable < 4; Zaehlvariable++)   //Strukturen...
  {
    digitalWrite(LED_rt, HIGH); //Output Bitwise High
    delay(zeit_kurz);                //Wait...
    digitalWrite(LED_rt, LOW);  //Output Bitwise Low
    delay(zeit_kurz);                //Wait...
  }
}

void LedSosFunktionLang (uint16_t zeit_lang) //Funktion !
{
  zeit_lang = zeit_lang *0.5;
  for (Zaehlvariable = 1; Zaehlvariable < 4; Zaehlvariable++)
  {
    digitalWrite(LED_rt, HIGH); //Output Bitwise High
    delay(zeit_lang);                //Wait...
    digitalWrite(LED_rt, LOW);  //Output Bitwise Low
    delay(zeit_lang);                //Wait...
  }
}
