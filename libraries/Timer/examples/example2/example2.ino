
#include <softShield.h>
#include <Event.h>
#include <Timer.h>

Timer t;
int pin = 13;
 
 
void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  t.oscillate(pin, 100, LOW);
  t.every(1000, takeReading);
}
 
 
void loop()
{
  softModule::update();
}
 
 
void takeReading()
{
  Serial.println(analogRead(0));
}

