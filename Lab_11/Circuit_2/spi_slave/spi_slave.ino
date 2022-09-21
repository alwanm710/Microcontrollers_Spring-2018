
/* SPI Communication Between Two Arduino Uno
  Input pins:
  D10: SS
  D11: MOSI
  D13: SCK
*/

volatile unsigned char secretMessage[3] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  // enable SPI, enable interrupts, slave mode
  SPCR |= 0xC0;
}

void loop() {
  for (unsigned char k = 0; k < 3; k++) {
    Serial.write(secretMessage[k]);
  }
  Serial.print('\n');

  _delay_ms(100);
}

ISR (SPI_STC_vect) {
  static unsigned char j = 0;
  unsigned char message = SPDR;
  if (message == 8) {
    j = 0;
  }
  else {
    secretMessage[j % 3] = message;
    j++;
  }
}

