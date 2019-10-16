/*
  Multi Signals
  Simulation of multiple random signals
*/
// signals
int humi=0;
int temp=0;
int lux=0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // Multi signals
  humi = random(40,90);
  temp = random(-10, 30);
  lux = random(150,250);

  Serial.print(lux);
  Serial.print(",");
  Serial.print(humi);
  Serial.print(",");
  Serial.println(temp);
  delay(500);        // delay in between reads for stability
}
