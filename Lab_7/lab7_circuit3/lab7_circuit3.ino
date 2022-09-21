/*
  Lab 7, Circuit 3
  Circuit 3: DC Motor Control
  Control the speed of the DC motor with a potentiometer
*/

void setup()
{
  // Configure OC0B (Pin D5) as an output pin so that it can be used with PWM
  DDRD |= 0x04;
  
  // Configure TCCR1A: Fast-PWM to OCR0A, non-inverting mode
  TCCR1A = 0x23;

  // Configure TCCR1B: no force compares, prescaler of 1
  TCCR1B = 0x11;

  // OCR1A value of 319 to create a PWM frequency of 25kHz
  OCR1AH = 0x01;
  OCR1AL = 0x3F;

  // Initialize ADCSRA with prescaler of 1024, Set ADEN, ADSC, ADATE and ADIE
  ADCSRA |= 0xEF;

  // Initialize ADMUX with reference voltage of AVcc, set ADLAR
  ADMUX |= 0x60;

  // Input the value of the analog pin you will use (possible values: 0-5)
  unsigned char yourAnalogPin = 0;
  // Configures ADMUX to operate on your chosen analog pin
  ADMUX |= yourAnalogPin;

  // Initialize ADCSRB into free-running mode
  ADCSRB &= 0xF8;
}

volatile unsigned int result = 0;

void loop()
{
  // using the L after the numbers forces the answer to be a long datatype, rather than an int datatype
  // int cannot save values as high as we need for (result * 249)
  // OCR0B cannot be larger than the value of OCR0A (249)
  OCR1B = ((result * 223L) / 1023L) + 96;
}


// This function automatically executes whenever the ADC has completed a conversion
// It is never called in the software code
ISR(ADC_vect) {
  volatile unsigned char LSByte = ADCL;
  volatile unsigned char MSByte = ADCH;
  result = (MSByte << 2) + (LSByte >> 6);
}
