#include <dht.h>
#include <LiquidCrystal.h>

#define dht_pin 13
#define DHTTYPE DHT11

dht DHT;
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);

  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(dht_pin);
  int temp = DHT.temperature * 1.8 + 32;
  int humid = DHT.humidity;

  lcd.setCursor(0,0);
  lcd.print("Temp:     ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("F");

  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humid);
  lcd.print(" ");
  lcd.print((char)37);

  delay(5000);
} 
