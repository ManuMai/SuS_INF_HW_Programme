void show_rechteck_aussen()
{
  send_data(0x01, 0xFF); //erste Zeile alle LEDs an
  send_data(0x02, 0x81);
  send_data(0x03, 0x81);
  send_data(0x04, 0x81);
  send_data(0x05, 0x81);
  send_data(0x06, 0x81);
  send_data(0x07, 0x81);
  send_data(0x08, 0xFF); // letzte Zeile...alle LEDs an
} //Ende show_rechteck_aussen()