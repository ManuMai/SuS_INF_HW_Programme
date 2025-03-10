// Pinbelegung
#define dataPin D8   //serielle Daten am DS-Pin des 74HC595
#define clockPin D4  // SCLK oder SHCP Pin des 74HC595 (Takteingang zur Datenübernahme an PIN11 am SR)
#define latchPin D12  // STCP Pin des 74HC595
#define pwm_PWM2A D11 //aktiviere den Pin 1 am L293 (1,2 EN)

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(pwm_PWM2A, OUTPUT);
  digitalWrite(pwm_PWM2A, HIGH);
}

void loop() {
  // Motor vorwärts drehen
  shiftOut(dataPin, clockPin, MSBFIRST, B00001000); // IN1 HIGH, IN2 LOW
  digitalWrite(latchPin, HIGH);
  delay(10);
  digitalWrite(latchPin, LOW); //danach erscheinen die DAten am Schieberegister Ausgang
  delay(2000); // 2 Sekunden warten

  // Motor rückwärts drehen -- CODE ergänzen
  

  // Motor stoppen - Code ergänzen
  
}
