
/*
Mohammad Alwan
Test, Circuit 1


*/
void setup() {
  //Global interrupts are disabled
  cli();
  
  // Initialize ADCSRA with prescaler of 128
  ADCSRA = 0xEF;

  // Initialize ADCSRB into free-running mode
  ADCSRB = 0x00;
  
PCICR = 0x01;
PCMSK0 = 0x03;

    // Input the value of the analog pin you will use (possible values: 0-5)
  unsigned char yourAnalogPin = 3;

  // Configures ADMUX to operate on your chosen analog pin
  ADMUX |= yourAnalogPin;

}

volatile unsigned int result = 0;
char LightButton = (PCICR);
char TempButton = (PCMSK0);

void loop() {
 
 while (TempButton = 1){
  //Serial Monitor begins
  Serial.begin(9600);

  const unsigned char n= 50;
  static unsigned long x=0;
  static unsigned int ADCvalues [n] = {};
  ADCvalues[x%n] = result;
  int avg = ave(ADCvalues, n);
  //Equation to calculate Temperature
  int temp = ((4.89*result) - 500 );

   Serial.println(temp);
 }

 
while (LightButton = 1){
  Serial.begin(9600);
  
// Saves result to ADC
  const unsigned char n= 10;
  static unsigned long x=0;
  static unsigned int ADCvalues [n] = {};
 
 // Rolling average 
  ADCvalues[x%n] = result;
  int avg = ave(ADCvalues, n);

 //Equation to calculate light value
 int Light = ((0.1 * result) + 4.37);
  
  // Wait 200 ms
  _delay_ms(200);

  x++;

   Serial.println(Light);
  }
}

int ave( int arr[],unsigned char k){
  // Configure of sum
  unsigned long sum = 0;
  unsigned char j = 0;
  
  //
 while( j < k){
  sum+=arr[j];
  sum = sum / k;
  j++;
  return sum;
 }
}



ISR(PCINT0_vect){
  ADMUX ^= 0x03;
  // This function automatically executes whenever the ADC has completed a conversion
// It is never called in the software code
  unsigned char LSByte = ADCL;
  unsigned char MSByte = ADCH;
  // depending on the value of ADLAR, the equation for result will be different
  result = ADCL + (ADCH << 8);
}




