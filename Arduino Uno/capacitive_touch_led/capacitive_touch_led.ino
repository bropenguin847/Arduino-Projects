int led=7;
int cap = 2;
int capStatus;

void setup() {f
  pinMode(led,OUTPUT);
  pinMode(cap, INPUT);
}

void loop() {
  capStatus = digitalRead(cap);
  
  if (capStatus == HIGH){
    // turn LED on
    digitalWrite(led,HIGH);
  } else{
    // otherwise, turn LED off
    digitalWrite(led,LOW);
  }
  delay(100);
}
