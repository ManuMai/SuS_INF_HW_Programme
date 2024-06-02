#define LED_extern D7 // Präprozessoranweisung --> ersetze onboard LED_extern durch D7

void setup()
{
    pinMode(LED_extern,OUTPUT);
} // Ende setup()

void loop() //Hauptprogramm in Endlosschleife
{
  digitalWrite(LED_extern, HIGH);  //schalte LED_extern an (PIN 7)
  delay(1000);              //Verzögerung von 1000ms = 1s
  digitalWrite(LED_extern,LOW);    //schalte LED_extern aus (PIN 7)
  delay(1000);
} // Ende main()
