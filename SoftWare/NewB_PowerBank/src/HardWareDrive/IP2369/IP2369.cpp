#include <Wire.h>
#include "IP2369.h"
#include "..\..\Util\Logger\Logger.h"


void IP2369::begin(uint8_t sdaPin, uint8_t sclPin) {
    m_pBatV = new short();
    m_pBatI = new short();
    m_pSysV = new short();
    m_pSysI = new short();
    m_pSysP = new short();
    m_pSoc = new uint8_t();

    Wire.setPins(sdaPin, sclPin);
    Wire.begin();
}

uint8_t IP2369::writeBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity) {
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.write(data, quantity);
    uint8_t res = Wire.endTransmission();
    if (res != 0) {
        Logger::info("IP2369 i2c writte error: res=" + std::to_string(res));
        return 0; 
    }
    return res;

}
uint8_t IP2369::readBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity) {
    Wire.beginTransmission(addr);
    Wire.write(reg);
    uint8_t res = Wire.endTransmission(false);
    if (res != 0) {
        Logger::info("IP2369 i2c read error: res=" + std::to_string(res));
        return 0; 
    }
    // read quantity bytes from I2C
    Wire.requestFrom(addr, quantity);
    uint8_t i = 0;
    while (Wire.available() && i < quantity) {
        data[i] = Wire.read();
        i++;
    }
    // clear buffer
    while (Wire.available()) {
        Wire.read(); 
    }
    // check if read as much as needed
    if (i < quantity) {
        Serial.println("IP5306 i2c read error 0data");
    }
    return i;
}


short* IP2369::GetBatV() {
    uint8_t data;
    this->readBytes(IP2369_ADDR_0_1, R_VBAT_LOW, &data, 1);
    *m_pBatV = data;
    this->readBytes(IP2369_ADDR_0_1, R_VBAT_HEIGH, &data, 1);
    *m_pBatV += data << 8;

    return m_pBatV;
}

short* IP2369::GetBatI() {
    uint8_t data;
    this->readBytes(IP2369_ADDR_0_1, R_IBAT_LOW, &data, 1);
    *m_pBatI = data;
    this->readBytes(IP2369_ADDR_0_1, R_IBAT_HEIGH, &data, 1);
    *m_pBatI += data << 8;

    return m_pBatI;
}

uint8_t* IP2369::GetSoc() {

    return m_pSoc;
}
short* IP2369::GetSysV() {
    uint8_t data;
    this->readBytes(IP2369_ADDR_0_1, R_VSYS_LOW, &data, 1);
    *m_pSysV = data;
    this->readBytes(IP2369_ADDR_0_1, R_VSYS_HEIGH, &data, 1);
    *m_pSysV += data << 8;

    return m_pSysV;
}
short* IP2369::GetSysI() {
    uint8_t data;
    this->readBytes(IP2369_ADDR_0_1, R_ISYS_LOW, &data, 1);
    *m_pSysI = data;
    this->readBytes(IP2369_ADDR_0_1, R_ISYS_HEIGH, &data, 1);
    *m_pSysI += data << 8;

    return m_pSysI;
}

short* IP2369::GetSysP() {
    uint8_t data;
    this->readBytes(IP2369_ADDR_0_1, R_PSYS_LOW, &data, 1);
    *m_pSysP = data;
    this->readBytes(IP2369_ADDR_0_1, R_PSYS_HEIGH, &data, 1);
    *m_pSysP += data << 8;

    return m_pSysP;
}

