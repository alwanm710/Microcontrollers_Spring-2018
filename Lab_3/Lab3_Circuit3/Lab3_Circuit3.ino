  
  void setup() {
  // Initialize ADCSRA with prescaler of 128
   ADCSRA = 0xEF;

  // Initialize ADMUX with reference voltage of AVcc
   ADMUX = 0x40;

  // Initialize ADCSRB into free-running mode
   ADCSRB = 0x00;

  // Configure your digital pin as an output
   DDRD |= 0xFF;

  //Configure your digital pin as an output 
   DDRB |= 0x0F;

}

volatile unsigned int result = 0;

unsigned char numeralArray[10] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6 };
 
  

void loop() {

  Serial.begin(9600);
 // Define an array with display values for each numeral from 0-9
PORTB = 0x0F;
  unsigned int a = result;
 //
  PORTB = 0x00;
 //
   a%=10;
 //
  PORTD = numeralArray[a];
 //

 Serial.println(a);
 
 _delay_ms(250);

 

 
  
}

// This function automatically executes whenever the ADC has completed a conversion
// It is never called in the software code
ISR(ADC_vect) {
  unsigned char LSByte = ADCL;
  unsigned char MSByte = ADCH;
  // depending on the value of ADLAR, the equation for result will be different
  result = ADCL + (ADCH << 8);
}
