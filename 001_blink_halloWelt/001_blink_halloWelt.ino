#define LED_STM32 D13 // Präprozessoranweisung --> ersetze onboard LED_STM32 durch D13

void setup()
{
    pinMode(LED_STM32,OUTPUT);
} // Ende setup()

void loop() //Hauptprogramm in Endlosschleife
{
  digitalWrite(LED_STM32, HIGH);  //schalte LED_STM32 an (PIN 7)
  delay(1000);              //Verzögerung von 1000ms = 1s
  digitalWrite(LED_STM32,LOW);    //schalte LED_STM32 aus (PIN 7)
  delay(1000); // Verzögerung 1 Sekunde
  
} // Ende main()
