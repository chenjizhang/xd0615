#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7
  
#define MAX 255
void setup()
{ 
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);

  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  
}

void loop()
{ 
 
  if(Serial.available() > 0)
  { 
    byte b[MAX] = {0};
    int n = Serial.readBytes(b, MAX);
 	if(n > 0)
    {
      	digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        int N = MAX - n + S1;
      if(n <= 4)
      {
    	for(int i = 0; i < n; i++)
    	{
     
    	b[i] = b[i]-'0';
    	digitalWrite(i+N, LOW);
    	digitalWrite(IN1,b[i]&0x1);
   	 	digitalWrite(IN2,(b[i]>>1)&0x1);
   	 	digitalWrite(IN3,(b[i]>>2)&0x1);
   		digitalWrite(IN4,(b[i]>>3)&0x1);
   		digitalWrite(i+N, HIGH);
    	}
      }
      else
      {
        int count = 0;
        for(int count = 0; count + 4 <= n; count++)
        {
        	for(int i = 0; i < 4; i++)
    		{
    			b[i+count] = b[i+count]-'0';
    			digitalWrite(i+S1, LOW);
    			digitalWrite(IN1,b[i+count]&0x1);
   	 			digitalWrite(IN2,(b[i+count]>>1)&0x1);
   	 			digitalWrite(IN3,(b[i+count]>>2)&0x1);
   				digitalWrite(IN4,(b[i+count]>>3)&0x1);
   				digitalWrite(i+S1, HIGH);
    		}
          delay(1000);
        }
      }
   }
  }
}
