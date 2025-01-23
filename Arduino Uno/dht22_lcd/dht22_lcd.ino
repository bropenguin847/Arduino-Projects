#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht DHT;

#define DHT22_PIN 5
#define relay 8

float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Initialize DHT22");
  delay(5000);
  lcd.setCursor(0,1);
  lcd.print("DHT22 activate");
  delay(2000);
  lcd.clear();
}

void loop() {
  DHT.read22(DHT22_PIN);

  temp = DHT.temperature;
  hum = DHT.humidity;
  Serial.println(DHT.humidity, 1);
  Serial.println(DHT.temperature, 1);

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(hum);
  delay(500);

  if (temp > 35){
    digitalWrite(relay, HIGH);
  }
  else{
    digitalWrite(relay, LOW);
  }
  lcd.clear();
}
