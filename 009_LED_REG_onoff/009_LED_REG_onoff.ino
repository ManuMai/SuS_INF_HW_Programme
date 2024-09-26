void setup()
{
  pinMode(PA5,OUTPUT); // PA5 = D13 --> LED auf MFC (blau) D1
  pinMode(PA6,OUTPUT); // PA6 = D12 --> LED auf MFC D2
  pinMode(PA7,OUTPUT); // PA7 = D11 --> LED auf MFC D3
  pinMode(PB6,OUTPUT); // PB6 = D10 --> LED auf MFC D4
} // Ende setup()
/*im loop() werden die ODR - Register des GPIO Ports A (GPIOA direkt angesteuert) mit Hilfe des Pfeil Operators -> werden die BITs gesetzt bzw. rückgesetzt

ACHTUNG: die LEDs auf dem MFC (blau) sind low active --> die Ansteuerung erfolgt invertiert. Entsprechend muss auch die HEX - Codierung angepasst werden */

void loop()
{
  GPIOA->ODR =0xFFDF; // jeweils 4 BIT = 1 Nibble sind eine HEX - Stelle --> PA5 = LED Pin --> 6tes BIT ist 0x0020 = 0b0000 0000 0010 0000 (32 BIT binär im ODR - oberen 16 BIT reserviert)
                      // da in dieser Aufgabe das MFC jedoch low active ist, ist die Bitcodierung 1111 1111 1101 1111 --> 0xFFDF für das zweite Nibble (von rechts gelesen)
  delay(500);
  GPIOA->ODR =0xFFFF; // 0b1111 1111 1111 1111 alle BITs im ODR setzen um die LEDs alle auszuschalten !!! immernoch low active
  delay(500);

}// Ende loop()
