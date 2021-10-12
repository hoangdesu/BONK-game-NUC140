//
// HMC5883 Driver: E-compass
//
// Interface: I2C
// pin1: Vcc to Vcc (+5V)
// pin2: Gnd to Gnd
// pin3: SCL to I2C0_SCL/GPA9
// pin4: SDA to I2C0_SDA/GPA8
// pin5: DRDY N.C.
#include <stdio.h>
#include <stdint.h>
#include "NUC100Series.h"
#include "I2Cdev.h"
#include "HMC5883.h"

void init_HMC5883(void)
{
     I2C_Open(HMC5883_I2C_PORT, 100000);	 // set I2C to 100KHz (10us)
     I2C_WriteBytes(HMC5883_I2C_PORT, HMC5883_I2C_SLA, 0x02, 0x00, 1);
     CLK_SysTickDelay(20000);               // wait for 20ms
}
