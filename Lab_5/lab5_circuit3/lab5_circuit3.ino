/*Lab 5, Circuit 3
 Circuit III: Watchdog Timer Reset.
 
 */



void setup() {

  //Clear interrupt
  cli();
  //Configured all output pins
   DDRD |= 0x0C;

  //Flash setup LED for 1.5 seconds
   //Turn on LED
    PORTD |= 0x04;

   //Delay of 1500 milliseconds
    _delay_ms(1500);

   //Turn off LED
    PORTD &= 0x00;

  //Configure prescaler for Watchdog Timer
   WDTCSR |= 0x18;
   WDTCSR = 0x0E;

  sei();

}

void loop() {

  unsigned int n = 1000;

  for (unsigned int j = 0; j < n; j++)
  {
    asm volatile ("wdr");

    PORTD ^= 0x08;

    msdelay(j);
  }

}

void msdelay(unsigned int x) {

  for (unsigned int i = 0; i < x; i++ )
  {
    _delay_ms(100);
  }

}

