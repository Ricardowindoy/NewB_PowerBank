// 串口输出函数会导致mcu在未连接串口时发生不可预测卡顿 故仅在develop模式下开启串口输出
// todo：：该日志工具依赖arduino 的Serial类 需要将其抽象
#include <Arduino.h>

#ifndef Logger_H
#define Logger_H

class Logger {
    public:
        static void info(std::string msg);

};
#endif
