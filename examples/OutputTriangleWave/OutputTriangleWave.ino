/*
 * file OutputTriangleWave.ino
 *
 * @ https://github.com/DFRobot/DFRobot_MCP4725
 *
 * connect MCP4725 I2C interface with your board (please reference board compatibility)
 *
 * Output triangular wave and print through serial port.
 *
 * Copyright   [DFRobot](http://www.dfrobot.com), 2016
 * Copyright   GNU Lesser General Public License
 *
 * version  V0.1
 * date  2018-1-15
 */
#include "DFRobot_MCP4725.h"
#define  REF_VOLTAGE    5000

DFRobot_MCP4725 DAC;

void setup(void) {
  
  Serial.begin(115200);
  /* MCP4725A0_address is 0x60 or 0x61  
   * MCP4725A0_IIC_Address0 -->0x60
   * MCP4725A0_IIC_Address1 -->0x61
   */
  DAC.init(MCP4725A0_IIC_Address1, REF_VOLTAGE);
  Serial.println("DFRobot_MCP4725 output triangle wave...");
}

void loop(void) {
    uint16_t value;

    for (value = 0; value < REF_VOLTAGE; value++)
    {
      DAC.outputVoltage(value);
    }
    for (value = REF_VOLTAGE; value > 0; value--)
    {
      DAC.outputVoltage(value);
    }
}