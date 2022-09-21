/*
  Luis, KP, Muhammad
  Lab 9, Circuit 3
  Master Code
  Pushbutton = D2
  Output pins:
    D13: SCK
    D12: MISO
    D10: SS

*/

void setup() {
  //enable & configure external interrupts
  EIMSK |= 0b00000001;
  EICRA |= 0b00000011;
  DDRD  |= 0b00000100;


  // configure SCK, MOSI and SS as output pins
  DDRB |= 0x34;
  // write slave select high (inhibits data transfer)
  PORTB |= 0x04;

  // use the value of SPCR that you determined from your in-class activity
  SPCR |= 0b11110010;
  // configure SPI status register
  SPSR |= 0b00000001;
}
unsigned char buttonState = 0;

void loop() {

  // SS pin LOW (enable write)
  PORTB &= 0xFB;

  SPDR = buttonState;
  while ( SPSR = 0x80) {
   // SS pin HIGH (disable write)
  PORTB |= 0x04;
  _delay_ms(100);
  }

  ISR(INT0_vect) {
    buttonState = PIND &= 0b00000100;
    
  }

