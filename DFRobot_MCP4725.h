
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

#define MCP4725_Write_CMD            0x40     // Write data to the DAC address.
#define MCP4725_WriteEEPROM_CMD      0x60     // Write data to the DAC EEPROM address.

/* The IIC address of MCP4725A0 may be 0x60 or 0x61, 
   depending on the location of the dial code switch on the sensor. */
#define MCP4725A0_IIC_Address0       0x60   
#define MCP4725A0_IIC_Address1       0x61

#define MCP4725_NORMAL_MODE          0
#define MCP4725_POWER_DOWN_1KRES     1
#define MCP4725_POWER_DOWN_100KRES   2
#define MCP4725_POWER_DOWN_500KRES   3

class DFRobot_MCP4725{
  public:
/*
 * @brief init MCP4725 device
 *
 * @param addr:
 *        Init the IIC address.
 *        vRef:
 *        Setting the base voltage of DAC must equal the power supply voltage, and the unit is millivolt.
 */
  void init(uint8_t addr, uint16_t vRef);
/*
 * @brief set power mode 
 *
 * @param 
 *        powerMode:
 *        Set power mode,three are normal mode and power down mode.
 *        The following are three modes of power down.
 *        MCP4725_POWER_DOWN_1KRES      1 kΩ resistor to ground
 *        MCP4725_POWER_DOWN_100KRES    100 kΩ resistor to ground
 *        MCP4725_POWER_DOWN_500KRES    500 kΩ resistor to ground
 */
  void setMode(uint8_t powerMode);
/* 
 *@brief  Output voltage value range 0-5000mv.
 *    
 *@param  voltage
 *        Voltage value, range 0-5000, unit millivolt.
 */
  void outputVoltage(uint16_t voltage);
/* 
 *@brief  Output voltage value range 0-5000mv and write to the EEPROM,
 *        meaning that the DAC will retain the current voltage output
          after power-down or reset.
 *@param  voltage
 *        Voltage value, range 0-5000, unit millivolt.
 */
  void outputVoltageEEPROM(uint16_t voltage);
/* 
 *@brief  Output a sine wave.
 *    
 *@param  amp:
 *        amp value, Output sine wave amplitude range 0-5000mv
 *        freq:
 *        freq value,Output sine wave frequency
 *        offset:
 *        offset value,Output sine wave DC offset
 *
 */
  void outputSin(uint16_t amp, uint16_t freq, uint16_t offset);
 /* 
 *@brief  Output a sine wave.
 *    
 *@param  amp:
 *        amp value, Output triangular wave amplitude range 0-5000mv
 *        freq:
 *        freq value,Output the triangle wave frequency
 *        offset:
 *        offset value,Output the DC offset of the triangle wave
 *        dutyCycle:
 *        dutyCycle value,Set the rising percentage of the triangle wave as a percentage of the entire cycle.
 *                  Value range 0-100 (0 for only the decline of 100, only the rise of paragraph)
 *
 */
  void outputTriangle(uint16_t amp, uint16_t freq, uint16_t offset, uint8_t dutyCycle);
  
  bool check_mcp4725();

 private:
  uint8_t  _IIC_addr;
  uint8_t  _PowerMode;
  uint16_t _refVoltage;
  uint16_t _voltage;
};
