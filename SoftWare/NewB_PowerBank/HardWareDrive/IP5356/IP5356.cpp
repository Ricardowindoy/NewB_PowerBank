#include <Wire.h>
#include <Arduino.h>
#include "IP5356.h"

/*
    Notice:
    endTransmission() returns:
    0: success.
    1: data too long to fit in transmit buffer.
    2: received NACK on transmit of address.
    3: received NACK on transmit of data.
    4: other error.
    5: timeout
*/


void IP5306::begin(uint8_t sdaPin, uint8_t sclPin) {
    m_pTypecV = new short();
    m_pTypecI = new short();

    Wire.setPins(sdaPin, sclPin);
    Wire.begin();
}

uint8_t IP5306::writeBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity) {
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.write(data, quantity);
    uint8_t res = Wire.endTransmission();
    if (res != 0) {
        log_e("IP5306 i2c write error: %d", res);
    }
    return res;

}
uint8_t IP5306::readBytes(uint8_t addr, uint8_t reg, uint8_t *data, uint8_t quantity) {
    Wire.beginTransmission(addr);
    Wire.write(reg);
    uint8_t res = Wire.endTransmission(false);
    if (res != 0) {
        Serial.printf("IP5356 i2c write error: %d\n", res);
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


short* IP5306::GetTypecV() {
    uint8_t data;
    this->readBytes(IP5306_ADDR_0_1, R_VBUS_LOW, &data, 1);
    *m_pTypecV = data;
    this->readBytes(IP5306_ADDR_0_1, R_VBUS_HEIGH, &data, 1);
    *m_pTypecV += data << 8;

    return m_pTypecV;
}

short* IP5306::GetTypecI() {
    uint8_t data;
    this->readBytes(IP5306_ADDR_0_1, R_IVIN_LOW, &data, 1);
    *m_pTypecI = data;
    this->readBytes(IP5306_ADDR_0_1, R_IVIN_HEIGH, &data, 1);
    *m_pTypecI += data << 8;

    return m_pTypecI;
}
