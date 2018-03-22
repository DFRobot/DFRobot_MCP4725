/*
 * file OutputVoltage.ino
 *
 * @ https://github.com/DFRobot/DFRobot_MCP4725
 *
 * connect MCP4725 I2C interface with your board (please reference board compatibility)
 *
 * Output a constant voltage value and print through the serial port.
 *
 * Copyright   [DFRobot](http://www.dfrobot.com), 2016
 * Copyright   GNU Lesser General Public License
 *
 * version  V0.1
 * date  2018-1-25
 */
#include "Wire.h"
#include "DFRobot_MCP4725.h"

#define  REF_VOLTAGE    5000

DFRobot_MCP4725 DAC;

int i =0;
void setup(void) {
  Serial.begin(115200);
  /* MCP4725A0_address is 0x60 or 0x61  
   * MCP4725A0_IIC_Address0 -->0x60
   * MCP4725A0_IIC_Address1 -->0x61
   */
  DAC.init(MCP4725A0_IIC_Address0, REF_VOLTAGE);
}

void loop(void) {
  /*Output a magnitude of 5000mv, the frequency of 10HZ, DC offset 2500mv sine wave*/
  DAC.outputSin(2500,10,2500);
}