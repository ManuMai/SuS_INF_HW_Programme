
char incomingByte; //globale Variable für eintreffende Daten
HardwareSerial Serial1(PA10, PA9); //PA10 --> D2 (Receive) und PA9 --> D8 (Transmit)

void setup() {
  pinMode(PC13, INPUT_PULLUP); // Setzt den Pin PC13 als Eingang
  pinMode(D13, OUTPUT); // Setzt den Pin D13 als Ausgang
  Serial.begin(115200); //Start des seriellen Monitors mit der Baudrate 115200
  Serial1.begin(115200); // Pins 
  attachInterrupt(digitalPinToInterrupt(PC13), toggleLED, FALLING); // Setzt einen Interrupt auf den Pin PC13
} //Ende setup()

void loop() {
  while(Serial.available()>0)
  {
    incomingByte = Serial.read(); //Liest die Eingabe am seriellen Monitor
  
    Serial1.write(incomingByte);
  }
  
  while(Serial1.available()>0)
  {
    incomingByte = Serial1.read();
    Serial.println("neue Nachricht: ");
    Serial.print(incomingByte);
    if(incomingByte == 'H')
    {
        //******************************* >>>>>>>>>>>>>>>> Ergänzen
    }

    if(incomingByte == 'L')
    {
      //******************************* >>>>>>>>>>>>>>>> Ergänzen
    }
  }
  
  delay(200);
}// Ende loop()

void toggleLED() {
  // Sendet 'H' oder 'L' abhängig vom aktuellen Zustand der LED
  if(digitalRead(D13) == HIGH)
  {
    
    ///////////********************** >>>>>>>>>>>>>>>>>> ERGÄNZEN 

  }
}