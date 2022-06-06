/*
 http://shop34791330.taobao.com/ //德飞莱旗舰店
 http://qixingchong.tmall.com/   //七星虫旗舰店
 http://www.doflye.net //德飞莱技术论坛
 http://www.doflye.net/forum-98-1.html //德飞莱论坛arduino版块
 
 通过串口软件写入对应的数据，格式如下：r,g,b,然后加入回车键
 r代表红色，范围是0-255，g代表绿色，范围是0-255，b代表蓝色，范围是0-255
 系统会处理相应的数据并返回相应的值到串口，通过写入不同的数据可以实现
 三色led灯的调光变色功能。
 
 The circuit:
 * led的3个脚连接到9,10,11脚
 * 阳极连接到VCC
 
 通过PWM功能进行调光，实现3种颜色混合显示
 
 德飞莱配套的连接电路和实物图，参考以下链接：
 http://www.doflye.net/viewthread.php?tid=5310&extra=
 */
#define redPin 11
#define greenPin 10
#define bluePin 9
int red, green, blue = 0;
int fadeAmount=5;
int brightness=0;
//初始化
void setup() {
  // 打开串口通讯功能等待串口打开
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  // 设置led端口方向:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  // 打开13脚led作为电源指示:
  pinMode(13, OUTPUT);
  //digitalWrite(13, HIGH);
  //digitalWrite(redPin, HIGH);
  //digitalWrite(greenPin, HIGH);
  //digitalWrite(bluePin, HIGH);
}
//主循环
void loop() {
  /*for(red=0; red<255; red+=fadeAmount)
    analogWrite(redPin,      red);
    {for(green=0; green<255; green+=fadeAmount)
      analogWrite(greenPin,    green);
      {for(blue=0; blue<255; blue+=fadeAmount) 
        {
         
         
         analogWrite(bluePin,     blue);

        }
      }
    }
   if((red==0||255)||(green==0||255)||(blue==0||255))
      fadeAmount=-fadeAmount;*/
  analogWrite(redPin, brightness);
  //delay(30);
  analogWrite(greenPin, brightness);
  //delay(30);
  analogWrite(bluePin, brightness);
  //delay(30);
  brightness+=fadeAmount;
     if(brightness==0||255)//||(green==0||255)||(blue==0||255))
      fadeAmount=-fadeAmount;
  /*  Serial.print("RED:");
  Serial.println(red);
    Serial.print("GREEN:");
  Serial.println(green);
    Serial.print("BLUE");
  Serial.println(blue);*/
  }
