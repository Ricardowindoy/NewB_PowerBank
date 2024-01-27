#include "IP5356Reg.h"
#include <Arduino.h>
#include "Wire.h"

#ifndef IP5356_H
#define IP5356_H

class IP5356 {
    public:
        void begin(uint8_t sdaPin, uint8_t sclPin);

    public:
        short* GetTypecV();
        short* GetTypecI();

    private:
        uint8_t writeBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity);
        uint8_t readBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity);

    private:
        short* m_pTypecV;
        short* m_pTypecI;
};

#endif
