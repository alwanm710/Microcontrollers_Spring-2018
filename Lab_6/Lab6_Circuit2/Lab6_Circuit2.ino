/* La 6, Circuit 2
    Circuit 2: Calculating Time Between Events
    Find
    By Mohammad, Robert, Evelyn
    3/7/2018
*/





#include "hd44780.h"

volatile long tks[2];
volatile long ticks = 0;


void setup() {
  //

  cli();



  // Initialize ADCSRA with prescaler of 128
  ADCSRA = 0xEF;

  // Initialize ADMUX with reference voltage of AVcc
  ADMUX = 0x40;

  // Initialize ADCSRB into free-running mode
  ADCSRB = 0x00;

  //Configure timer/counter 2 control register A
  TCCR2A |= 0x00;

  //Configure timer/counter 2 control register B
  TCCR2B |= 0x01;

  //Configure timer/counter 2 interrupt mask register B
  TIMSK2 |= 0x01;

  EICRA = 0x03;

  EIMSK = 0x01;
  sei();

  lcd_init();
}

volatile int result = 0;

void loop() {

  double tksElapsed = 0;
  if ((tks[1] - tks[0]) > 0) {
    tksElapsed = tks[1] - tks[0];

  }
  else {
    tksElapsed = tks[0] - tks[1];
  }


  double  sec = tksElapsed * 0.00000000625;


  //Clear the LCD screen
  lcd_clrscr();

  char charBuffer[6];

  dtostrf( sec, 1, 2, charBuffer);
  // Displays Pot. Value
  lcd_puts( "Time (s)" );

  //Creat an array that will save the ASCII encoding of each number


  //Go to line 2 in LCD
  lcd_goto(40);

  //Display result of string
  lcd_puts(charBuffer);

  //Wait 150 ms
  _delay_ms(150);



}




ISR(TIMER2_OVF_vect) {
  ticks += 255;
}

ISR(INT0_vect) {
  static unsigned long x = 0;
  unsigned long curTicks = ticks + TCNT2;
  tks[x % 2] = curTicks;
  x++;
}



