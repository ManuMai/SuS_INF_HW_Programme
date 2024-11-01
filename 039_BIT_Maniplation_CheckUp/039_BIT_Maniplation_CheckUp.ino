void setup() {
  Serial.begin(9600);

  // Aufgabe a
  byte zahlA = 0b00001111;
  byte negierteZahlA = ~zahlA;
  Serial.print("Negierte Zahl a: ");
  Serial.println(negierteZahlA, BIN);

  // Aufgabe b
  byte zahlB = 0b00001011;
  zahlB |= (1 << 2); // Setze das dritte Bit auf 1
  Serial.print("Zahl b mit gesetztem dritten Bit: ");
  Serial.println(zahlB, BIN);

  // Aufgabe c
  byte zahlC = 0b00000111;
  zahlC &= ~(1 << 2); // Setze das dritte Bit auf 0
  Serial.print("Zahl c mit gelöschtem dritten Bit: ");
  Serial.println(zahlC, BIN);

  // Aufgabe d
  byte zahlD = 0b00001111;
  zahlD &= ~(1 << 1); // Lösche das zweite Bit
  zahlD &= ~(1 << 2); // Lösche das dritte Bit
  Serial.print("Zahl d mit gelöschtem zweiten und dritten Bit: ");
  Serial.println(zahlD, BIN);

  // Aufgabe e
  byte zahlE = 0b00101111;
  bool sechstesBitGesetzt = bitRead(zahlE, 5); // Prüfe das sechste Bit mit Funktion
  Serial.print("Sechstes Bit der Zahl e (mit Funktion): ");
  Serial.println(sechstesBitGesetzt);

  bool sechstesBitGesetztManuell = (zahlE & (1 << 5)) != 0; // Prüfe das sechste Bit mit Bitmanipulation
  Serial.print("Sechstes Bit der Zahl e (mit Bitmanipulation): ");
  Serial.println(sechstesBitGesetztManuell);
}

void loop() {
  // Leerer Loop
}
