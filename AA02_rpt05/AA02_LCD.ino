#include <LiquidCrystal_I2C.h>

#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2); //LCD 클래스 초기화, 0x3F

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Hello World!");
  
 lcd.setCursor(0,1);
lcd.print("Hi AA02!");
}

void loop() {
  delay(10);
}
