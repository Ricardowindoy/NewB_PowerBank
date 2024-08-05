#include "Logger.h"

void Logger::info(std::string msg) {
    Serial.println(msg.c_str());
}

