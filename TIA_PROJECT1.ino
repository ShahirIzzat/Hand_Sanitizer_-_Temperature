#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT11


const int EN1 = 4;
const int IN1 = 2;
const int IN2 = 3;

const int trigPin_1 = 9;
const int echoPin_1 = 10;
long duration_1, cm_1;

const int trigPin_2 = 11;
const int echoPin_2 = 12;
long duration_2, cm_2;
  
DHT dht(DHTPIN, DHTTYPE, 6);

void setup() 
{ 
Serial.begin(9600);
dht.begin();
Serial.println("STARTS TO READ DHTxx DATA"); 

pinMode(EN1,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
}

void loop() 
{
  
////////////////////////DHT11 IS WORK//////////////////////////
  
  Serial.println ("DHT11 Read Update:-------------------");
  Serial.println ("\n");
  delay (100);

  float t = dht.readTemperature();
  
  if (isnan (t))
  
  {
    Serial.println ("Failed to read DHT Sensor!");
    return;
  }

  ////////////////////////HC-SR04_1 IS WORK///////////////////////

  pinMode(trigPin_1, OUTPUT);
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);

  pinMode(echoPin_1, INPUT);
  duration_1 = pulseIn(echoPin_1, HIGH);
  cm_1 = microsecondsToCentimeters(duration_1);

  delay(1000);
  
////////////////////////HC-SR04_1 IS WORK///////////////////////

  if (cm_1 <= 20)
  {
  Serial.print("Temperature:");
  Serial.print (t);
  Serial.println ("*C\t");
  Serial.println(" \n");
  }

  if (cm_1 > 20)
  {
  Serial.println("Move your HEAD at TEMPERATURE SENSOR!");
  Serial.println("\n");
  }
////////////////////////DHT11 IS WORK//////////////////////////




////////////////////////HC-SR04_2 IS WORK///////////////////////

  pinMode(trigPin_2, OUTPUT);
  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_2, LOW);

  pinMode(echoPin_2, INPUT);
  duration_2 = pulseIn(echoPin_2, HIGH);
  cm_2 = microsecondsToCentimeters(duration_2);

  delay(1000);
  
////////////////////////HC-SR04_2 IS WORK/////////////////////// 


///////////////////HAND SANITIZER IS WORK //////////////////// 
  
   if (cm_2 <= 20)
    
   { 
   analogWrite (EN1,255);
   digitalWrite (IN1,HIGH);
   digitalWrite (IN2,LOW);
   Serial.println("Sanitizer:-->  ON");
   Serial.println(" \n");
   delay(1000);

   analogWrite (EN1,0);
   digitalWrite (IN1,HIGH);
   digitalWrite (IN2,LOW);
   Serial.println("Sanitizer:-->  OFF");
   Serial.println(" \n");
   Serial.println(" \n");
   Serial.println(" \n");
   delay(1000);
   }

   else
   {
   Serial.println("Put your HAND near at SANITIZER!");
   Serial.println("\n");  
   }
   
///////////////////HAND SANITIZER IS WORK ////////////////////
    
}







/////////////////DEFINE MY FUNCTION OF MY PROJECT/////////////


///////////////////////////HC-SR04//////////////////////////

long microsecondsToInches(long microseconds)
  {
  return microseconds / 74 / 2;
  }

long microsecondsToCentimeters(long microseconds)
  {
  return microseconds / 29 / 2;
  }
  
///////////////////////////HC-SR04//////////////////////////
