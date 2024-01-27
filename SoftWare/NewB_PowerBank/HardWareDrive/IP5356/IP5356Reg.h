#ifndef IP5356REG_H
#define IP5356REG_H

// 第一组IIC地址 DS上八位地址0xe8 0xe9 oxea 0xeb arduino用的是7位地址换算一下就是0x74 0x75
#define IP5306_ADDR_0_0             0x74
// 第二组IIC地址
#define IP5306_ADDR_0_1             0x75

// 7：4保留   3：2拔掉输入是否自动转boost输出 1x待机 01有负载boost无负载待机 00开启boost 1boost输出使能 0充电使能
#define SYS_CTL0                0x00
// 7:6保留    5：4轻载关机时间2的（3+x）次方s   3轻载VSYS功率使能   2轻载VSYS电流使能   1:0保留
#define SYS_CTL1                0x03
// 7:3保留    2：0 12V充电欠压值 000/10.7 001/10.9 010/11.3 011/11.4 -- 111/11.8
#define CHG_CTL0                0x0B
// 7:6 2:0 保留  5：3 9V充电欠压值 000/7.98 001/8.13 010/8.65 011/8.58  100/8.5 101/8.43 110/8.13 111/7.98
#define CHG_CTL1                0x0C
// 7:6保留 5：3同充同放电压   2：0 5V充电欠压  傻逼数据爷不抄了
#define CHG_CTL2                0x0D

// 第三组IIC地址的寄存器 R表示只读

// 输入电流 单位0.671387ma
#define R_IVIN_LOW              0x54
#define R_IVIN_HEIGH            0x55
// VBUS(c口)电压  单位1.611328mv
#define R_VBUS_LOW               0x62
#define R_VBUS_HEIGH             0x63

#endif
