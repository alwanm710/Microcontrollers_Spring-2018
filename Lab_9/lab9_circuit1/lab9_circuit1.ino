/*
  Lab 9, Circuit 1
  This code uses SPI and a 74595 register to cycle through 
    numerals 0-9 on a 7-segment common-cathode display
  Output pins: 
    D13: SCK
    D11: MOSI
    D10: SS
  Written by Alyssa J. Pasquale, Ph.D.
  October 1, 2017
*/

void setup() {
  // configure SCK, MOSI and SS as output pins
  DDRB |= 0x2C;
  // write slave select high (inhibits data transfer)
  PORTB |= 0x04;

  // use the value of SPCR that you determined from your in-class activity
  SPCR |= ;
}

void loop() {
  static unsigned char x = 0;
  unsigned char numArray[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};

  // SS pin LOW (enable write)
  PORTB &= 0xFB;

  // Data will transfer when SPDR is written to
  SPDR = numArray[x];

  // Wait until transfer is complete
  while (!(SPSR & (1 << 7)));

  // SS pin HIGH (disable write)
  PORTB |= 0x04;

  x++;

  if (x > 9) {
    x = 0;
  }

  _delay_ms(250);
}
