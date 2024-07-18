/*es gibt unter Beispiele ein Testprogramm, mit dessen Hilfe man verschiedene Modi ausprobieren kann
...einfach mal testen
*/

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

// Zunächst wird ein Objekt mit dem Namen "mein_lcd" der Klasse LiquidCrystal_PCF8574 erzeugt
LiquidCrystal_PCF8574 mein_lcd(0x27);  // I2C-Adresse des LCD auf 0x27 festlegen (Standard 16 Zeichen und 2 Zeilen)


void setup()
{
  i2c_LCD_init();

} // Ende setup()


void loop()
{

  //hier passiert nichts

} //Ende loop()
