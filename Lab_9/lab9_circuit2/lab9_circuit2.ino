/*
  Luis, KP, Muhammad
  Lab 9, Circuit 2
  This code uses SPI and a 74165 8-bit shift register
  Output pins:
    D13: SCK
    D12: MISO
    D10: SS
  
*/

void setup() {

  //Global interrupts are disabled
  cli();

  //Serial Monitor begins
  Serial.begin(9600);

  //

  // configure SCK, MOSI and SS as output pins
  DDRB |= 0x34;
  // write slave select high (inhibits data transfer)
  PORTB |= 0x04;

  // use the value of SPCR that you determined from your in-class activity
  SPCR |= 0x70;

  //Enale global interrupts
  sei();

}

void loop() {

  static unsigned char dipData = 0;
  static unsigned char oldDipData = 0;

  // SS pin LOW (enable write)
  PORTB &= 0xFB;

  // SS pin HIGH (disable write)
  PORTB |= 0x04;

  dipData = SPIRx (0);


  if (dipData != oldDipData) {
    Serial.println(dipData);
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

