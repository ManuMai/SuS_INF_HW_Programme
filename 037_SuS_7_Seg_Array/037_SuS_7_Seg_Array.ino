/* 

Bitte beachten, ob es eine 7 - Segment Anzeige mit gemeinsamer Anode oder Kathode ist.
schauen Sie sich die Funktionsweise des bitRead(x,n) - Befehls an z.B. unter www.arduino.cc

*/


int seven_seg_ports[] = {6,7,8,9,10,11,12,13}; //globales Array für Ports der 7Segment Anzeige
int seven_seg_anzeige[] = //Bitmuster für 7 - Segment Anzeige (7 Segment Codierung der Dezimalziffern)

{ 
  

  //// BITMUSTER für 7 Segment Anzeige ERGÄNZEN !!! (7 - Segment - Code)

}; //Ende Bitmuster - Array

int count = 0; //Zählvariable um die Bitmuster durch zu zählen

void setup()
{

  //Initialisierung der Ports D13-->DP, D12-->Segment g,... bis D6-->Segment a
 
 //  HIER PORTS Initialisieren mit einer for Schleife und dem Array seven_seg_ports[]
 
  Serial.begin(115200);
  Serial.println("Hello, 7 Segment Display");
  
}//Ende setup()

void loop()
{
    
    //Ausgabe der Ziffer an 7 Segment Anzeige
    write7_seg(seven_seg_anzeige[count]); 

    if(count == 9) // wenn die letzte Ziffer erreicht von 0 wieder anfangen
    {
      // HIER ERGÄNZEN
    }
    else
    {
      count++;
    }// Ende if

    delay(500);

    // 7 Segment Anzeige leeren für neue Ziffer
    Serial.println("Anzeige clear\n");
    clear7_seg(0x00); 
  
  
    delay(10); // this speeds up the simulation
    Serial.println("------- nächste Ziffer --------\n");
}//Ende loop()

void write7_seg(uint16_t anzeige_var) //Funktion zum Schreiben an 7Seg Anzeige
{
  
  // HIER ERGÄNZEN AUSGABE an das 7 Segment Display

}//Ende wirte7_seg

void clear7_seg(uint16_t anzeige_var) //Funktion zum Schreiben an 7Seg Anzeige
{
  for(int16_t j=7;j>=0;j--)
  { 
    delay(50);
   
    //Schreibt den Wert an den entsprechenden Portpin zum Anzeigen an der 7 Segment Anzeige
    digitalWrite(seven_seg_ports[j], bitRead(anzeige_var,7-j));
    
  }//Ende for

}//Ende clear7_seg


