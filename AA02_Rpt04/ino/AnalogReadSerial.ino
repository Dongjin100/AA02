void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
 
int sensorValue = analogRead(A0);
Serial.print("AA02,Present V(0 ~ 5.0):");
float voltage = sensorValue*(5.0/1023.0);
Serial.println(voltage);
delay(500);
}
