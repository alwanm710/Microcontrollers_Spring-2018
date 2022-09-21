/*
  Lab 8, Circuit 3
  Circuit 3: Porportional-Integral Control of light levels
*/

void setup()
{
  // Initialize ADCSRA with prescaler of 128, Set ADEN, ADSC, ADATE and ADIE
  ADCSRA |= 0xEF;

  // Initialize ADMUX with reference voltage of AVcc, set ADLAR
  ADMUX |= 0x60;

  // Input the value of the analog pin you will use (possible values: 0-5)
  unsigned char yourAnalogPin = 5;
  // Configures ADMUX to operate on your chosen analog pin
  ADMUX |= yourAnalogPin;

  // Initialize ADCSRB into free-running mode
  ADCSRB &= 0xF8;

  // Configure TCCR0A: Fast PWM to 0xFF, non-inverting mode for OC1A
  TCCR0A = 0x83;

  // Configure TCCR0B: no force compares, prescaler of 8
  TCCR0B = 0x02;

  // This causes pin D6 to be output pins
  DDRD |= 0x40;

  // Start with LED in D6 (OC0A) as fully on
  OCR0A = 0xFF;

  Serial.begin(9600);
}

volatile unsigned int result = 0;

// pV is the process variable (8-bit value from ADC)
volatile unsigned char pV = 0;
// err is the amount of error: setpoint - process variable
volatile int err = 0;
// tau is the amount of times the error will be recorded
unsigned const char tau = 5;
//Array of errors
volatile int errHist[tau];

void loop()
{
  // setpoint should be between 90% of the photocell ON ADC result, in 8 bits
  unsigned char sP = 673;

  // convert the process variable to 8 bits to be
  // directly comparable with sP and OCR0A
  pV = (result * 255L) / 1024L;
  err = sP - pV;

  // this is the value of the proportionality constant * 10
  // tune this variable until you obtain stable results
  unsigned char Kp = ;

  // finds a new value for the PWM duty cycle of the LED, scaled with the value of Kp and error
  OCR0A += ((Kp * err) / 10);

  Serial.print(pV);
  Serial.print('\t');
  Serial.println(sP);
}

// This function automatically executes whenever the ADC has completed a conversion
// It is never called in the software code
ISR(ADC_vect) {
  volatile unsigned char LSByte = ADCL;
  volatile unsigned char MSByte = ADCH;
  result = (MSByte << 2) + (LSByte >> 6);
}


int calcSum (int*array){
  int tempVar = 0;

  for (unsigned char j =0; j < tau; j++){
    tempVar += array[j];
  }
  return tempVar;
}

