/*
  Lab 1, Circuit 3
  Traffic Light Circuit 
  Set DDRD bit 5 & 4 on
  D7= Main Red, D6= Main Yellow, and D5= Main Green
  D4= Side Red, D3= Side Yellow, and D2= Side Green
  D1 & D0= Don't Care
  Written by Mohammad Alwan
  January 31, 2018
*/

void setup()
{
  
  // Configure register D outputs
  DDRD = DDRD | 0b11111100;
}

void loop()
{
  //Turn on Main Green, Turn on Side Red, and Turn off all Others
  PORTD = PORTD | 0b00110000;
  //wait for 5000 ms
  _delay_ms(5000);

  //Turn on Main Yelllow, Turn on Side Red, and Turn off all Others
  PORTD = PORTD ^ 0b01100000;
  //wait for 2000 ms
  _delay_ms(2000);

  //Turn on Main Red, Turn on Side Green, and Turn off all Others
  PORTD = PORTD ^ 0b11010100;
  //wait for 5000 ms
  _delay_ms(5000);

  //Turn on Main Red, Turn on Side Yellow, and Turn off all Others
  PORTD = PORTD ^ 0b00001100;
  //wait for 2000 ms
  _delay_ms(2000);

  //Made to reset the traffic lights before loop 
  PORTD = PORTD ^ 0b10111000;
  //wait for 100 ms
  _delay_ms(100);
  }



