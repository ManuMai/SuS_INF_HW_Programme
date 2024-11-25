
void I2C_LCD_init(void)
{
   lcd.begin(16, 2); // initialize the lcd
   lcd.clear();
   lcd.setBacklight(255);
   lcd.setCursor(0,0);
   lcd.print("SOS --> SW2");
}

void I2C_LCD(String LCD_1)
{
   lcd.setCursor(0, 1);
   lcd.print(LCD_1);
}
