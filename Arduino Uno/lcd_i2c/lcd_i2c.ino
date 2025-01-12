#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
  lcd.init(); // initialize the lcd
  // lcd.begin();
  lcd.backlight();
}

void loop()
{
  lcd.setCursor(3, 0);
  lcd.print("welcome");
  delay(1000);
  lcd.setCursor(3, 1);
  lcd.print("user");
  delay(1000);

  lcd.clear();

  delay(1000);
  lcd.setCursor(1, 0);
  lcd.print("^-^");  
}
