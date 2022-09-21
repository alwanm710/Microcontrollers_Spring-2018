/* Lab 4, circuit 2
 *  Mohammad, Luis
 *  Photoresistor Calibration & Light level measurements
 */


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


}

volatile unsigned int result = 0;

void loop() {

// Saves result to ADC
  const unsigned char n= 10;
  static unsigned long x=0;
  static unsigned int ADCvalues [n] = {};
 
 // Rolling average 
  ADCvalues[x%n] = result;
  int avg = ave(ADCvalues, n);

 //Equation to calculate light value
 int Light = ((0.1 * result) + 4.37);
  
  // Wait 200 ms
  _delay_ms(200);

  x++;
  
  //Clear the LCD screen
   lcd_clrscr();

  // Displays Power 
   lcd_puts( "Light Level: " );

  //Creat an array that will save the ASCII encoding of each number
   char charBuffer[5];

  //Converts value, in the given base, into the variable charBuffer[]
   itoa( Light, charBuffer, 10 );

  //Go to line 2 in LCD
   lcd_goto( 40);

  //Display result of string
   lcd_puts( charBuffer);

  //Go to line 2 in LCD behind the value
   lcd_goto( 43);

  //Display unit
   lcd_puts( "%");
   
  //Wait 50 ms
   _delay_ms(50);


}

    
int ave( int arr[],unsigned char k){
  // Configure of sum
  unsigned long sum = 0;
  unsigned char j = 0;
  
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