/*
 * Jeff, Mohammad
 * Activity 2
 * INnputs from a DIP switch change the color of an RGB  LED
 * OUtputs: D7-D5
 * Inputs: D13-D12 (A), D10-D8 (B)
 */

void setup() {

  DDRD |= 0b11100000; //outputs to rbg led

}

void loop() {

  unsigned char a, b, c;
  a = PINB & 0b00000111; //inputs from a
  b = PINB & 0b00111000; //inputs from b
  c = ( b >> 3 ); //bitshift b to isolate those inputs

  if ( a > c )
  {
    PORTD |= 0b10000000; //if a > c light is red
    }
  if ( a < c )
  {
    PORTD |= 0b01000000; // if a < c light is green
  }
  if ( a == c )
  {
    PORTD |= 0b00100000; //if a = c light is blue
    }

  PORTD &= 0x00; // clears all outputs so that only one color is lit at a time


}
