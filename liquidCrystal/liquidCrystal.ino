/*
 http://shop34791330.taobao.com/ //德飞莱旗舰店
 http://qixingchong.tmall.com/   //七星虫旗舰店
 http://www.doflye.net //德飞莱技术论坛
 http://www.doflye.net/forum-98-1.html //德飞莱论坛arduino版块
 LiquidCrystal库 - 自定义字符
 
 演示了如何使用16X2液晶显示屏。该LiquidCrystal
 库适用于所有的兼容HD44780的LCD液晶。常用的是16引脚。

 
 引脚定义，这里使用4位数据模式，只写数据，不读数据:
 * LCD RS pin to digital pin 12      //数据/指令控制引脚
 * LCD Enable pin to digital pin 11  //使能引脚
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground 接GND       //读/写控制引脚，高电平是读数据，低电平是写数据
 * 10K resistor://使用LY-51S开发板已经连接好这些硬件，值需要连接对应的端口，非常方便。
 * ends to +5V and ground VO引脚接电位器抽头，用于调节对比度，LY-51S开发板只需要调节W1电位器。
 * wiper to LCD VO pin (pin 3)
 * A0接10K电位器
 面包板连接电路图和详细说明英文版：
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 使用独立模块开发板LY-51S连接详情：
 http://www.doflye.net/viewthread.php?tid=5293&extra=
 
 
 */

// 包含头文件
#include <LiquidCrystal.h>

// 初始化引脚
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// 自定义字符
byte you[8] = {
  0b11111,
  0b01000,
  0b11111,
  0b01001,
  0b01111,
  0b01001,
  0b01111,
  0b01001
};

byte nei[8] = {
  0b00100,
  0b00100,
  0b11111,
  0b10101,
  0b11011,
  0b10001,
  0b10101,
  0b10010
};

byte gui[8] = {
  0b11111,
  0b10101,
  0b11111,
  0b10101,
  0b11111,
  0b00100,
  0b01101,
  0b10111
};

byte zhong[8] = {
  0b01010,
  0b10111,
  0b11101,
  0b01101,
  0b10010,
  0b11101,
  0b00010,
  0b11001
};

byte zhi[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00111,
  0b10100,
  0b10100,
  0b10100,
  0b11111
};

byte jiao[8] = {
  0b00100,
  0b11111,
  0b01010,
  0b10001,
  0b01010,
  0b00100,
  0b01010,
  0b10001
};

byte yi[8] = {
  0b01110,
  0b01110,
  0b01110,
  0b01000,
  0b01111,
  0b10111,
  0b01101,
  0b00010
};

byte jvhao[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11100,
  0b10100,
  0b11100,
  0b00000,
};
byte mail[8] = {
  0b00000,
  0b11111,
  0b11011,
  0b10101,
  0b10001,
  0b11111,
  0b00000,
  0b00000,
};
void setup() {
  // 创建一个新的字符
  lcd.createChar(0, you);
  // 创建一个新的字符
  lcd.createChar(1, nei);
  // 创建一个新的字符
  lcd.createChar(2, gui);
  // 创建一个新的字符
  lcd.createChar(3, zhong);  
  // 创建一个新的字符
  lcd.createChar(4, zhi);  
  lcd.createChar(5, jiao);
  lcd.createChar(6, yi);
  lcd.createChar(7, jvhao); //用ASCII码怎么打？
  //lcd.createChar(8, mail);
  // 设置液晶行列数值 
  lcd.begin(16, 2);
  //lcd.write(8);
  //lcd.print("1");

  lcd.write(0.0);
  delay(1000);
  lcd.write(1);
  delay(1000);
  lcd.write(2);
  delay(1000);
  lcd.print(",");
  delay(1000);
  lcd.write(3);
  delay(1000);
  lcd.write(4);
  delay(1000);
  lcd.write(5);
  delay(1000);
  lcd.write(6.0);
  delay(1000);
  lcd.write(7);
  //lcd.setCursor(0, 1);
  //lcd.write(8);
}

void loop() {
  lcd.cursor();
  delay(500);
  lcd.noCursor();
  delay(500);  
}

//想要加✉，但是不行
//想要加“操作”“退出”也不行
