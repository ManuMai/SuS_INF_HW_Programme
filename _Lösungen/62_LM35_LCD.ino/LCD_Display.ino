
void I2C_LCD_init(void) //LCD Init Funktion
{
   lcd.begin(16, 2); // initialize the lcd
   lcd.clear();
   lcd.setBacklight(255);
   lcd.setCursor(0,0);
   lcd.print("Starting...");
}

void I2C_LCD(String LCD_1) //Funktion zur Ausgabe am LCD 16x2 untere Zeile
{
   lcd.setCursor(0, 1);
   lcd.print(LCD_1);
}
