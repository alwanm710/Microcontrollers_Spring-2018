
  void setup() {
  
  // Initialize ADCSRA with prescaler of 128
  ADCSRA = 0xEF;

  // Initialize ADMUX with reference voltage of AVcc
  ADMUX = 0x40;

  // Initialize ADCSRB into free-running mode
  ADCSRB = 0x00;

  // Configure your digital pin as an output
  ADMUX |= 0x00;

  
  
  
}

volatile unsigned int result = 0;

void loop(){
   //Beginnig of Serial
   Serial.begin(9600);
  const unsigned char n=30;
  static unsigned long x=0;
  static unsigned int ADCvalues [30];
  ADCvalues[x%n] = result;
  int avg = ave(ADCvalues, n);
  //Equation to calculate Temperature
  int temp = ((0.489*result) - 50);
  //Finish of Serial
  Serial.println(temp);
  // wait 500ms
  _delay_ms(500);

  x++;


}

int ave( int arr[],unsigned char k){
  // Configure of sum
  unsigned long sum = 0;
  
  //
 for(unsigned char j = 0; j < k; j++){
  sum+=arr[j];
  sum = sum / k;
  return sum;
 }
  
}
// This function automatically executes whenever the ADC has completed a conversion
// It is never called in the software code
ISR(ADC_vect) {
  unsigned char LSByte = ADCL;
  unsigned char MSByte = ADCH;
  // depending on the value of ADLAR, the equation for result will be different
  result = ADCL + (ADCH << 8);
}
