#include "src\HardWareDrive\IP5356\IP5356.h"
// tft屏幕懒得抽象了 暂时用不上 todo：将屏幕单独抽象成一个类
#include "TFT_eSPI.h"

#define SDA_PIN 4
#define SLK_PIN 5

TFT_eSPI tft = TFT_eSPI();
IP5356 drp;
void setup()
{
  Serial.begin(115200);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("I2C Scanner");

  drp.begin(4,5);
  
  tft.begin();
  tft.setRotation(0);
}
 
 
void loop()
{
IP5356 drp;
  drp.begin(4,5);
    tft.fillScreen(TFT_GREEN);
    delay(200);
    tft.fillScreen(TFT_RED);
    delay(200);
    tft.fillScreen(TFT_BLUE);
    
    double fTypecV = (*drp.GetTypecV()) * 1.611328;
    double fTypecI = (*drp.GetTypecI()) * 1.611328;
    Serial.print("loop print power: ");
    Serial.println(fTypecV * fTypecI / 1000000);
    
    delay(700);
} 
