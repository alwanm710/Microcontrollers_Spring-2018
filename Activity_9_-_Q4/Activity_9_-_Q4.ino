void setup() {
  // put your setup code here, to run once:
DDRB = 0x02;
TCCR1A = 0x42;
TCCR1B = 0x01;
OCR1AH=0x01;
OCR1AL=0x3F;
}

void loop() {
  // put your main code here, to run repeatedly:

}
