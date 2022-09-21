void setup() {
  
  // Configure external interrupt registers
  // Rising edge triggered interrupts on pins D2 and D38
   EICRA |= 0x01;

  // Enable interrupts INT0 and INT1
   EIMSK |= 0x01;

  // Enable pin change interrupts on port C
   PCICR |= 0x01;

  // Allows pin change interrupts on pins C0-C3
   PCMSK1 |= 0x07;

   DDRC |= 0x07;

}

void loop() {

}

ISR (PCINT0_vect){
  PORTC ^= 0x07;
  
}

ISR (PCINT1_vect){
  PORTC ^= 0x07;
  
}

ISR (PCINT2_vect){
  PORTC ^= 0x07;
  
}

