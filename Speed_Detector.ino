//SPEED DETECTOR


#include <TimeLib.h>
#include <LiquidCrystal.h>

const int IR_Sensor1 = 35;
const int IR_Sensor2 = 34;
LiquidCrystal lcd(53, 52, 50, 48,46,44);

void setup() {
pinMode(IR_Sensor1, INPUT);
pinMode(IR_Sensor2, INPUT);
Serial.begin(9600);
lcd.begin(16, 2);
lcd.print("hello, world!");
}

float next = 0, count = 0;

void loop()
{
  float h, h1, t, s;
  delay(5);
  if (digitalRead(IR_Sensor1) == 0)
  {
    count = 0;
    next = 0;
    while (!next)
    {
      delayMicroseconds(1);
      count++;
      if (digitalRead(IR_Sensor2) == 0)
      {
        lcd.clear();
        next = 1;
        Serial.print("The time taken to reach from point A to point B is  ");
        Serial.print(count/60000.00);
        Serial.print("  seconds ");
        Serial.println();
        float s=(60000.0*0.3/count);
        Serial.print("The speed is");
        Serial.print(s,2);
        Serial.print("m/s");
        Serial.println();
        h=3.6*s;
        Serial.print("The speed in km/hr is : ");
        Serial.print(h,2);
        Serial.println();
        lcd.setCursor(0,0);
        delay(500);
        lcd.print("THE SPEED IS ");
        delay(500);
        lcd.setCursor(0,1);
        delay(500);
        lcd.print(h,2);
        delay(500);
        lcd.print(" km/hr");
        delay(500);
        
        digitalWrite(IR_Sensor1, HIGH);
        digitalWrite(IR_Sensor2, HIGH);
        if(h>=1)
        { 
            Serial.println("Overspeed Detected ");
            delay(500);
            lcd.clear(); 
            lcd.print("OVERSPEED DETECTED");
            delay(500);
        }
        }
      }
    }
next = 0;


if (digitalRead(IR_Sensor2) == 0)
  {
    count = 0;
    next = 0;
    while (!next)
    {
      delayMicroseconds(1);
      count++;
      if (digitalRead(IR_Sensor1) == 0)
      {
        lcd.clear();
        next = 1;
        Serial.print("The time taken to reach from point B to point A is  ");
        Serial.print(count/60000.00);
        Serial.print("  seconds ");
        Serial.println();
        float s=(60000.0*0.3/count);
        Serial.print("The speed is");
        Serial.print(s,2);
        Serial.print("m/s");
        lcd.setCursor(0,0);
        lcd.print("THE SPEED IS ");
        delay(1000);
        lcd.setCursor(0,1);
       
        lcd.print(h,2);
        delay(1000);
        lcd.print("km/hr");
        delay(1000);
       
        //delay(1000);
        Serial.println();
        h=3.6*s;
        Serial.print("The speed in km/hr is : ");
        Serial.print(h,2);
        Serial.println();
        digitalWrite(IR_Sensor1  , HIGH);
        digitalWrite(IR_Sensor2, HIGH);
        if(h>=1)
        {
            Serial.println("Overspeed Detected ");
            lcd.clear();
            delay(500);
            lcd.print("OVERSPEED DETECTED");
            delay(500);
        }
        }
      }
    }
next = 0;

       

  }
