int humi=0;
int temp = 0;
int lux=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
humi = random(40,90);
temp = random(-10,30);
lux = random(150,250);
Serial.print("AA02, Ambient lux: ");
Serial.print(lux);
Serial.print(" , Humidity: ");
Serial.print(humi);
Serial.print(" , Temperature: ");
Serial.println(temp);
delay(500);
}
