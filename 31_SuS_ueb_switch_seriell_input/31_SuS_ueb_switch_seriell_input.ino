/*Programm zur Übung der switch - case Anweisung. Ergänze die switch case Anweisungen für die entsprechenden Fälle. 
 * Die DAten werden über die serielle Schnittstelle eingelesen. Hierzu dient der Befehl parseInt();
 * Kommentiere weiterhin die Befehle, die mit einem Pfeil --> markiert sind
 * 
 */

int new_value;
int auswahl_var = 0;

void setup()
{  
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  if(Serial.available()>0)      // -->
  {
    HIER ergänzen
  }
  
  Serial.print("aktueller Wert:");
  Serial.println(new_value,DEC);

  auswahl_var = new_value;
  
  // wenn auswahl_var gleich 1 --> LED an
  // wenn auswahl_var gleich 0 --> LED aus
  // eenn auswahl_var gleich 2 --> LED blinkt

   if (Serial.read() == '\n') // --> Der Befehl Serial.read() liest 1 Byte des Empfangspuffers. Der eingelesene Wert wird mit der Aktion 
  {                           // --> zum Betätigen der ENTER - Taste verglichen --> Hochkommas (SHIFT + # -Tasten) mit \n entspricht der
                              // --> betätigten Taste "ENTER" (ASCII - Zeichen)


  // HIER ergänzen
  
  }//ende if Abfrage ob ENTER betätigt wurde
  
delay(250);

}//Ende loop()
  
