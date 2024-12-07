#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h> 
#include <DHT.h>
#include <Adafruit_BMP085.h>

LiquidCrystal_I2C LCD(0x27,16,2);
DHT dht(2,DHT22);
RTC_DS1307 rtc;
Adafruit_BMP085 bmp;
void setup() {
  LCD.init();
  LCD.backlight();
  rtc.begin();
  dht.begin();
  bmp.begin();
}
void loop() {
  DateTime now = rtc.now();

  LCD.setCursor(0,0);
  int hours = now.hour();
  int minutes = now.minute();
  int seconds = now.second();
  if (hours <= 9 )
  {
    LCD.print("0");
  }
  LCD.print(hours);
  LCD.print(":");
  if (minutes <= 9 )
  {
    LCD.print("0");
  }
  LCD.print(minutes);
  LCD.print(":");
  if (seconds <= 9 )
  {
    LCD.print("0");
  }
  LCD.print(seconds);
  
  LCD.print(" ");

//температура
  float t = dht.readTemperature();
  LCD.print(t,1);
  LCD.print("C");

//давление
  LCD.setCursor(0,1);
  long p = bmp.readPressure();
  LCD.print(p/100);
  LCD.print("hPa");

  LCD.print(" ");

//влажность
  float hum = dht.readHumidity();
  LCD.print("h");
  LCD.print(hum,1);
  LCD.print("%");

  delay(1000);
  LCD.clear();
}