char ins = ' ';
//对小车的指令
void setup()
{
  Serial.begin(9600);
  //左轮8&9；右轮2&3；
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0)
  {
  	ins = Serial.read();
    /*
    w/W -> 前进
    a/A -> 左转
    s/S -> 后退
    d/D -> 右转
    r/R -> 停止
    其他按键无效
    */
    switch(ins)
    {
      case 'w':
      case 'W':
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      break;
      case 'a':
      case 'A':
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      break;
      case 's':
      case 'S':
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(2,LOW);
      break;
      case 'd':
      case 'D':
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(2,LOW);
      break;
      case 'r':
      case 'R':
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(3,LOW);
      digitalWrite(2,LOW);
      break;
      default:
      break;
    }
  }
}