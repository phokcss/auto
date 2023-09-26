#include "mas001.h"
#include "dmd150.h"
MAS001 myShield;
DMD150 myMotor;
int touchSensor = 8;  
int ledPin = 9;       
 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  
  pinMode(touchSensor, INPUT);
  
}
 
void loop() {
  uint8_t upspd;
  int spd;
  int touchValue = digitalRead(touchSensor);
  if(myShield.button1Clicked()){
    myMotor.floating();
  }else
  {
    if (touchValue == HIGH)
    {      
      digitalWrite(ledPin, HIGH);
      Serial.println("TOUCHED");
        spd ++;
    } 
    else 
    {                      
      digitalWrite(ledPin,LOW);
      Serial.println("NOT TOUCHED");
      spd --;
    }
    myMotor.rotation(spd);  
    delay(1000);
    }
  }
