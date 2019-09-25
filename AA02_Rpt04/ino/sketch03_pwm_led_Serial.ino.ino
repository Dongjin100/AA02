int pwm = 0;
int led = 3;


void setup() {
Serial.begin(9600);
}

void loop() {
pwm = random(0,255);
pwmLed(led, pwm);

  Serial.print("AA02,LED: ");
  Serial.println(pwm);
  delay(10);
}
void pwmLed(int led, int pwmValue){
  analogWrite(led, pwmValue);
  delay(10);
}
