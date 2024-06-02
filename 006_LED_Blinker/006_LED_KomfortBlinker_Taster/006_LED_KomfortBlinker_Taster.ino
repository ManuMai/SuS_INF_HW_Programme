#define LED_D1 D13          // Variablendeklaration
#define LED_D2 D12
#define LED_D3 D11
#define LED_D4 D10
#define User_Button PA1




void setup()    // Einmalige Ausführung
{
    pinMode(LED_D1,OUTPUT);   //Pins als Output festlegen
    pinMode(LED_D2,OUTPUT);
    pinMode(LED_D3,OUTPUT);
    pinMode(LED_D4,OUTPUT);

    AlleAus();

    Serial.begin(115200); //Startet den seriellen Monitor zur Kommunikation mit dem PC
    
} // Ende setup()

void loop()     // Endlosschleife
{

  if (digitalRead(User_Button)== LOW)
  {
   for (int i = 1; i < 4; i++)    //Zählschleife
   {
    digitalWrite (LED_D1, LOW);
    delay(200);
    digitalWrite (LED_D2, LOW);
    delay(200);
    digitalWrite (LED_D3, LOW);
    delay(200);
    digitalWrite (LED_D4, LOW);
    delay(200);
    AlleAus();
    delay(300);
    Serial.print("das ist der: ");
    Serial.print(i);
    Serial.println(" Durchlauf");
   }
   

  }
//  else
//   {
//    AlleEin();
//   }
  
} // Ende main()
