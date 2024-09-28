
void setup() {
  Serial.begin(9600);
}

void loop() {
  aufgabe1_log_OPs();
  aufgabe2_bitverschiebung();
  aufgabe3_bitManipulation();
  while(1);
}

void aufgabe1_log_OPs(void)
{
  byte a = 0b11001100;
  byte b = 0b10101010;

  Serial.print("a & b: ");
  Serial.println(a & b, BIN);
  
  Serial.print("a | b: ");
  Serial.println(a | b, BIN);
  
  Serial.print("a ^ b: ");
  Serial.println(a ^ b, BIN);
  
  Serial.print("~a: ");
  Serial.println(~a, BIN);
}// Ende UP Aufgabe 1

void aufgabe2_bitverschiebung(void)
{
  byte a = 0b00001111;
  
  Serial.print("a << 2: ");
  Serial.println(a << 2, BIN);
  
  Serial.print("a >> 2: ");
  Serial.println(a >> 2, BIN);

} // Ende UP Aufgabe 2

void aufgabe3_bitManipulation(void)
{
   byte a = 0b00000000;
  
  bitWrite(a, 2, 1);
  Serial.print("bitWrite(a, 2, 1): ");
  Serial.println(a, BIN);
  
  bitSet(a, 4);
  Serial.print("bitSet(a, 4): ");
  Serial.println(a, BIN);
  
  bitClear(a, 2);
  Serial.print("bitClear(a, 2): ");
  Serial.println(a, BIN);
  
  Serial.print("bitRead(a, 4): ");
  Serial.println(bitRead(a, 4));

} //Ende UP Aufgabe 3