/*
  Lab 13, Circuit 1
  This code uses TCNT1 input capture unit to determine pulse-width
    of HIGH pulse of signal from a function generator
  TCNT1 input capture prescaler: 256
  Input capture pin: D8
  Written by Alyssa J. Pasquale, Ph.D.
  November 14, 2017
*/

void setup() {
  TCCR1A = 0;
  // input capture enabled, rising-edge triggered
  // prescaler of 256 (shortest pulse = 16 us, longest pulse = 1.05 s)
  TCCR1B = 0xC4;
  // enable input capture interrupt
  TIMSK1 = 0x21;
}

volatile unsigned int captT[2] = {};

void loop() {
  static int timeBetween = 0;

  // calculates number of clock ticks between rising-edge and falling-edge
  if (captT[1] > captT[0]) {
    timeBetween = captT[1] - captT[0];
  }

  // timePassed gives time in ms
  float timePassed = (float) timeBetween * 256.0 / 16000.0;
}

ISR(TIMER1_CAPT_vect) {
  static unsigned long x = 0;
  unsigned int tLo = ICR1L;
  unsigned int tHi = ICR1H;

  if ((x % 2) == 0) {
    // captured on RISING edge
    captT[0] = tLo + (tHi << 8);
    // switch to FALLING-edge trigger
    TCCR1B &= 0xBF;
  }
  else {
    // captured on FALLING edge
    captT[1] = tLo + (tHi << 8);
    // switch to RISING-edge trigger
    TCCR1B |= 0x40;
  }

  x++;
}

