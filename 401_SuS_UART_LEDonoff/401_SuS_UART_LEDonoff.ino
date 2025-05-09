/*********************************************************************************************************
*
*
*Dieses Programm ist ein einfacher **serieller Kommunikationscontroller**, der Daten zwischen zwei seriellen Schnittstellen austauscht und eine LED auf Basis der empfangenen Daten steuert. Hier ist eine kurze Übersicht über die Funktionen des Programms:
*
*- Es initialisiert zwei serielle Schnittstellen, `Serial` für die Kommunikation mit dem seriellen Monitor und `Serial1` für die Kommunikation mit einem externen Gerät.
*- Es liest Daten, die über die `Serial`-Schnittstelle eingehen, und sendet diese Daten über die `Serial1`-Schnittstelle.
*- Es liest auch Daten, die über die `Serial1`-Schnittstelle eingehen. Wenn es ein 'H' empfängt, schaltet es eine LED an. Wenn es ein 'L' empfängt, schaltet es die LED aus.
*- Es hat auch eine Interrupt-Service-Routine (ISR), die aufgerufen wird, wenn ein bestimmter Pin (PC13) einen FALLING-Edge-Interrupt erzeugt. Diese ISR ändert den Zustand der LED und sendet entsprechend 'H' oder 'L' über die `Serial1`-Schnittstelle.
*
*
* ************************ Diese Einführung ist KI - genertiert ********************************************/

char incomingByte; //globale Variable für eintreffende Daten
HardwareSerial Serial1(PA10, PA9); //PA10 --> D2 (Receive) und PA9 --> D8 (Transmit)
volatile char ledValue = 0; //Variable für die extISR - Routine um led - Wert zu ändern

void setup() {
  pinMode(PC13, INPUT_PULLUP); // Setzt den Pin PC13 als Eingang
  pinMode(D13, OUTPUT); // Setzt den Pin D13 als Ausgang
  Serial.begin(115200); //Start des seriellen Monitors mit der Baudrate 115200
  Serial1.begin(115200); // Pins 
  attachInterrupt(digitalPinToInterrupt(PC13), extISR_toggleLED, FALLING); // Setzt einen Interrupt auf den Pin PC13
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

void extISR_toggleLED() {
  // Sendet 'H' oder 'L' abhängig vom aktuellen Zustand der LED
  ledValue =  !ledValue; //invertiert den Wert der LED

  if(ledValue == 0) //Wenn die LED aus ist ...
  {
    
    ///////////********************** >>>>>>>>>>>>>>>>>> ERGÄNZEN 

  }
}