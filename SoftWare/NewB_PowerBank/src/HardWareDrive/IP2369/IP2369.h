#include "IP2369Reg.h"
#include <Arduino.h>
#include "Wire.h"

#ifndef IP2369_H
#define IP2369_H

class IP2369 {
    public:
        void begin(uint8_t sdaPin, uint8_t sclPin);

    public:
        short* GetTypecV();
        short* GetTypecI();
        uint8_t* GetSoc();

    private:
        uint8_t writeBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity);
        uint8_t readBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity);

    private:
        short* m_pTypecV;
        short* m_pTypecI;
        uint8_t* m_pSoc;
};

#endif
