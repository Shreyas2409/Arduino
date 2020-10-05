void setup() {
  // put your setup code here, to run once:
pinMode(12,OUTPUT);
pinMode(11,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(11)==LOW)
  {
    delay(500);
    while(digitalRead(11)==LOW)
    {
      digitalWrite(12,HIGH);
      delay(00);
      digitalWrite(12,LOW);
      delay(00);
      
    }
  }

}
