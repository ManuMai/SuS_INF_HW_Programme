// Lauflichter Analogtaster ->Multifuncion Shield

#define LED1 D13 // Präprozessoranweisung --> ersetze LED 1 durch D13
#define LED2 D12 // Präprozessoranweisung --> ersetze LED 2 durch D12
#define LED3 D11 // Präprozessoranweisung --> ersetze LED 3 durch D11
#define LED4 D10 // Präprozessoranweisung --> ersetze LED 4 durch D10
#define Taster1 PA1
#define Taster2 
#define Taster3

void setup() {

    Serial.begin(9600);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(LED4,OUTPUT);
    pinMode(Taster1,INPUT);
    pinMode(Taster2,INPUT);
    pinMode(Taster3,INPUT);

  digitalWrite(LED1, HIGH);  //schalte LED aus
  digitalWrite(LED2, HIGH);  //schalte LED aus
  digitalWrite(LED3, HIGH);  //schalte LED aus
  digitalWrite(LED4, HIGH);  //schalte LED aus



}

void loop() {
  
  if (digitalRead(Taster1) == LOW){
    Blinker_links();
  }

 // Code für Taster2 - Blinker_rechts() und Warnblinker() Taster3 ergänzen


}

void Blinker_links(void){
  for(int n = 0; n < 3; n++){
  delay(200);              //Verzögerung von 500 ms
  digitalWrite(LED1, LOW);  //schalte LED an
  delay(200);              //Verzögerung von 500 ms
  //digitalWrite(LED1, LOW);  //schalte LED aus
  digitalWrite(LED2, LOW);  //schalte LED aus
  delay(200);              //Verzögerung von 500 ms
  //digitalWrite(LED1, LOW);  //schalte LED aus
  //digitalWrite(LED2, LOW);  //schalte LED aus
  digitalWrite(LED3, LOW);  //schalte LED aus
  delay(200);              //Verzögerung von 500 ms
  //digitalWrite(LED1, LOW);  //schalte LED aus
  //digitalWrite(LED2, LOW);  //schalte LED aus
  //digitalWrite(LED3, LOW);  //schalte LED aus
  digitalWrite(LED4, LOW);  //schalte LED aus
  delay(200);              //Verzögerung von 500 ms
  
  digitalWrite(LED1, HIGH);  //schalte LED aus
  digitalWrite(LED2, HIGH);  //schalte LED aus
  digitalWrite(LED3, HIGH);  //schalte LED aus
  digitalWrite(LED4, HIGH);  //schalte LED aus
  }
}

void Blinker_rechts(void){
  for(int n = 0; n < 3; n++){
  delay(200);              //Verzögerung von 500 ms
  digitalWrite(LED4, LOW);  //schalte LED an
  delay(200);              //Verzögerung von 500 ms
  //digitalWrite(LED1, LOW);  //schalte LED aus
  digitalWrite(LED3, LOW);  //schalte LED aus
  delay(200);              //Verzögerung von 500 ms
  //digitalWrite(LED1, LOW);  //schalte LED aus
  //digitalWrite(LED2, LOW);  //schalte LED aus
  digitalWrite(LED2, LOW);  //schalte LED aus
  delay(200);              //Verzögerung von 500 ms
  //digitalWrite(LED1, LOW);  //schalte LED aus
  //digitalWrite(LED2, LOW);  //schalte LED aus
  //digitalWrite(LED3, LOW);  //schalte LED aus
  digitalWrite(LED1, LOW);  //schalte LED aus
  delay(200);              //Verzögerung von 500 ms
  
  digitalWrite(LED1, HIGH);  //schalte LED aus
  digitalWrite(LED2, HIGH);  //schalte LED aus
  digitalWrite(LED3, HIGH);  //schalte LED aus
  digitalWrite(LED4, HIGH);  //schalte LED aus
  }
}

void Warnblinker(void){
  for(int n = 0; n < 5; n++){
  digitalWrite(LED1, LOW);  //schalte LED aus
  digitalWrite(LED2, LOW);  //schalte LED aus
  digitalWrite(LED3, LOW);  //schalte LED aus
  digitalWrite(LED4, LOW);  //schalte LED aus

  delay (400);
  
  digitalWrite(LED1, HIGH);  //schalte LED aus
  digitalWrite(LED2, HIGH);  //schalte LED aus
  digitalWrite(LED3, HIGH);  //schalte LED aus
  digitalWrite(LED4, HIGH);  //schalte LED aus

  delay(200);
}
}
