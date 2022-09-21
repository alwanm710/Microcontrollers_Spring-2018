/*
  Lab 3, Circuit 1
  Display digits 0-F on a (common-cathode or common-anode) 7-segment display
  Written by Alyssa J. Pasquale, Ph.D.
  June 5, 2017
  Edited: November 17, 2017
*/

void setup()
{
  // Configure your output pins
  DDRD |= 0xFF;
}

void loop()
{
  // Define an array with display values for each numeral from 0-F
  // This data will come from Activity 4
  unsigned char numeralArray[16] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6, 0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E };
  // Define an index to use with the while loop
  unsigned char j = 0;

  while (j < 16) {
    PORTD = numeralArray[j];
    j++;
    _delay_ms(500);
  }
}

