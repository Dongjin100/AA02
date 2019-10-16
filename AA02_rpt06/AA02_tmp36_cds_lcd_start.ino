/*
 온도, 빛 입력 LCD 모니터링 및 제어
*/
 // LCD 라리브러리 설정
#include <LiquidCrystal_I2C.h>
#include<Wire.h>
// LCD 설정
LiquidCrystal_I2C lcd(0x27,16,2); // 0x3F
// 0번 아날로그핀을 TMP36 온도 입력으로 설정한다.
// 1번 아날로그핀을 CdS 조도 입력으로 설정한다.
#define TMP36_INPUT 0  // A0
#define CDS_INPUT 1    // A1

void setup() { 
  Serial.begin(9600);
// 16X2 LCD 모듈 설정하고 백라이트를 켠다.
  lcd.init();
  lcd.backlight();
// 모든 메세지를 삭체한 뒤
// 숫자를 제외한 부분들을 미리 출력시킨다.
lcd.clear();
lcd.setCursor(0,0);
lcd.print("AA02, Temp: ");
lcd.setCursor(0,1);
lcd.print("Light: ");
lcd.setCursor(13,1);
lcd.print("lux");

}

void loop(){
  // Temperature from TMP36
  int temp_value = analogRead(TMP36_INPUT);
  // converting the analog value to voltage
  float voltage = temp_value * 5.0 * 1000;  // in mV
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10 ;  // in C

  // Lux from CdS (LDR)
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));  // in lux

  // Monitoring via LCD
  // 전에 표시했던 내용을 지운다.  
  lcd.setCursor(12,0);
  lcd.print("    "); 
  // 온도를 표시한다  
  lcd.setCursor(12,0);
  lcd.print(tempC);

  
  // 전에 표시했던 내용을 지운다.
  lcd.setCursor(9,1);  
  lcd.print("   ");
  // 조도를 표시한다  
  lcd.setCursor(9,1);
  lcd.print(lux);


     

  // Serial output --> 온도,조도
Serial.print(tempC);
Serial.print(",");
Serial.println(lux);

  
  delay(1000);
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10;  
  // lux = 500 / Rldr, 
  // Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
