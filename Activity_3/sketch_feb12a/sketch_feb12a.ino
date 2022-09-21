void setup() {
  // Conforme all pins in PortD;
   DDRD = DDRD | 0xFF
  // Arraying the out puts;
   unsigned char myArry [16] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6, 0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E};
}

void loop() {
  // Display number 0 on 7-Segment:
   PORTD = myArry [0];
  // Wait 1 second
  _delay_ms(1000);
  // Display number 1 on 7-Segment:
   PORTD = myArry [1];
  //Wait 1 second
  _delay_ms(1000);
  // Display number 2 on 7-Segment:
   PORTD = myArry [2];
  //Wait 1 second
  _delay_ms(1000);
  // Display number 3 on 7-Segment:
   PORTD = myArry [3];
  //Wait 1 second
  _delay_ms(1000);
  // Display number 4 on 7-Segment:
   PORTD = myArry [4];
  //Wait 1 second
  _delay_ms(1000);
  // Display number 5 on 7-Segment:
   PORTD = myArry [5];
  //Wait 1 second
  _delay_ms(1000);
  // Display number 6 on 7-Segment:
   PORTD = myArry [6];
  //Wait 1 second
  _delay_ms(1000);
  // Display number 7 on 7-Segment:
   PORTD = myArry [7];
  //Wait 1 second
  _delay_ms(1000);
  // Display number 8 on 7-Segment:
   PORTD = myArry [8];
  //Wait 1 second
  _delay_ms(1000);
  // Display number 9 on 7-Segment:
   PORTD = myArry [9];
  //Wait 1 second
  _delay_ms(1000);
  // Display letter A on 7-Segment:
   PORTD = myArry [10];
  //Wait 1 second
  _delay_ms(1000);
  // Display letter b on 7-Segment:
   PORTD = myArry [11];
  //Wait 1 second
  _delay_ms(1000);
  // Display letter C on 7-Segment:
   PORTD = myArry [12];
  //Wait 1 second
  _delay_ms(1000);
  // Display letter d on 7-Segment:
   PORTD = myArry [13];
  //Wait 1 second
  _delay_ms(1000);
  // Display number E on 7-Segment:
   PORTD = myArry [14];
  //Wait 1 second
  _delay_ms(1000);
  // Display number F on 7-Segment:
   PORTD = myArry [15];
  //Wait 1 second
  _delay_ms(1000);
  
}
