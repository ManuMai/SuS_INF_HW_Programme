/*******************************************************************
* Programm erstellt mit Hilfe eines my_timers (TIM2) eine zufällige Zahl 
* durch einen my_timer - Interrupt. Der Wert der Zahl wird alle 5 ms
* erhöht. Ist der Wert 7 erreicht, wird der Zählwert wieder auf 1 
* gesetzt. Der Würfel-Timer startet, sobald die Taste PC13 einmal betätigt wurde.
* Wir die Taste das zweite mal betätigt, wird das Würfelergebnis angezeigt.
* Die Ausgabe erfolgt am seriellen Monitor und am LCD (I2C)
* (Version Mai - 06.05.24)
* ***** Verbesserungen: Irgend eine Anzeige, dass gerade gewürfelt wird z.B. LED Blinken???
*********************************************************************/
#include <LiquidCrystal_PCF8574.h>

// Pin für den USER BUTTON (PC13)
const int buttonPin = PC13;

// my_timer-Instanz für TIM2
static HardwareTimer my_timer = HardwareTimer(TIM2);

//LCD Objekt
LiquidCrystal_PCF8574 my_lcd(0x27);

// Variable für Würfelwert
volatile int diceValue = 1;

// Würfel - BIT --> Würfel ist aktiv = 1 / inaktiv = 0
volatile char  diceActive = 0;

void setup() {
  // Initialisierung
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  my_lcd.begin(16,2);
  my_lcd.setBacklight(255);
  my_lcd.setCursor(0,0);
  my_lcd.print("--Digit Würfel--");
  my_lcd.setCursor(0,0);

  // my_timer-Konfiguration
  my_timer.setPrescaleFactor(90); // Prescaler für 1 MHz (90 MHz / 90 = 1MHz --> 1µs für Timer)
  my_timer.setOverflow(5000);     // Overflow-Wert --> 5000*1 µs = 5 ms

  // Interrupt-Handler
  my_timer.attachInterrupt(isr_timer2);

  // externer Interrupt am buttonPin PC13
  attachInterrupt(digitalPinToInterrupt(PC13),isr_ext_buttonPin,FALLING);
}

// ISR für externen IR
void isr_ext_buttonPin(void)
{
  if(diceActive == 0)
  {
  // Starte den my_timer
  my_timer.resume(); //Starte Timer zum Würfeln
  my_lcd.print("Würfel start...");
  my_lcd.setCursor(0,1);
  diceActive=1;
  }
  else
  {
    my_timer.pause(); // Schalte Timer aus
    diceActive=0;
    Serial.print("Würfelwert: ");
    Serial.println(diceValue);
    my_lcd.print("Würfelwert: "); my_lcd.print(diceValue);
    
  }

}//End isr_ext

//ISR für Timer2 IR
void isr_timer2(void)
{
    diceValue++; // Erhöhe Würfelwert bei jedem Interrupt (nach 5 ms)
    if (diceValue > 6)
    {
      diceValue = 1;
    }
}// Ende isr_timer2

void loop()
{
  
      
}

