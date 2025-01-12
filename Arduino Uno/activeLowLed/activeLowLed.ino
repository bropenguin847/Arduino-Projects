//Active Low LED

int adcVal;
#define led1 15
#define alwaysHigh 14
#define highAlways 19
int led2 = 18;

void setup()
{
  Serial.begin(9600);
  pinMode(A3, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(alwaysHigh, OUTPUT);
  pinMode(highAlways, OUTPUT);
  
  digitalWrite(alwaysHigh, HIGH);
  digitalWrite(highAlways, HIGH);
}

void loop()
{
  adcVal = analogRead(A3);
  Serial.print("\nNilai ADC: ");
  Serial.println(adcVal);

  if(adcVal >= 650)
  {
    Serial.print("Lamp ON");
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  else
  {
    Serial.print("Lamp OFF");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  delay(500);
}
