// the setup routine runs once when you press rese
void setup() {                
  // initialize the digital pin as an output.
  pinMode(4, OUTPUT);
}
// the loop routine runs over and over again forever:
void loop() {  
  digitalWrite(4, HIGH);     // turn the LED on (HIGH is the voltage level)
  delay(2000);               // wait for a second
  digitalWrite(4, LOW);      // turn the LED off by making the voltage LOW
  delay(2000);               // wait for a second
}
