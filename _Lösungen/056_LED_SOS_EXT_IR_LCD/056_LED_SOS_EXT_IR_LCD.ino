#include <LiquidCrystal_PCF8574.h>
#define S2_STATE  D3

LiquidCrystal_PCF8574 lcd (0x27); // LCD-Adresse (I2C) auf 0x27 für 16 Zeichen und 2 Zeilen ein

volatile int LED_bl = D13; //blaue LED auf EMS
volatile int LED_rt = D12; //rote LED auf EMS
volatile bool ledToggle;
volatile int Zaehlvariable;

void ISR_EXT_IR ()
{
ledToggle =! ledToggle;
digitalWrite (LED_bl, ledToggle);
I2C_LCD("SOS-Alarm       ");
LedSosFunktionKurz();
LedSosFunktionLang();
LedSosFunktionKurz();
} // Ende ISR_SOS


void setup()
{
  Serial.begin(115200);    
  I2C_LCD_init();
  pinMode (LED_rt, OUTPUT);
  pinMode (LED_bl, OUTPUT);
  pinMode (S2_STATE, INPUT);
  attachInterrupt (digitalPinToInterrupt (S2_STATE), ISR_EXT_IR, FALLING);

  delay(500);
}

void loop()
{
  I2C_LCD("Wait IR...");
  delay(1000);
}
