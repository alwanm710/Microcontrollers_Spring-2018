void setup() {

  // Initialize ADCSRA with prescaler of 128
   ADCSRA = 0xEF;

  // Initialize ADMUX with reference voltage of AVcc
   ADMUX = 0x40;

  // Initialize ADCSRB into free-running mode
   ADCSRB = 0x00;

  // ADMUX takes in the integer value from the Potentiometer
   ADMUX |= 0x00;
   
  // Configure Cathode pins as an output
   DDRB |= 0x0F;

  // Configure 7-Segment pins as an output
   DDRD |= 0xFE;

  
}

volatile unsigned int result = 0;

unsigned char numeralArray[10] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6 };

void loop() {
  // One's place
   unsigned int A = result % 10;
   PORTB |= 0x0F;
   PORTB &= 0xFE;
   PORTD = numeralArray[A];
   _delay_ms(1);

  // Ten's place
   unsigned int B = (result % 100) / 10;
   PORTB |= 0x0F;
   PORTB &= 0xFD;
   PORTD = numeralArray[B];
   _delay_ms(1);

  // Hundred's Place
   unsigned int C = (result % 1000) / 100;
   PORTB |= 0x0F;
   PORTB &= 0xFB;
   PORTD = numeralArray[C];
   _delay_ms(1);

  // Thousand's Place
  unsigned int D = result / 1000;
   PORTB |= 0x0F;
   PORTB &= 0xF7;
   PORTD = numeralArray[D];
   _delay_ms(1);


}


// This function automatically executes whenever the ADC has completed a conversion
// It is never called in the software code
ISR(ADC_vect) {
  unsigned char LSByte = ADCL;
  unsigned char MSByte = ADCH;
  // depending on the value of ADLAR, the equation for result will be different
  result = ADCL + (ADCH << 8);
}
