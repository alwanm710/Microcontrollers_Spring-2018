/*
  Lab 5, Circuit 1
  External interrupt falling-edge triggered adder using a keypad with 74C922 outputs A-D connected to pins D4-D7, respectively
  Output displays on an LCD screen connected to pins D8-D13
  Written by Alyssa J. Pasquale, Ph.D.
  June 14, 2017
*/

// include the library that contains all of the LCD functions and constants
#include "hd44780.h"

void setup()
{
  // configure external interrupt registers
  // rising edge triggered interrupts on pins D2 and D3
  EICRA |= 0x0F;

  // enable interrupts INT0 and INT1
  EIMSK |= 0x03;

  PCICR |= 0x02;// enables pin change interupts on port c
  PCMSK1 |= 0x0F; // allows pin change interupts on pins c0- c3

  // initialize the LCD screen (sets the screen size, font, etc.)
  lcd_init();
}

volatile unsigned char a = 0;
volatile unsigned char b = 0;

volatile unsigned char result = 0;


void loop()
{
//   clear the screen
  lcd_clrscr();

char c = 0;
unsigned char K = 0;
  // Switch case
  switch (result) {

    case 1:
      c = a + b;
      K = '+';

      break;

    case 2:
      c = a - b;
      K = '-';

      break;

    case 3:
      c = a * b;
      K = '*';

      break;
     

    case 4:
      if ( b == 0){
        lcd_goto(40);
        lcd_puts ("Error");
      }
      else
      {
        c = a / b;
      }
      
      K = '/';

      break;

      default:
      c = a*b;
      result ='*';
      break;
      
      }
       //convert a to a string, can only be 3 characters (0-11 and terminal character), then display
      char aBuffer[2];
      itoa(a, aBuffer, 10);
      lcd_puts(aBuffer);
      lcd_puts(K);

      //convert b to a string, can only be 3 characters (0-11 and terminal character), then display
      char bBuffer[3];
      itoa(b, bBuffer, 10);
      lcd_puts(bBuffer);
     lcd_puts("=");



      // convert c to a string, can only be 3 characters (0-22 and terminal character), then display
      char cBuffer[3];
      itoa(c, cBuffer, 10);
      lcd_puts(cBuffer);

     _delay_ms(500);
}

ISR(INT0_vect) {
  a = PIND >> 4;
}

ISR(INT1_vect) {
  b = PIND >> 4;
}
ISR (PCINT1_vect) {
  if (PINC != 0) {
    result = PINC ^ 0x00;
  }
}


