//Servo mit +5V (rot), GND (braun), D10 (orange)

#include <Servo.h>
//uint16_t Winkel;
Servo servo;
 
 
void setup()
{
  servo.attach(10);  //Pin D10
  Serial.begin(9600);
  servo.write(170);
  delay(500);
}
 
void loop() {
  
 /*
  Winkel=analogRead (A5);
 
  int Value=map(Winkel,0,1023, 88, 158); //Map von 0 bis 75 mit ca. 37 Mittelstellung
  servo.write(Value);
  Serial.print("ADC - Wert "); Serial.println(Winkel);
  Serial.println(Value);
  delay(250);
 */
}