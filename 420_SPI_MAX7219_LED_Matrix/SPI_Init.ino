/// MAX7219 initialisation
void Init_MAX7219(void)
{
  //send_data(MSB ,  LSB);
    send_data(0x09, 0x00);         // Deaktiviere Decodierung (0xAddr Data) --> Datenblatt: Adresse 0x09
    send_data(0x0A, 0x08);         // Helligkeit auf mittleres Niveau einstellen
    send_data(0x0B, 0x07);         // Scan-Limit auf 7 setzen (alle Reihen/Spalten)
    send_data(0x0C, 0x01);         // Normaler Betriebsmodus
    send_data(0x0F, 0x0F);         // Display-Test aktivieren
    delay(500);                    // 500 ms Verzögerung
    send_data(0x0F,0x00);          // Display-Test deaktivieren -- Alle LEDs an
    send_data(0x01,0x00);          // Reihe 0 löschen
    send_data(0x02,0x00);          // Reihe 1 löschen
    send_data(0x03,0x00);          // Reihe 2 löschen
    send_data(0x04,0x00);          // Reihe 3 löschen
    send_data(0x05,0x00);          // Reihe 4 löschen
    send_data(0x06,0x00);          // Reihe 5 löschen
    send_data(0x07,0x00);          // Reihe 6 löschen
    send_data(0x08,0x00);          // Reihe 7 löschen

    delay(500);                    // 500 ms Verzögerung
}

// Funktion zum Senden von Daten an den MAX7219
void send_data (unsigned char MSB, unsigned char LSB)
{
  digitalWrite(CS, LOW);          // CS-Pin auf LOW setzen (aktivieren)
  SPI.transfer(MSB);              // Übertrage das höherwertige Byte (MSB)
  SPI.transfer(LSB);              // Übertrage das niederwertige Byte (LSB)
  digitalWrite(CS, HIGH);         // CS-Pin auf HIGH setzen (deaktivieren)
}