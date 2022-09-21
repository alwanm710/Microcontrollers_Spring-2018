/*
  Lab 2, Circuit 1
  Using a pushbutton (connected to D8) to turn on/off an LED (connected to D13)
  Written by Alyssa J. Pasquale, Ph.D.
  May 15, 2017
  Edited: November 17, 2017
*/

void setup()
{
  // Set DDRB bit 5
  // This causes Arduino pin D13 to be an output
  DDRB = DDRB | 0b00100000;
}

void loop()
{
  //Read value from pushbutton (D8)
  unsigned char buttonState = PINB & 0b00000001;
  if (buttonState == 1) {
    //Turn on LED
    PORTB = PORTB | 0b00100000;
  }
  else {
    //Turn off LED
    PORTB = PORTB & 0b11011111;
  }
}




