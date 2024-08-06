// todo:: iic方法应该抽象掉
#include "IP2369Reg.h"
#include "Wire.h"

#ifndef IP2369_H
#define IP2369_H

class IP2369 {
    public:
        void begin(uint8_t sdaPin, uint8_t sclPin);

    public:
        short* GetBatV();
        short* GetBatI();
        short* GetSysV();
        short* GetSysI();
        short* GetSysP();
        uint8_t* GetSoc();

    private:
        uint8_t writeBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity);
        uint8_t readBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity);

    private:
        short* m_pBatV;
        short* m_pBatI;
        short* m_pSysV;
        short* m_pSysI;
        short* m_pSysP;
        uint8_t* m_pSoc;
};

#endif
