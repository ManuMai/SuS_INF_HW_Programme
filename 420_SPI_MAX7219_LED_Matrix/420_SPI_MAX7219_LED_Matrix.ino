//SPI_MAX7219_led8x8
#include <SPI.h>

#define CS  D10
#define PIN_LED D13
#define UserButton_state  PC13

void setup()
{
  pinMode(PIN_LED, OUTPUT);
  pinMode(UserButton_state, INPUT_PULLUP);
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV32);
  SPI.setDataMode(SPI_MODE0);
  delay(10);
  Init_MAX7219();                
  Serial.begin(115200);
  Serial.println("Ende Setup");
}

void loop() 
{  
     send_data(0x01,0x81);   
     delay(2000);
     send_data(0x08,0x81);  
     Serial.println("Punkt(e)"); 
     delay(2000);
 }
