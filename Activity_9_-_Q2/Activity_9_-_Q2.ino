void setup() {
  // put your setup code here, to run once:
DDRD = 0x40;
TCCR0A = 0x42;
TCCR0B = 0x05;
OCR0A = 155;
}

void loop() {
  // put your main code here, to run repeatedly:

}
