static HardwareTimer my_timer = HardwareTimer(TIM3);  // Timerinstanz der Klasse HardwareTimer sowie Timerauswahl
//Achtung Zugriff auf die Funktionen der Klasse erfolgt über das Objekt

void setup() 

{
  //my_timer.refresh(); //Alle Register aktualisieren --> nötig?
  
  Serial.begin(9600);
  //Ermittle Taktfrequenz und gib sie aus
  uint32_t timer_freq = my_timer.getTimerClkFreq();
  Serial.print("Taktfrequenz des Systems: "); Serial.print(timer_freq/1000000); Serial.println(" MHz");

  //Ermittle den aktuellen Prescal - Faktor und gib ihn aus
  u_int32_t prescale_factor =  my_timer.getPrescaleFactor();
  Serial.print("aktueller Prescale - Faktor: "); Serial.print(prescale_factor); Serial.println("");


}

void loop() 
{

 
}