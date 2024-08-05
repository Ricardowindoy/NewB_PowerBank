#ifndef IP5356REG_H
#define IP5356REG_H

// 第一组IIC地址 DS上八位地址0xe8 0xe9 oxea 0xeb arduino用的是7位地址换算一下就是0x74 0x75
#define IP2369_ADDR_0_0             0x74
// 第二组IIC地址
#define IP2369_ADDR_0_1             0x75


// IBAT电流 单位0.671387ma
#define R_IVIN_LOW              0x50
#define R_IVIN_HEIGH            0x51
// VBAT电压  单位1.611328mv
#define R_VBUS_LOW               0x6e
#define R_VBUS_HEIGH             0x6f

#endif
