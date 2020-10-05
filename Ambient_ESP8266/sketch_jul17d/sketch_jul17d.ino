const int pin=2;
const int pin2=13;
int val=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(pin);
  digitalWrite(pin2,HIGH);
  delay(val);
  digitalWrite(pin2,LOW);
  Serial.println(val);
  delay(val);
  

}
