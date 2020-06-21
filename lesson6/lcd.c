
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 9, 8, 7, 6, 5, 4, 3, 2);
 
void setup()
{
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  delay(1000);
  lcd.setCursor(0, 0); 
  lcd.print("I'm ready!     ");
  Serial.begin(9600);
  
}
String Str;
void loop()
{
  if(Serial.available()>0)
  {
    lcd.setCursor(0, 0); 
    lcd.print("Working!         ");
    Str = Serial.readString();
    lcd.setCursor(0,1);
    lcd.print(Str);
  }
}
 