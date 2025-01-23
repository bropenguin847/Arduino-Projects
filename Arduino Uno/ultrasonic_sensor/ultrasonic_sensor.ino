#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define trigPin 14
#define echoPin 15
#define ledReady 13
#define ledMeasure 8

// declare variable
unsigned long travelTime;
unsigned long duration;
float distance;
float height;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledReady, OUTPUT);
  pinMode(ledMeasure, OUTPUT);

  lcd.init();
  lcd.backlight();

  digitalWrite(ledReady, HIGH);
}
  
void loop()
{
  digitalWrite(trigPin,LOW);          //ready sensor & lcd
  delay(2);
  
  digitalWrite(trigPin,HIGH);         //start sensor for 10ms
  delay(10);
  digitalWrite(trigPin,LOW);          // no output
  
  travelTime = pulseIn(echoPin,HIGH);
  duration = travelTime / 2;
  distance =  duration * 0.0343;

  Serial.print("Distance = "); 
  Serial.print(distance, 1);
  Serial.println(" cm");

  height = 20 - distance;
  Serial.print("Height = "); 
  Serial.print(height, 1);
  Serial.println(" cm\n");
  
  if(distance <= 20)
  {
    digitalWrite(ledMeasure, HIGH);
    lcd.setCursor(3, 0);
    lcd.print("LCD:");
    lcd.setCursor(8, 0);
    lcd.print(height, 1);
    lcd.setCursor(12, 0);
    lcd.print("cm");
    lcd.setCursor(1, 1);
    lcd.print("L1: ON");
    lcd.setCursor(8, 1);
    lcd.print("L2: ON");
  }
  else
  {
    digitalWrite(ledMeasure, LOW);
    lcd.setCursor(3, 0);
    lcd.print("LCD: READY");
    lcd.setCursor(1, 1);
    lcd.print("L1: ON");
    lcd.setCursor(8, 1);
    lcd.print("L2: OFF");
  }

  delay(860);
  lcd.clear();
}
