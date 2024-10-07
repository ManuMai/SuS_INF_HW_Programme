/* dieses Programm enthält nur ein UP / Funktion für das SOS Blinklicht
  
*/

void setup()
{
  pinMode(D13, OUTPUT);
} //Ende setup()

void loop()
{
  sos_Funktion_blink(); // Aufruf des UP für Blinklicht "S"
}// Ende loop()
