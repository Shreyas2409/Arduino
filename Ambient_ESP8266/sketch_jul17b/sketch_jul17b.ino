const int switchPin = 2; 
const int ledPin = 13; 
int switchState = 0; 
void setup()
{
    pinMode(ledPin, OUTPUT); 
    pinMode(switchPin, INPUT);
   
}
void loop()
{
    switchState = digitalRead(switchPin);
    if (switchState == LOW) 
    {
        digitalWrite(ledPin, HIGH); 
        delay(3000); 
        digitalWrite(ledPin, LOW);
    }
}
