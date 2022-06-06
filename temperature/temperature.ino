#include <dht.h>        
dht DHT;       
#define DHT11_PIN A0    
int ledCount=8;
int segCount=4;

long previousMillis = 0; 

const unsigned char dofly_DuanMa[12]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x63,0x58};
//位码
//unsigned char const dofly_WeiMa[]={0,1,2,3};
int ledPins[] = { 
  12,8,5, 3, 2, 11, 6, 4, };   // 11,7,4,2,1,10,5,3 注释是数码管实际引脚数，和芯片一样，逆时针数
int segPins[] = {
  13,10,9,7   //12,9,8,6 注释是数码管实际引脚数，和芯片一样，逆时针数 德飞莱论坛会有详细帖子说明
};
unsigned char displayTemp[4];//显示缓冲区
void setup() {
// 循环设置，把对应的端口都设置成输出
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT); }
  for (int thisSeg = 0; thisSeg < segCount; thisSeg++) {
    pinMode(segPins[thisSeg], OUTPUT); 
  }
  DHT.read11(DHT11_PIN);

}
// 数据处理，把需要处理的byte数据写到对应的引脚端口。
void deal(unsigned char value){
 for(int i=0;i<8;i++)
   digitalWrite(ledPins[i],bitRead(value,i));//使用了bitWrite函数，非常简单
   // !bitRead(value,i)，这里前面加！(非运算符号)，取决于使用的是共阴还是共阳数码管。
}
// 主循环
void loop() {
  

  int temp=DHT.temperature;
  displayTemp[0]=dofly_DuanMa[temp/10]; //静态显示
  displayTemp[1]=dofly_DuanMa[temp%10];
  displayTemp[2]=dofly_DuanMa[10];
  displayTemp[3]=dofly_DuanMa[11];
  

  static int i;
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > 0) {
    previousMillis = currentMillis;   

     deal(0);// 清除“鬼影”
     for(int a=0;a<4;a++) //循环写位码，任何时刻只有1位数码管选通，之前全部关闭，然后再选通需要的那位数码管
       digitalWrite(segPins[a],1);//
     digitalWrite(segPins[i],0);//
     deal(displayTemp[i]);//读取对应的段码值
    i++;
    if(i==4) //4位结束后重新循环
      i=0;
  }
  

  }

//如何加·？
//如何初始化作为时钟？
