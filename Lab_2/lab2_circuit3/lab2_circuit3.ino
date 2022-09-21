/*
  Lab 2, Circuit 3
  SKELETON CODE
  Modify this code to blink an LED at intervals corresponding to the analog value of a potentiometer
  Written by Alyssa J. Pasquale, Ph.D.
  May 22, 2017
*/

void setup()
{
  // Initialize ADCSRA with prescaler of 128
   ADCSRA = 0xEF;

  // Initialize ADMUX with reference voltage of AVcc
   ADMUX = 0x40;

  // Initialize ADCSRB into free-running mode
   ADCSRB = 0x00;

  // Configure your digital pin as an output
   DDRB = DDRB | 0x04;
   
  //Configure your analog pin as an input
   ADMUX = ADMUX | 0;
}

// Assigned result to equal 0
volatile unsigned int result = 0;

void loop()
{
  //Toggles the LED on pin D3
   PORTD = PORTD ^ 0x04;

  //Assigned i to equal 0
   unsigned int i=0;
  
  //If while is true it will follow the rest of the command
   while(i < result){
    
  //Wait 1000 unsecond = 1 millisecond
   _delay_us(1000);
  
  //Forces i to the value to be high
   i=i+1;
  }
}

// This function automatically executes whenever the ADC has completed a conversion
// It is never called in the software code
ISR(ADC_vect) {
  unsigned char LSByte = ADCL;
  unsigned char MSByte = ADCH;
  // depending on the value of ADLAR, the equation for result will be different
   result = ADCL + (ADCH << 8);
}

