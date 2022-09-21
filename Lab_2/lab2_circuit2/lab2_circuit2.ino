/*
  Lab 2, Circuit 2
  Using a pushbutton (connected to D8) to turn on/off an LED (connected to D13)
  Written by Alyssa J. Pasquale, Ph.D. 
  Edited by Mohammad Alwan
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
  //Read value from Dipswitch (D10)
  unsigned char ToggleState = PINB & 0b00000100;
  if (ToggleState == 4) {
  //Read value from BottonState (D8 & D9)
  unsigned char buttonState = PINB & 0b00000011;
  if (buttonState > 0) {
  //Turn on LED
  PORTB = PORTB | 0b00100000;
  }
  else { //Turn off LED
    PORTB = PORTB & 0b11011111;
  }
}

  else {
  //Read value from BottonState (D8 & D9)
  unsigned char buttonState = PINB & 0b00000011;
  if (buttonState == 1) {
  //Turn on LED
  PORTB = PORTB | 0b00100000;
  }
  else if (buttonState == 2) {
  //Turn on LED
  PORTB = PORTB | 0b00100000;
  }
  else { //Turn off LED
    PORTB = PORTB & 0b11011111;
  }
}
}

