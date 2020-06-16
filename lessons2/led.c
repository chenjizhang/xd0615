void setup()
{
  int i = 0;
  while(i < 8)
  {
	pinMode(i, OUTPUT);
    i++;
  }
}
void loop()
{
  int i = 0;
  while(i < 8)
  {
  	digitalWrite(i, HIGH);
  	delay(1000);
  	digitalWrite(i, LOW);
  	delay(500);
    i++;
  }
}