#include <TFT_eSPI.h>

#include "src\HardWareDrive\IP5356\IP5356.h"
#include "src\HardWareDrive\IP2369\IP2369.h"
#include "src\Util\Queue\Queue.h"
#include "src\DIN.h"
#include "src\Util\Logger\Logger.h"

// todo：将屏幕抽象成绘图工具

#define DRP_SDA_PIN 4
#define DRP_SLK_PIN 5

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite tfts = TFT_eSprite(&tft);   //创建TFT_eSprite对象


IP2369 drp;
Queue BatQue;
Queue SysQue;
double fSumPBat = 0;
double fSumPSys = 0;
long i64Time = 0;
void setup()
{
  tft.init();
  tfts.loadFont(DIN);  
  tft.setRotation(3);
  tfts.setRotation(3);
  tfts.createSprite(180, 80);     //创建160*80的精灵
  tfts.fillSprite(0x0000);        //填充窗口为黑色
  tft.invertDisplay(true);
  
  drp.begin(DRP_SDA_PIN,DRP_SLK_PIN);

  BatQue.SetCap(256);
  SysQue.SetCap(256);
}
 
 
void loop()
{
    float fBatV = float(*drp.GetBatV()) / 1000;
    float fBatI = float(*drp.GetBatI()) / 1000;
    float fBAtPower = fBatV * fBatI;
    float fSysV = float(*drp.GetSysV()) / 1000;
    float fSysI = float(*drp.GetSysI()) / 1000;
    float fSysPower = float(*drp.GetSysP()) / 100;
    
    float t = millis();
    int iMin = i64Time / 60000;
    int iS = (i64Time / 1000) - iMin * 60;
    fSumPBat += fBatV / 3.7 * fBatI * (t - i64Time) /3600;
    fSumPSys += fSysPower / 3.7 * (t - i64Time) /3600;
    i64Time = t;
    
  tfts.fillSprite(0x0000);    //填充窗口为黑色        
  tfts.setTextColor(0x867D);    
  tfts.setTextSize(3); 
    
  tfts.drawFloat(fBatV, 2 , 0,  0);  tfts.drawString("伏", 56,  2); tfts.drawFloat(fBatI, 2 , 85, 0);  tfts.drawString("安", 136, 0); 
  tfts.drawFloat(SysQue.AddItem(fBAtPower) , 2 , 0, 22);  tfts.drawString("瓦", 56, 22); tfts.drawFloat(SysQue.AddItem(fSysPower) , 2 , 85, 22);  tfts.drawString("瓦", 136, 22); 
  tfts.drawFloat(fSumPBat, 1 , 0, 42);  tfts.drawString("mah", 56, 42);  tfts.drawFloat(fSumPSys, 1, 97, 42);
  tfts.drawFloat(fSysV, 2 , 0,  62);  tfts.drawString("伏", 56,  62); tfts.drawFloat(fSysI, 2 , 85, 62);  tfts.drawString("安", 136, 62); 

  tfts.pushSprite(1, 2);            //将精灵刷新到屏幕上
} 
