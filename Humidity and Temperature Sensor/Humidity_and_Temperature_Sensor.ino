// include the library code:
#include <LiquidCrystal.h>

#include <Wire.h>
#include <dht.h>

#define DHT11PIN  7
dht1wire DHT(DHT11PIN, dht::DHT11);

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");

}

void loop() {
  
  DHT.read();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity = ");
  lcd.print(DHT.getHumidity()/10);
  lcd.setCursor(0,1);
  lcd.print("Temp = ");
  lcd.print(DHT.getTemperature()/10);

  delay(2000);  //delay 2seconds
}


