#include <dht.h>
#include <LiquidCrystal.h>

// Defining characteristics of the DHT11 sensor
#define dht_pin 13
#define DHTTYPE DHT11

// Creating an instance of the DHT sensor and the lcd screen
dht DHT;
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  // Set baud rate for serial communication and delay for one second to give the Arduino time to start up
  Serial.begin(9600);
  delay(1000);

  // Start the lcd
  lcd.begin(16,2);
}

void loop() {
  // Read the data from the sensor
  DHT.read11(dht_pin);
  
  // Set variables for the temperature (converted to Fahrenheit) and humidity
  int temp = DHT.temperature * 1.8 + 32;
  int humid = DHT.humidity;

  // Print out the temperature data on the top line
  lcd.setCursor(0,0);
  lcd.print("Temp:     ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("F");

  // Print out the humidity data on the second line
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humid);
  lcd.print(" ");
  lcd.print((char)37);

  // Delay 5 seconds between reads
  delay(5000);
} 
