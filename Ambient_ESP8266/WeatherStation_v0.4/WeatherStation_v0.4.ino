#include <LCD5110_Basic.h>
#include "DHT.h"
#include "RTClib.h"
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
#define DHTPIN 2
#define DHTTYPE DHT22 
#define DS3231_i2c_AD 0x68

//The Nokia 5110 LCD
 LCD5110 myGLCD(8,9,10,11,12); 
    extern uint8_t SmallFont[]; 
    extern uint8_t MediumNumbers[]; 
    extern uint8_t BigNumbers[];
DHT dht(DHTPIN, DHTTYPE);
int photocellPin = 0;
int photocellRead;
const int bckLghtPin =  7;
int bckLghtState = LOW:          
void setup() {
  
   rtc.adjust(DateTime(2019, 7, 18, 11, 39, 0));
   pinMode(bckLghtState, OUTPUT);
   pinMode(bckLghtPin, OUTPUT);
   myGLCD.InitLCD(); 
   myGLCD.setFont(SmallFont);
   myGLCD.setContrast(60);
   Serial.begin(9600);
   dht.begin();
}

void loop() {  
   DateTime now = rtc.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
  delay(500);
   photocellRead = analogRead(photocellPin);
   Serial.print("Analog reading = ");
   Serial.print(photocellRead); 
   if (photocellRead < 70) {
     analogWrite(bckLghtPin, 20);
     myGLCD.enableSleep();
     Serial.println(" - Dark");
   } else (photocellRead > 200); 
   { myGLCD.disableSleep();
   analogWrite(bckLghtPin, 255);
     Serial.println(" - Light");
   } 
   float hum = dht.readHumidity();
   float temp = dht.readTemperature();
   if (isnan(hum) || isnan(temp)) {
      myGLCD.clrScr();
      myGLCD.print("Device Not Found",15,1);
      //Serial.print(temp);
      delay(2000);
    
   }
  else {
     
      myGLCD.clrScr();
      myGLCD.print("TFM Weather",0,10);
      myGLCD.print("Temp=",0,25);
      myGLCD.printNumI(temp,35,25);
      myGLCD.print("~C",61,25);
      myGLCD.print("Hum.=",0,35);
      myGLCD.printNumI(hum,35,35);
      myGLCD.print("%",61,35);
} 
}


