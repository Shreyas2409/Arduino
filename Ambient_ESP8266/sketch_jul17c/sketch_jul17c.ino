const int switchPin = 2; 
const int ledPin = 12; 
int switchState = 0; 
void setup()
{
    pinMode(ledPin, OUTPUT); 
    pinMode(switchPin, INPUT);
    Serial.begin(9600);
}
void loop()
{
    switchState = digitalRead(switchPin); 
    if (switchState == LOW) 
    {
        digitalWrite(ledPin, HIGH); 
        delay(3000);
        Serial.println(switchState);
        
    } 
    else{
        digitalWrite(ledPin, LOW); 
        delay(3000);
        Serial.println(switchState);

        
    }
    
}

