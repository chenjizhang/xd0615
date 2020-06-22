#include <MsTimer2.h>  
int pinInterrupt = 2;
byte count = 0;  
void timetozero()
{
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  count = 0;
}
void time()
{
  digitalWrite(3, count&0x1);
  digitalWrite(4,(count>>1)&0x1);
  digitalWrite(5,(count>>2)&0x1);
  digitalWrite(6,(count>>3)&0x1);	
  count++;
  count %= 10;
}  
 
void setup()
{ 
  Serial.begin(9600); 
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), timetozero, CHANGE);
  MsTimer2::set(1000, time); 
  MsTimer2::start(); 
}
 
void loop(){}