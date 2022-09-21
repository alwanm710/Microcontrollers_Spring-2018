#include "hd44780.h"

void setup() {
  //
   lcd_init();
  
  // Initialize ADCSRA with prescaler of 128
  ADCSRA = 0xEF;

  // Initialize ADMUX with reference voltage of AVcc
  ADMUX = 0x40;

  // Initialize ADCSRB into free-running mode
  ADCSRB = 0x00;

  // Configure your digital pin as an output
  DDRB |= 0x3F;

}

volatile unsigned int result = 0;

void loop() {
  //Clear the LCD screen
   lcd_clrscr();

  // Displays Pot. Value
   lcd_puts( "Pot. Value: " );

  //Creat an array that will save the ASCII encoding of each number
   char charBuffer[5];

  //Converts value, in the given base, into the variable charBuffer[]
   itoa( result, charBuffer, 10 );

  //Go to line 2 in LCD
   lcd_goto( 0x40);

  //Display result of string
   lcd_puts( charBuffer);

  //Wait 50 ms
   _delay_ms(50);





}

// This function automatically executes whenever the ADC has completed a conversion
// It is never called in the software code
ISR(ADC_vect) {
  unsigned char LSByte = ADCL;
  unsigned char MSByte = ADCH;
  // depending on the value of ADLAR, the equation for result will be different
  result = ADCL + (ADCH << 8);
}
