//die Schleifen sind schon zusätzlich 

void setup() {
  // put your setup code here, to run once:
  analogWriteFrequency(2000);
  analogWriteResolution(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int pwm_wert = 0; pwm_wert <=255; pwm_wert++)
  {
    analogeWrite(D10, 255);
  }

  for(int pwm_wert = 255; pwm_wert>=0; pwm_wert--)
  {
      analogeWrite(D10, 255);
  }
  
}
