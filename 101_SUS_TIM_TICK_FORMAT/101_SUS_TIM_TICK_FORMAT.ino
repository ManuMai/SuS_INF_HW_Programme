#define LED_B PA5 // D13 Led auf dem Board
static HardwareTimer my_timer = HardwareTimer(TIM3);

volatile int toggle = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_B, OUTPUT);
  my_timer.setPrescaleFactor(1384);
  my_timer.setOverflow(65001, TICK_FORMAT);
  my_timer.attachInterrupt(isr_blinken_led);
  my_timer.resume();
}

void isr_blinken_led()
{
  toggle = !toggle;
  digitalWrite(LED_B, toggle);
}

void loop()
{
  // Die Hauptloop-Funktion bleibt leer, da der Timer unabhängig arbeitet.
}
