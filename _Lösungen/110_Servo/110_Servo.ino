#include <Servo.h>

Servo myservo;  // Erstellen eines Servo-Objekts

void setup() {
  myservo.attach(D10);  // Servo an Pin D10 anschließen
}

void loop() {
  myservo.write(90);  // Servo auf 90 Grad positionieren
  delay(1000);        // 1 Sekunde warten
  myservo.write(0);   // Servo auf 0 Grad positionieren
  delay(1000);        // 1 Sekunde warten
}
