/*
This code uses dht22, I2C LCD and a relay
*/
#include <dht.h>
#include <Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht DHT;

#define DHT22_PIN 2
#define led1 12
#define led2 11
#define led3 10
int ldr = A0;
int relay = 3;

const int button1 = 7;
const int button2 = 6;

int buttonState1 = 0;
int buttonState2 =0;

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value
int ldrValue = 0; // variable to store the value coming from the sensor
int newldr;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("EE-021-4:2012");
  lcd.setCursor(0,1);
  lcd.print("AMALI AKHIR T4");
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(relay, OUTPUT);
}

void loop()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);

    while (buttonState1 == HIGH && buttonState2 == LOW){
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);

      int chk = DHT.read22(DHT22_PIN);  //Read data and store to hum and temp
      hum = DHT.humidity;
      temp= DHT.temperature;
      ldrValue = analogRead(ldr); // read the value from the sensor
      newldr = ldrValue*100/500;

      if (ldrValue < 250){
        digitalWrite(led3, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Lembap: ");
        lcd.print(hum);
        lcd.print("%");
    
        lcd.setCursor(0,1);
        lcd.print("Suhu: ");
        lcd.print(temp);
        lcd.print("C");
        delay(1500);

        Serial.println(newldr); //prints the values on serial monitor
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Low Lighting");
        delay(900);

        buttonState2 = digitalRead(button2);//refresh the status of button2
      }

      else{
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Lembap: ");
        lcd.print(hum);
        lcd.print("%");
    
        lcd.setCursor(0,1);
        lcd.print("Suhu: ");
        lcd.print(temp);
        lcd.print("C");
        delay(1500);

        Serial.println(newldr); //prints the values on serial monitor
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Cerah: ");
        lcd.print(newldr);
        lcd.print("%");
        delay(900);
      
        buttonState2 = digitalRead(button2);//refresh the status of button2
      }
    }
    
    if (buttonState2 == HIGH){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("EE-021-4:2012");
      lcd.setCursor(0,1);
      lcd.print("AMALI AKHIR T4");
      delay(500);
    }
}
