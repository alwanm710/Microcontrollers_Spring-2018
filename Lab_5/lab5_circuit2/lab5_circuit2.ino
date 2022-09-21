/*
  Lab 5, Circuit 2
  Written by Alyssa J. Pasquale, Ph.D.
  Edited by Mohammad
  June 14, 2017
*/

  // Include the library that contains all of the LCD functions and constants
   #include "hd44780.h"

void setup()
{
  // Configure external interrupt registers
  // Rising edge triggered interrupts on pins D2 and D38
   EICRA |= 0x0F;

  // Enable interrupts INT0 and INT1
   EIMSK |= 0x03;

  // Enable pin change interrupts on port C
   PCICR |= 0x02;

  // Allows pin change interrupts on pins C0-C3
   PCMSK1 |= 0x0F;
   
  // initialize the LCD screen (sets the screen size, font, etc.)
   lcd_init();
   
}

volatile unsigned char a = 0;
volatile unsigned char b = 0;
volatile unsigned char K = 0;

void loop()
{
  // clear the screen
   lcd_clrscr();

   char c = 0;
   unsigned char d = 0;

   switch (K){

   case 1:
    c = a + b;
    d = '+';
    break;
    
   case 2:
    c = a - b;
    d = '-';
    break;

   case 4:
    c = a * b;
    d = '*';
    break;

   case 8:
    if ( b == 0){ 
    lcd_goto (40);
    
   // Displays "Does Not Exist" on LCD srceen
    lcd_puts("Does Not Exist");
   }
    else{
      c = a / b;
    }

    d = '/';
    break;

  default:
   c = a + b;
   d = '+';
   break;
   }

   lcd_goto (00);
  // convert a to a string, can only be 3 characters (0-11 and terminal character), then display
  char aBuffer[2];
  itoa(a, aBuffer, 10);
  lcd_puts(aBuffer);
  lcd_putc(d);
  
  // convert b to a string, can only be 3 characters (0-11 and terminal character), then display
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

ISR (PCINT1_vect){
  if (PINC != 0x00){
  // 
   K = PINC ^ 0x00;
  }
}

ISR(INT0_vect) {
  a = PIND >> 4;
}

ISR(INT1_vect) {
  b = PIND >> 4;
}
