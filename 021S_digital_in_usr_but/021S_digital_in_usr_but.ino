/* Recherchiere mit Hilfe des Nucleo user manuals, auf welchem Portpin sich der "User Button B1" befindet.
 */

#define              // Präprozessoranweisung --> ersetze onboard LED_STM32 durch D13
#define              // <<<<< Ergänzen des Portpins für den User Button bei define, die Ersetzung für den Port soll "USR_BUT" sein

void setup()  //setup() ergänzen mit entsprechenden pinModes
{
    



} // Ende setup()

void loop() //Hauptprogramm in Endlosschleife
{
  if(                ) //<<<<<< if - Abfrage ergänzen - User Button B1 ist low - active 
  {
  delay(1000);
  digitalWrite(LED_STM32, HIGH);  //schalte LED_STM32 
  delay(1000);                    //Verzögerung von 1000ms = 1s
  digitalWrite(LED_STM32,LOW);    //schalte LED_STM32 aus 
  delay(1000);
  digitalWrite(LED_STM32, HIGH);  //schalte LED_STM32 
  delay(1000);                    //Verzögerung von 1000ms = 1s
  digitalWrite(LED_STM32,LOW);    //schalte LED_STM32 aus

  }//Ende if

} // Ende main()
