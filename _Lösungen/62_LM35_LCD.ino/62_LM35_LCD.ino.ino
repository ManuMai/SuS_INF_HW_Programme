#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd (0x27); // LCD-Adresse (I2C) auf 0x27 für 16 Zeichen und 2 Zeilen ein

u_int16_t adc_lm35_wert; //Messwert, der vom ADC kommt
float temp_wert; //Berechnungsvariable für Kommazahlen aus dem Messwert 

void setup()
{

  I2C_LCD_init();
  Serial.begin(115200);

  pinMode(PA_4, INPUT_ANALOG); 
  analogReadResolution(10);

  lcd.home();
  lcd.print("Temperaturanzeige");
  
}

void loop()
{
  
  adc_lm35_wert = analogRead(PA_4); //PIN A2 auf dem Arduino
  temp_wert = adc_lm35_wert * 0.32227;

  I2C_LCD("Temp: " + String(temp_wert) + "\xdfC");
  delay(500);

  Serial.println("Temp: " + String(temp_wert) + "°C");
  Serial.println("Temp als adc - Wert: " + String(adc_lm35_wert));
  
  
  
  
}
