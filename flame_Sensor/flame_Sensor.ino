 /*
  * Flame
  * 火焰传感器检测到火焰后，控制蜂鸣器报警
  */
 
 int beep = 8;//定义蜂鸣器接口为数字8 接口
 int flameVal = A0; //存储火焰传感器数据
 
 void setup() {
   pinMode(beep, OUTPUT); //定义beep 为输出接口
   Serial.begin(9600);
 }
 
 void loop() {
   flameVal = analogRead(A0); //读取火焰传感器的模拟值
   if (flameVal >= 10) //当模拟值大于200时蜂鸣器鸣响，阈值根据实际测试进行修改
   { 
     digitalWrite(beep, HIGH);//
   }
   else
   { 
     digitalWrite(beep, LOW);
   }
   Serial.println(flameVal);
 }
