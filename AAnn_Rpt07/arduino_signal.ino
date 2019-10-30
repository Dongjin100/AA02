/*
  Single Signal 
  Simulation of a random signal
*/
// signals
int data=0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // single random  signal
  data = random(-10,40);
  Serial.print("AA02, Signal: ");
  Serial.println(data);
  delay(1000);        // fs = 1 Hz
}
