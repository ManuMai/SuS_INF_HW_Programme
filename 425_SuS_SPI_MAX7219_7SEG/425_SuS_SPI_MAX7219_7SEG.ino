#include <SPI.h>
 
#define CS  D10
#define UserButton_state  PC13
#define einer 1
#define zehner 2
#define hunderter 3
#define tausender 4
#define z_tausender 5
#define h_tausender 6
#define million 7
#define z_million 8
 
 //>>>>>>>>> TAbelle ergänzen 
const unsigned char tab7Seg[] = {                             };
 
// Reihenfolge 10^0, 10^1, ... , 10^7
unsigned char Seg[] = {1, 2, 3, 4, 5, 6, 7, 8};
 
void setup()
{
  pinMode(CS, OUTPUT);
  pinMode(UserButton_state, INPUT_PULLUP);
  digitalWrite(CS, HIGH);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV32);
  SPI.setDataMode(SPI_MODE0);
  delay(100);
  Init_MAX7219();                 // Initialize the LED controller
  Serial.begin(115200);
  Serial.println("Ende Setup");
}
 
void loop() 
{
     if(digitalRead(UserButton_state)== HIGH) 
     {
        send_data(einer, tab7Seg[1]);
        send_data(zehner, tab7Seg[2]);
        send_data(hunderter, tab7Seg[3]);
        send_data(tausender, tab7Seg[4]);
        Serial.println("1234");
     } else 
     {
        send_data(z_tausender, tab7Seg[5]);
        send_data(h_tausender, tab7Seg[6]);
        send_data(million, tab7Seg[7] | 0x80);
        send_data(z_million, tab7Seg[8]);
        Serial.println("5678");
     }
     delay(500);
 }
