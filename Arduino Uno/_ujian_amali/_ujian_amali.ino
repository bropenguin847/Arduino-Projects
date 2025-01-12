#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C mylcd (0x27, 16, 2);
#define sw1 3
#define sw2 4
#define sw3 14
#define led1 8
#define led2 9
#define led3 10

void setup()
{
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  mylcd.init();
  mylcd.backlight();
  mylcd.setCursor(1, 0);
  mylcd.print("MICROCONTROLLER");
  mylcd.setCursor(1, 1);
  mylcd.print("SISTEM SEDIA");
  digitalWrite(led1, HIGH);

  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(sw1)==HIGH)
  {
    mylcd.clear();
    mylcd.setCursor(2, 0);
    mylcd.print("SISTEM MULA");

    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }

  if(digitalRead(sw2)==HIGH)
  {
    mylcd.clear();
    mylcd.setCursor(1, 0);
    mylcd.print("Silinder 1 OFF");

    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }

  if(digitalRead(sw3)==HIGH)
  {
    mylcd.clear();
    mylcd.setCursor(1, 0);
    mylcd.print("MICROCONTROLLER");
    mylcd.setCursor(1, 1);
    mylcd.print("SISTEM SEDIA");

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  delay(200);
}
