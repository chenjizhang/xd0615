/*
用于对传感器输入信号值区间校准的装置；
前五秒检测外界温度变化，设置接收信号值区间的新的最大值和最小值；
之后传感器信号大小在区间位置可由led亮度显示；
*/



const int sensorPin = A0;    //A0 设为传感器信号接收引脚
const int ledPin = 9;        //9  设为led亮度控制引脚

// variables:
int sensorValue = 0;         // 声明传感器信号值
int sensorMin = 1023;        // 传感器信号最大值
int sensorMax = 0;           // 传感器信号最小值


void setup() {
    // 用主板上的led作为校准时的信号:
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);

    // 前五秒用于对接受光照范围的校准
    while (millis() < 5000) {
        sensorValue = analogRead(sensorPin);

        //存储新的最大信号值
        if (sensorValue > sensorMax) {
            sensorMax = sensorValue;
        }

        // 存储新的最小信号值
        if (sensorValue < sensorMin) {
            sensorMin = sensorValue;
        }
    }

    // 结束校准
    digitalWrite(13, LOW);
}

void loop() {
    // 读取传感器信号值：
    sensorValue = analogRead(sensorPin);

    // 将传感器信号值在校准后的信号区间位置转换为对应0-255的信号值的区间位置（用于输出led信号）
    sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

    //将超出约束范围的数值设为边缘值（不然该值不适用led）
    sensorValue = constrain(sensorValue, 0, 255);

    //将转化后的信号值传给led:
    analogWrite(ledPin, sensorValue);
}