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
  ADMUX |= 0x00;

}

volatile unsigned int result = 0;

void loop() {
 
  //Beginnig of Serial
  unsigned char offset = 20;
  const unsigned char n= 50;
  static unsigned long x=0;
  static unsigned int ADCvalues [n] = {};
  ADCvalues[x%n] = result;
  int avg = ave(ADCvalues, n);
  //Equation to calculate Temperature
  int temp = ((4.89*result) - 500 + offset);

  unsigned char D = temp % 10;
  
  // wait 500ms
  _delay_ms(200);

  x++;
  
  //Clear the LCD screen
   lcd_clrscr();

  // Displays Pot. Value
   lcd_puts( "Temperature: " );

  //Creat an array that will save the ASCII encoding of each number
   char charBuffer[5];

//Creat an array that will save the ASCII encoding of each number
   char charBuffer2[5];

  //Converts value, in the given base, into the variable charBuffer[]
   itoa( temp, charBuffer, 10 );

  //Go to line 2 in LCD
   lcd_goto( 40);

  //Display result of string
   lcd_puts( charBuffer);

  //Go to line 2 in LCD
  lcd_goto(42);

  lcd_puts(".");

  //Converts value, in the given base, into the variable charBuffer[]
   itoa( D, charBuffer2, 10 );
  
  //Go to line 2 in LCD
  lcd_goto(43);

 //Display result of string
   lcd_puts( charBuffer2);
 
  //Converts value, in the given base, into the variable charBuffer[]
   itoa( D, charBuffer, 5 );
  
  //Go to line 2 in LCD
   lcd_goto( 44);

  // Displays character
   lcd_puts( "C" );

  //Wait 50 ms
   _delay_ms(50);


}

    
int ave( int arr[],unsigned char k){
  // Configure of sum
  unsigned long sum = 0;
  unsigned char j = 0;
  
  //
 while( j < k){
  sum+=arr[j];
  sum = sum / k;
  j++;
  return sum;
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
