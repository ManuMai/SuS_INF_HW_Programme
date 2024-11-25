/* 
Das Programm liest den Wert am PIN A0 ein (STM32 -> PIN PA0_ALT0). Dieser ist am Potenziometer angeschlossen und gibt
den Wert am LCD (untere Zeile aus). Mit der Taste 2 (SW2) kann das SOS Signal ausgelöst werden. Die rote LED
leuchtet entsprechenden dem SOS Signal kurz und lang. Über den Potenziometer kann die Leuchtdauer variiert werden.


*/


#include <LiquidCrystal_PCF8574.h>
#define S2_STATE  D3

LiquidCrystal_PCF8574 lcd (0x27); // LCD-Adresse (I2C) auf 0x27 für 16 Zeichen und 2 Zeilen ein

volatile int LED_bl = D13; //blaue LED auf EMS
volatile int LED_rt = D12; //rote LED auf EMS
volatile bool ledToggle;
volatile int Zaehlvariable;

volatile uint16_t adc_poti_wert; // Potiwert - Variable

void ISR_EXT_IR ()
{
  adc_poti_wert = analogRead(PA0_ALT0);

  ledToggle =! ledToggle;
  digitalWrite (LED_bl, ledToggle);

  I2C_LCD("SOS-Alarm       ");
  LedSosFunktionKurz(adc_poti_wert);
  LedSosFunktionLang(adc_poti_wert);
  LedSosFunktionKurz(adc_poti_wert);
} // Ende ISR_SOS


void setup()
{
  pinMode(PA0_ALT0,INPUT_ANALOG);
  analogReadResolution(12); // Auflösung des AD - Wandlers auf 12 BIT einstellen
  Serial.begin(115200);    
  I2C_LCD_init();
  pinMode (LED_rt, OUTPUT);
  pinMode (LED_bl, OUTPUT);
  pinMode (S2_STATE, INPUT);
  attachInterrupt (digitalPinToInterrupt (S2_STATE), ISR_EXT_IR, FALLING);
  
}

void loop()
{
  adc_poti_wert = analogRead(PA0_ALT0);
  I2C_LCD("Potiwert: " + String(adc_poti_wert));
  delay(500);
}
