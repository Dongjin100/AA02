void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue=analogRead(A0);
Serial.print("AA02, present Value(0~1023):");
Serial.println(sensorValue);
delay(500);
}
