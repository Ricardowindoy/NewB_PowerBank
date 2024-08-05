#include <TFT_eSPI.h>

#include "src\HardWareDrive\IP5356\IP5356.h"
#include "src\HardWareDrive\IP2369\IP2369.h"
#include "src\Util\Queue\Queue.h"
#include "src\Util\Logger\Logger.h"

// tft屏幕懒得抽象了 暂时用不上 todo：将屏幕单独抽象成一个类
#include "TFT_eSPI.h"

#define DRP_SDA_PIN 4
#define DRP_SLK_PIN 5

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite tfts = TFT_eSprite(&tft);   //创建TFT_eSprite对象


IP2369 drp;
Queue pQue;
void setup()
{
  tft.init();
  tft.setRotation(3);
  tfts.setRotation(3);
  tfts.createSprite(160, 80);     //创建160*80的精灵
  tfts.fillSprite(0x0000);        //填充窗口为黑色
  tft.invertDisplay(true);
  
  drp.begin(DRP_SDA_PIN,DRP_SLK_PIN);

  pQue.SetCap(128);
}
 
 
void loop()
{
    float fTypecV = float(*drp.GetTypecV()) / 1000;
    float fTypecI = float(*drp.GetTypecI()) / 1000;
    float fPower = fTypecV * fTypecI;
    float t = float(millis())/1000;
    
  tfts.fillSprite(0x0000);    //填充窗口为黑色        
  tfts.setTextColor(0x867D);    
  tfts.setTextSize(2);             
  tfts.drawFloat(fTypecV, 4 , 0,  0);  tfts.drawString("V", 148,  2); 
  tfts.drawFloat(fTypecI, 4 , 1, 22);  tfts.drawString("A", 148, 22); 
  tfts.drawFloat(pQue.AddItem(fPower) , 4 , 1, 42);  tfts.drawString("W", 148, 42); 
  tfts.drawFloat(t, 1 , 1, 62);  tfts.drawString("mills", 100, 62); 

  tfts.pushSprite(2, 2);            //将精灵刷新到屏幕上 
} 
