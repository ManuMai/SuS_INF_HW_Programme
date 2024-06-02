#define LED_intern D13 // Präprozessoranweisung --> ersetze LED_extern durch D7


void setup()
{
    pinMode(LED_intern,OUTPUT);
   
} // Ende setup()

void loop() 
{
  digitalWrite(LED_intern, HIGH); 
  delay(500); //SOS - kurz
  digitalWrite(LED_intern, LOW); 
  delay(500); //SOS - kurz

  digitalWrite(LED_intern, HIGH); 
  delay(500); //SOS - kurz
  digitalWrite(LED_intern, LOW); 
  delay(500); //SOS - kurz

  digitalWrite(LED_intern, HIGH); 
  delay(500); //SOS - kurz
  digitalWrite(LED_intern, LOW); 
  delay(500); //SOS - kurz

  digitalWrite(LED_intern, HIGH); 
  delay(1000); //SOS - lang
  digitalWrite(LED_intern, LOW); 
  delay(1000); //SOS - lang

  digitalWrite(LED_intern, HIGH); 
  delay(1000); //SOS - lang
  digitalWrite(LED_intern, LOW); 
  delay(1000); //SOS - lang

  digitalWrite(LED_intern, HIGH); 
  delay(1000); //SOS - lang
  digitalWrite(LED_intern, LOW); 
  delay(1000); //SOS - lang

  digitalWrite(LED_intern, HIGH); 
  delay(500); //SOS - kurz
  digitalWrite(LED_intern, LOW); 
  delay(500); //SOS - kurz

  digitalWrite(LED_intern, HIGH); 
  delay(500); //SOS - kurz
  digitalWrite(LED_intern, LOW); 
  delay(500); //SOS - kurz

  digitalWrite(LED_intern, HIGH); 
  delay(500); //SOS - kurz
  digitalWrite(LED_intern, LOW); 
  delay(500); //SOS - kurz
  
} // Ende main()
