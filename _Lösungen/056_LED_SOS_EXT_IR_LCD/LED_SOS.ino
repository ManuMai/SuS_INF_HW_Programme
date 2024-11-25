void LedSosFunktionKurz (void) //Funktion !
{
  for (Zaehlvariable = 1; Zaehlvariable < 4; Zaehlvariable++)   //Strukturen...
  {
    digitalWrite(LED_rt, HIGH); //Output Bitwise High
    delay(500);                //Wait...
    digitalWrite(LED_rt, LOW);  //Output Bitwise Low
    delay(500);                //Wait...
  }
}

void LedSosFunktionLang (void) //Funktion !
{
  for (Zaehlvariable = 1; Zaehlvariable < 4; Zaehlvariable++)
  {
    digitalWrite(LED_rt, HIGH); //Output Bitwise High
    delay(1000);                //Wait...
    digitalWrite(LED_rt, LOW);  //Output Bitwise Low
    delay(1000);                //Wait...
  }
}
