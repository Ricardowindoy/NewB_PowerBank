#include "src\HardWareDrive\IP5356\IP5356.h"
#include "src\HardWareDrive\IP2369\IP2369.h"
// tft屏幕懒得抽象了 暂时用不上 todo：将屏幕单独抽象成一个类
#include "TFT_eSPI.h"

#define SDA_PIN 4
#define SLK_PIN 5

TFT_eSPI tft = TFT_eSPI();
IP2369 drp;
void setup()
{
  
    Serial.print("SET UP: ");
  Serial.begin(115200);
  while (!Serial);

  drp.begin(4,5);
  
  //tft.init();
  //tft.setRotation(0);
}
 
 
void loop()
{
   // tft.fillScreen(TFT_GREEN);
    delay(200);
   // tft.fillScreen(TFT_RED);
    delay(200);
   // tft.fillScreen(TFT_BLUE);
    
    double fTypecV = (*drp.GetTypecV()) * 1.611328;
    double fTypecI = (*drp.GetTypecI()) * 0.671387;
    Serial.print("loop print power: ");
    Serial.println(fTypecV * fTypecI / 1000000);
    
    delay(700);
} 
