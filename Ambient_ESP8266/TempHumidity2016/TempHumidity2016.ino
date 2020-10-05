

#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 6        
#define DHTTYPE DHT11   


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);


int stepDelay       = 100;
int shortDelay      = 200;
int mediumDelay     = 500;
int oneSecDelay     = 1000;
int longDelay       = 3000;
int nCounter        = 3
float humidity      = 0;
float tempFahr      = 0;
float tempCels      = 0;  
float tempHeatC     = 0;
float tempHeatF     = 0;
float tempMIN       = 0;
float tempMAX       = 0;
bool  isFirstExec   = true;

void debugDataCelsius(float h, float t, float hit) {
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");

  Serial.print("Heat Temp.: ");
  Serial.print(hit, 1);
  Serial.print(" *C ");

  Serial.println("\t");
}

String getTextTemparature() {
  String txt = "TEMP: ";
  txt.concat(String(tempCels, 0));
  txt.concat((char)223);          /
  txt.concat("C");
  return txt;
}

String getTextHumidity() {
  return "UMIDITA': " + String(humidity, 0) + "%";
}

String getTextHeatTemp() {
  String txt  = "H.TEMP: ";
  txt.concat(String(tempHeatC, 1));
  txt.concat((char)223);          
  txt.concat("C");
  return txt;
}

String getTextMinMaxTemp() {
  String txt = "MAX:";
  txt.concat(String(tempMAX, 0));
  txt.concat((char)223);          
  txt.concat(" ");
  txt.concat("MIN:");
  txt.concat(String(tempMIN, 0));
  txt.concat((char)223);
  return txt;
}

void readSensorData() {
  

  humidity = dht.readHumidity();            

  tempCels = dht.readTemperature();         

  

  
  if (isnan(humidity) || isnan(tempCels) || isnan(tempFahr)) {
    
    return;
  }

  
  tempHeatC = dht.computeHeatIndex(tempCels, humidity, false);

  if(isFirstExec){
    tempMAX = tempMIN = tempCels;
    isFirstExec = false;
  }

 
  if (tempCels != tempMAX && tempCels > tempMAX) {
      tempMAX = tempCels;
  }
  
  if (tempCels != tempMIN && tempCels < tempMIN) {
      tempMIN = tempCels;
  }
}

void printLcdTemperatureRow() {
  
  lcd.setCursor(0, 0);                
  
  lcd.print(getTextTemparature());    
}

void printLcdDataRow() {
  
  lcd.setCursor(0, 1);                
  
  
  if (nCounter == 0) {
    lcd.print(getTextHumidity());     
  } else if (nCounter == 1) {
    lcd.print(getTextHeatTemp());     
  } else if (nCounter == 2) {
    lcd.print(getTextMinMaxTemp());   
  }
}

void scrollText(){
 
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(stepDelay);
  }
}




void setup() {
  
                
  
  lcd.begin(16, 2);                  

  dht.begin();

  
}





void loop() {

  lcd.clear();

  if (nCounter > 2) {
    nCounter = 0;       
    readSensorData();   
  }



  printLcdTemperatureRow();
  printLcdDataRow();
  delay(longDelay);

  lcd.clear();

  delay(mediumDelay);

  printLcdTemperatureRow();
  printLcdDataRow();
  delay(longDelay);

  scrollText();

  nCounter++;

  delay(mediumDelay);
}
