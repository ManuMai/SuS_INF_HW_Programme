#include <LiquidCrystal_PCF8574.h>  // Bibliothek für das LCD-Display

#define detect_value D8  // Pin für den Eingangssensor

LiquidCrystal_PCF8574 lcd(0x27);  // Initialisierung des LCD-Displays mit der I2C-Adresse 0x27

volatile bool detected = false;  // Variable zur Speicherung des Alarmzustands

void setup() {
  lcd.begin(16, 2);  // Initialisiere das LCD mit 16 Spalten und 2 Zeilen
  lcd.setBacklight(127);  // Setze die Hintergrundbeleuchtung des LCDs auf mittlere Helligkeit

  pinMode(detect_value, INPUT_PULLUP);  // Setze den Pin für den Eingangssensor auf INPUT_PULLUP
  
  attachInterrupt(digitalPinToInterrupt(detect_value), ISR_Alarm, CHANGE);  // Interrupt für den Eingangssensor bei Zustandsänderung
}

void loop() {
  if (detected) {
    lcd.clear();  // Lösche das LCD
    lcd.print("ALARM");  // Zeige "ALARM" auf dem LCD an
    while(detected) {  // Warte, bis sich der Zustand ändert
      delay(10);  // Kleine Verzögerung, um CPU-Auslastung zu reduzieren
    }
  } else {
    lcd.clear();  // Lösche das LCD
    lcd.print("Alles OK");  // Zeige "Alles OK" auf dem LCD an
    while(!detected) {  // Warte, bis sich der Zustand ändert
      delay(10);  // Kleine Verzögerung, um CPU-Auslastung zu reduzieren
    }
  } 
}

void ISR_Alarm() {
  detected = !detected;  // Invertiere den Zustand direkt im Interrupt
}
