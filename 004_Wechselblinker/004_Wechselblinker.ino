#define LED_extern D7 // Präprozessoranweisung --> ersetze LED_extern durch D7
#define LED_extern2 D8

void setup()
{
    pinMode(LED_extern,OUTPUT);
} // Ende setup()

void loop() //Hauptprogramm in Endlosschleife
{
  digitalWrite(LED_extern, HIGH);  //schalte LED_extern an (PIN 7)
  digitalWrite(LED_extern2,LOW);    //schalte LED_extern aus (PIN 8)
  delay(2000);
  digitalWrite(LED_extern2, HIGH);  //schalte LED_extern an (PIN 8)
  digitalWrite(LED_extern,LOW);    //schalte LED_extern aus (PIN 7)
  delay(2000);
} // Ende main()
