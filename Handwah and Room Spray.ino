#include<EEPROM.h>
int trig=12, echo=11, ir=10, relay=9;
float temp=0, hum=0, dist=0;
long dur=0;
int tm=0;
int sw1=3, sw2=4, t1=1, t2=1;
int eepaddr=0, eepdata, looplim=60;

#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); //class declare
#include <Servo.h>

#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE); //class declare

Servo servo1; //class declare
Servo servo2; //class declare 



void setup() {
  Serial.begin(9600);
  EEPROM.get(0, looplim);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(ir, INPUT);

  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  
  digitalWrite(trig, LOW);
  digitalWrite(relay, LOW);

  servo1.attach(5);
  servo2.attach(6);
  
  lcd.init(); 
  lcd.clear();
  lcd.backlight();
  
  dht.begin();

  lcd.setCursor(1,0); //set position for write, col/row
  lcd.print("Put Hand Under Pot");

  lcd.setCursor(0,3);
  lcd.print("Spray Duration: ");
  lcd.setCursor(16,3);
  lcd.print("    ");
  lcd.setCursor(16,3);
  lcd.print(looplim);
  lcd.print("s");

}

void loop() {

  temp = dht.readTemperature();
  hum = dht.readHumidity();

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur=pulseIn(echo, HIGH);
  dist = dur * 0.178;
  dist = 100-dist;
  if(dist<3) dist =0;
  else if(dist>99) dist = 99;



if(digitalRead(ir)==0)
{
  digitalWrite(relay, HIGH);
  lcd.setCursor(1,0);
  lcd.print("  Soap Dispansed   ");
  servo1.write(45);
  
}
else 
{
  digitalWrite(relay, LOW);
  servo1.write(90);
  lcd.setCursor(1,0);
  lcd.print("Put Hand Under Pot");
}

  
  lcd.setCursor(0,1);
  lcd.print("Temp=");
  lcd.print(temp,1);
  lcd.print("C");
  lcd.setCursor(11,1);
  lcd.print("Hum=");
  lcd.print(hum,1);
  lcd.print("%");
  lcd.setCursor(1,2);
  lcd.print("Soap Remaining: ");
  lcd.print(dist,0);
  lcd.print("%");


  tm++;
  if(tm>=looplim)
  {
    tm=0;
    servo2.write(65);
    delay(500);
    servo2.write(90);
  }

  Serial.print(digitalRead(sw1));
  Serial.print(" ");
  Serial.println(digitalRead(sw2));

  Serial.println(looplim);


  

  for(int i=0; i<90; i++)
  {

    if((digitalRead(sw1)==0) && (t1==1))
  {
    t1=0;
    looplim+=5;
    if(looplim>995) looplim=995;
    EEPROM.write(0, looplim);
    lcd.setCursor(16,3);
    lcd.print("    ");
    lcd.setCursor(16,3);
    lcd.print(looplim);
    lcd.print("s");
  }
  if(digitalRead(sw1)==1)
  {
   t1=1;
  }

  if((digitalRead(sw2)==0) && (t2==1))
  {
    t2=0;
    looplim-=5;
    if(looplim<10) looplim=10;
    EEPROM.write(0, looplim);
    lcd.setCursor(16,3);
    lcd.print("    ");
    lcd.setCursor(16,3);
    lcd.print(looplim);
    lcd.print("s");
  }
  if(digitalRead(sw2)==1)
  {
   t2=1;
  }


    delay(10);
  }
 

}
