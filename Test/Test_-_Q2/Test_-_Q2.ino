 
 /*
 Mohammad Alwan
  Test , Circuit 2
  Output pins:
    D13: SCK
    D12: MISO
    D10: SS
  
*/

void setup() {

  //Global interrupts are disabled
  cli();

  // configure SCK, MOSI and SS as output pins
  DDRB |= 0x34;

  //Configure your digital pin as an output 
   DDRD |= 0xF0;
   
  // write slave select high (inhibits data transfer)
  PORTB |= 0x04;

  PORTD |= 0x04;

  // use the value of SPCR that you determined from your in-class activity
  SPCR |= 0x70;

  //Enale global interrupts
  sei();

}

volatile unsigned int result = 0;


void loop() {

  static unsigned char dipData = result;
  static unsigned char oldDipData = result;

  // SS pin LOW (enable write)
  PORTB &= 0xFB;

  // SS pin HIGH (disable write)
  PORTB |= 0x04;

  dipData = SPIRx (0);

// Define an array with display values for each numeral from 0-9
PORTD = 0xF0;
  unsigned int a = result;
 //
  PORTD = 0x00;
 //
   a%=10;

   _delay_ms(10);

  if (dipData != oldDipData) {
    oldDipData = dipData;
  }

  else {
    _delay_ms(10);

  }
}

char SPIRx ( char data ) {

  SPDR = data;
while( SPSR = 0x80){
  return SPDR;
}
  



}

