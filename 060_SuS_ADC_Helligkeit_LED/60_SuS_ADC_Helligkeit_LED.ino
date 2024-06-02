/* 
Verwende das EMS - Shield mit dem LDR.
Die LED D13 soll angeschaltet werden, sobald der ADC - Wert des LDR (light dependend resistor) unter 1500 fällt.
Ist der Wert höher als 1500 soll die LED D13 ausgeschaltet werden
*/


int val_helligkeit; //globale Helligkeitsvariable


void setup() 
{
  analogReadResolution(12); // Auflösung in BIT --> ändern in 2^12 = 4096 "Stufen"
  pinMode(A1,INPUT_ANALOG); //optional --> geht auch ohne pinMode
  Serial.begin(9600);
  pinMode(D13,OUTPUT);
  
} // Ende setup()

void loop()
{
  val_helligkeit = analogRead(A1); // analogRead(Pin) ließt den analogen Spannungswert am Portpin
  Serial.println(val_helligkeit);
  delay(100);

  // ******** HIER CODE ergänzen der LED D13 an bzw. aus schaltet


} // Ende loop()
