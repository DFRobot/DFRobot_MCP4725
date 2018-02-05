# DFRobot_MCP4725 Gravity： 12-Bit I2C DAC Module

MCP4725 is a 12-bit iic-driven high precision DAC module. It has an EEPROM inside, 
means that the DAC will retain the current voltage output after power-down or reset.

## DFRobot_MCP4725 Library for Arduino
---------------------------------------------------------
Provides an Arduino library for reading and interpreting Bosch MCP4725 data over I2C.

## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

<snippet>
<content>

## Installation

To use this library download the zip file, uncompress it to a folder named DFRobot_MCP4725. 
Download the zip file first to use this library and uncompress it to a folder named DFRobot_MCP4725. 

## Methods

```C++
/* The IIC address of MCP4725A0 may be 0x60 or 0x61, 
   depending on the location of the dial code switch on the sensor. */
#define MCP4725A0_IIC_Address0  0x60   
#define MCP4725A0_IIC_Address1  0x61

#define MCP4725_NORMAL_MODE          0
#define MCP4725_POWER_DOWN_1KRES     1
#define MCP4725_POWER_DOWN_100KRES   2
#define MCP4725_POWER_DOWN_500KRES   3

/*
 * @brief init MCP4725 device
 *
 * @param addr:
 *        Init the IIC address.
 *        vRef:
 *        The DAC base voltage setting must be equal to the power supply, and the unit is millivolt.
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
 *@brief  Output voltage value range 0-vRef.
 *    
 *@param  voltage
 *        Voltage value, range 0-vRef, unit millivolt.
 */
  void outputVoltage(uint16_t voltage);
/* 
 *@brief  Output voltage value range 0-vRef mv and write to the EEPROM,
 *        meaning that the DAC will retain the current voltage output
          after power-down or reset.
 *@param  voltage
 *        Voltage value, range 0-vRef, unit millivolt.
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

```

## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
FireBeetle-ESP32  |      √       |             |            | 
FireBeetle-ESP8266  |      √       |             |            | 
Arduino uno |       √      |             |            | 

## History

- Jan 15, 2018 - Version 0.1 released.

## Credits

Written by DFRobot_YangYue, 2018. (Welcome to our [website](https://www.dfrobot.com/))
