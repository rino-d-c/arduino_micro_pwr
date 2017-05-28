class blinkLED
{
  int LED;                      // variabel 'LED' untuk led pin
  int tundaHIGH;                // variabel 'tundaHIGH' untuk delay saat HIGH
  int tundaLOW;                 // variabel 'tundaLOW' untuk delay saat LOW
  int statusLED;
  unsigned long millisAwal = 0;

  public:
  blinkLED(int pin, long high, long low)
  {
    LED = pin;
    pinMode(LED, OUTPUT);          

    tundaHIGH = high;
    tundaLOW = low;

    statusLED = HIGH;
    millisAwal = 0;
  }

  void Update()
  {
    unsigned long millisSekarang = millis();            // 'millisSekarang' disamakan dengan nilai millis()
    if((statusLED == HIGH) && (millisSekarang - millisAwal >= tundaHIGH)) // jika 'statusLED' HIGH dan millisSekarang-millisAwal kurangdarisamadengan 'tundaHIGH'
    {
      statusLED = LOW;                // 'statusLED' diberi nilai LOW
      millisAwal = millisSekarang;    // 'millisAwal' disamakan dengan 'millisSekarang'
      digitalWrite(LED, statusLED);   
    }
    else if((statusLED == LOW) && (millisSekarang - millisAwal >=  tundaLOW))
    {
      statusLED = HIGH;
      millisAwal = millisSekarang;
      digitalWrite(LED, statusLED);
    }
  }
};

blinkLED led0 (0, 1000, 1000);   //  blinkLED led0 (pin led, delay saat HIGH, delay saat LOW) 
blinkLED led1 (1, 500, 500);
blinkLED led2 (2, 1000, 500);
blinkLED led3 (3, 500, 1000);
blinkLED led4 (4, 1000, 100);
blinkLED led5 (5, 2000, 500);
blinkLED led6 (6, 500, 100);
blinkLED led7 (7, 100, 200);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  led0.Update();               
  led1.Update();
  led2.Update();
  led3.Update();
  led4.Update();
  led5.Update();
  led6.Update();
  led7.Update();
  
}
