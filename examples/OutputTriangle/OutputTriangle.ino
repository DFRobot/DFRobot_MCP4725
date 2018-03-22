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
  /*Output amplitude 5000mv, frequency 10HZ, 
   *the rise of the entire cycle accounted for 50% of the DC offset 0mv triangular wave.
   */
  DAC.outputTriangle(5000,10,0,50);
}