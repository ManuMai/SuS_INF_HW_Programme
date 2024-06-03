/*
*Dieses Programm ist ein einfacher Code für einen Mikrocontroller, der einen externen Interrupt am Pin PC13 (benannt als `buttonPin`) und einen Timer-Interrupt (TIM2) verwendet. 

- Der externe Interrupt wird ausgelöst, wenn der Zustand des `buttonPin` von HIGH auf LOW wechselt (FALLING edge). Wenn dieser Interrupt ausgelöst wird, wird der Timer (TIM2) gestartet.
- Der Timer-Interrupt wird ausgelöst, wenn der Timer einen bestimmten Wert (`tickValue`) erreicht. Der Timer läuft mit einer Frequenz von 1 MHz, die durch den Prescale-Faktor (`prscFactor`) eingestellt wird. Der Overflow-Wert des Timers ist so eingestellt, dass der Timer-Interrupt alle 25 ms ausgelöst wird.
- Im Hauptprogramm (innerhalb der `loop()` Funktion) wird der externe Interrupt wieder aktiviert, wenn der Zustand des `buttonPin` von LOW auf HIGH wechselt (RISING edge).
- Es gibt auch einige globale Variablen für die Farbwerte (rot, grün, blau), die jedoch im aktuellen Code nicht verwendet werden.

Bitte beachten, dass die Funktionen `isr_ext_buttonPin` und `isr_timer2`, die als Interrupt-Handler dienen, im aktuellen Code leer sind. Sie müssen mit dem entsprechenden Code gefüllt werden, der ausgeführt werden soll, wenn die jeweiligen Interrupts ausgelöst werden.
*
*
*/

// Pin für den USER BUTTON (PC13)
const int buttonPin = PC13;

// Farbvariablen - global
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

//Tick - Wert für Overflow
const int tickValue= 25000; // Overflow nach 25000 --> 25000 * 1 µs = 25 ms
const int prscFactor = 90; //PRescalefaktor von 90 --> 90 MHz / 90 = 1 MHz --> T = 1µs

// my_timer-Instanz für TIM2
static HardwareTimer my_timer = HardwareTimer(TIM2);

void setup() {
  // Initialisierung
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  
  // my_timer-Konfiguration
  my_timer.setPrescaleFactor(prscFactor); // Prescaler für 1 MHz (90 MHz / 90 = 1MHz --> 1µs für Timer)
  my_timer.setOverflow(tickValue);     // Overflow-Wert --> 25000*1 µs = 25 ms

  // Interrupt-Handler
  my_timer.attachInterrupt(isr_timer2);

  // externer Interrupt am buttonPin PC13
  attachInterrupt(digitalPinToInterrupt(PC13),isr_ext_buttonPin,FALLING);
}

void isr_ext_buttonPin(void)
{
  detachInterrupt(PC13);
  my_timer.resume();
}

void isr_timer2(void)
{
 
}// Ende isr_timer2


void loop()
{

  attachInterrupt(digitalPinToInterrupt(PC13),isr_ext_buttonPin,RISING);
  analogWrite(D9, rgb_red)
}