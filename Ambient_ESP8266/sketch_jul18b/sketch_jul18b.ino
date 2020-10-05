#include <Servo.h>

Servo myservo;  

int pos = 3;  
void setup() {
  myservo.attach(pos);  
}

void loop() {
 
    myservo.write(0);              
    delay(1); 
                       
  
    myservo.write(90);              
    delay(1);                       
    myservo.write(180);              
    delay(1);                       
  
}
