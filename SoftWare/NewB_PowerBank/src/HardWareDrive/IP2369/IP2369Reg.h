#ifndef IP2369REG_H
#define IP2369REG_H

// 第一组IIC地址 DS上八位地址0xe8 0xe9 oxea 0xeb arduino用的是7位地址换算一下就是0x74 0x75
#define IP2369_ADDR_0_0             0x74
// 第二组IIC地址
#define IP2369_ADDR_0_1             0x75


// IBAT 电池端电流 单位ma
#define R_IBAT_LOW              0x6e
#define R_IBAT_HEIGH            0x6f
// VBAT 电池端电压 单位mv
#define R_VBAT_LOW               0x50
#define R_VBAT_HEIGH             0x51

// ISYS
#define R_ISYS_LOW              0x70
#define R_ISYS_HEIGH            0x71
// VSYS 
#define R_VSYS_LOW               0x52
#define R_VSYS_HEIGH             0x53
// PSYS
#define R_PSYS_LOW               0x74
#define R_PSYS_HEIGH             0x75

#endif
