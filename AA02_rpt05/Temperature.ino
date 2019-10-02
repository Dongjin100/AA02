#define TEMP_INPUT 0

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int value = analogRead(TEMP_INPUT);
Serial.println(value);

delay(1000);
}
