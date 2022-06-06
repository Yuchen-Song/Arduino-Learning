
// CONNECTIONS:
// DS1302 CLK/SCLK --> 7
// DS1302 DAT/IO --> 6
// DS1302 RST/CE --> 8
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND

// 包含头文件
#include <LiquidCrystal.h>

// 初始化引脚
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <ThreeWire.h>  
#include <RtcDS1302.h>

ThreeWire myWire(6,7,8); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup () 
{
    // 设置行列值
    lcd.begin(16, 2);

    Serial.begin(57600);

    Serial.print("compiled: ");
    Serial.print(__DATE__" ");
    Serial.println(__TIME__);

    Rtc.Begin();

    RtcDateTime compiled = Rtc.GetDateTime();
    Serial.print("getDateTime:");
    //printDateTime(compiled);
    Serial.println();

    if (!Rtc.IsDateTimeValid()) 
    {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing

        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled) 
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }
    else if (now > compiled) 
    {
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    else if (now == compiled) 
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }
}

void loop () 
{
    RtcDateTime now = Rtc.GetDateTime();

    //printDateTime(now);
    Serial.println();

    if (!now.IsValid())
    {
        // Common Causes:
        //    1) the battery on the device is low or even missing and the power line was disconnected
        Serial.println("RTC lost confidence in the DateTime!");
    }
    /*lcd.print(__DATE__" ");
    lcd.setCursor(0,1);
    lcd.print(__TIME__" ");
    lcd.setCursor(0,0);*/
    lcd.setCursor(0,0);
    lcd.print(printDate(now));
    lcd.setCursor(0,1);
    lcd.print(printTime(now));
    delay(1000);// ten seconds
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

String printDate(const RtcDateTime& dt)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u"),
            dt.Month(),
            dt.Day(),
            dt.Year());

    return datestring;
    Serial.print(datestring);
}
String printTime(const RtcDateTime& dt)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u:%02u:%02u"),

            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    return datestring;
    //Serial.print(datestring);
}
/*memset(day, 0, sizeof(day));
    switch (t.day)
    {
    case 0: strcpy(day, "Sun"); break;
    case 1: strcpy(day, "Mon"); break;
    case 2: strcpy(day, "Tues"); break;
    case 3: strcpy(day, "Wed"); break;
    case 4: strcpy(day, "Thur"); break;
    case 5: strcpy(day, "Fri"); break;
    case 6: strcpy(day, "Sat"); break;
    }
*/
