// Lauflichter Analogtaster ->Multifuncion Shield

#define LED1 D13 // Präprozessoranweisung --> ersetze LED 1 durch D13
#define LED2 D12 // Präprozessoranweisung --> ersetze LED 2 durch D12
#define LED3 D11 // Präprozessoranweisung --> ersetze LED 3 durch D11
#define LED4 D10 // Präprozessoranweisung --> ersetze LED 4 durch D10
#define Schalter1 A1
#define Schalter2 A2
#define Schalter3 A3

void setup() {

    Serial.begin(9600);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(LED4,OUTPUT);

  digitalWrite(LED1, HIGH);  //schalte LED aus
  digitalWrite(LED2, HIGH);  //schalte LED aus
  digitalWrite(LED3, HIGH);  //schalte LED aus
  digitalWrite(LED4, HIGH);  //schalte LED aus

}

void loop() {
  int S1 = analogRead(Schalter1);
  int S2 = analogRead(Schalter2);
  int S3 = analogRead(Schalter3);
  Serial.print(S1);
  Serial.print(" ; ");
  Serial.print(S2);
  Serial.print(" ; ");
  Serial.println(S3);
  
  if (S1 < 100){
    Blinker_links();
  }

  if (S2 < 100){
    Blinker_rechts();
  }

  if (S3 < 100){
    Warnblinker();
  }


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
