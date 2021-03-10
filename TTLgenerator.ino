/*
 * Arduino TTL Pulse Generator
 * PoC (proof of concept)
 * Lukasz Jablonski, Agata Witkowska
 * 
 * Upon TTL_IN signal TTL_OUT train will be generated with pulse width of DURATION_PULSE and inter-pulse interval of DURATION_IPI
 */

// Arduino Uno input and output pins
int TTL_IN = 8;
int TTL_OUT = 9;

// Set duration of states (ms) 
const int32_t DURATION_PULSE = 5000;
const int32_t  DURATION_IPI = 106000; // inter-pulse interval

void setup() {
  pinMode(TTL_IN, INPUT); // set TTL_IN as input
  pinMode(TTL_OUT, OUTPUT); // set TTL_OUT as output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(digitalRead(TTL_IN)){
    // DURATION_PULSE
    digitalWrite(TTL_OUT,HIGH);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(DURATION_PULSE);
    // DURATION_IPI
    digitalWrite(TTL_OUT,LOW);
    digitalWrite(LED_BUILTIN,LOW);
    delay(DURATION_IPI);
  }  
}
