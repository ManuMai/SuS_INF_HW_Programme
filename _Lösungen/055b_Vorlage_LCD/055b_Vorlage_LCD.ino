#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd (0x27); // LCD-Adresse (I2C) auf 0x27 für 16 Zeichen und 2 Zeilen ein


void setup()
{
  
  I2C_LCD_init();
  
}

void loop()
{
  
}
