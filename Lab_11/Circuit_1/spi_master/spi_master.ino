
/* SPI Communication Between Two Arduino Uno

  Output pins:
  D13: SCK
  D11: MOSI
  D10: SS
*/

void setup() {
  // configure SCK, MOSI and SS as output pins
  DDRB |= 0x2C;
  // write slave select high (inhibits data transfer)
  PORTB |= 0x04;

  // enable SPI, MSB first, master mode, CPOL = 0, CPHA = 0, prescaler of 32
  SPCR |= 0x52;
  SPSR |= 0x01;
}

void loop() {
  unsigned char secretMessage[4] = {8, 'A', 'B', 'C'};

  for (unsigned char j = 0; j < 4; j++) {

    // write slave select low
    PORTB &= 0xFB;

    SPDR = secretMessage[j];
    while (!(SPSR & (1 << SPIF))) {
      // wait for the transmission to complete
    }

    // write slave select high
    PORTB |= 0x04;
  }

  _delay_ms(100);
}
