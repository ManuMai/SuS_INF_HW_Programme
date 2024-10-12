/* Die sos Funktionen sos_kurz und sos_lang sind als UPs einzeln als TABs (Reiter) aufgeführt
   
  
*/

void setup()
{
  pinMode(D13, OUTPUT);
} //Ende setup()

void loop()
{
  sos_kurz(); // Aufruf des UP für Blinklicht "S"
  sos_lang(); // Aufruf des UP für Blinklicht "O"
  sos_kurz();
}// Ende loop()
