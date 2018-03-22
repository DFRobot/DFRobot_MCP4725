# MCP4725
MCP4725 is a 12-bit iic-driven high precision DAC module. It has an EEPROM inside, means that the DAC will retain the current voltage output after power-down or reset.


## DFRobot_MCP4725.py Library for Raspberry pi
---------------------------------------------------------
Provides an Raspberry pi library for reading and interpreting Bosch MCP4725 data over I2C.
## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
<snippet>
<content>

## Installation

Download and install smbus library on Raspberry pi. Steps to install smbus are provided at:

$> sudo apt-get install -y python-smbus
$> sudo apt-get install -y i2c-tools

Run the program:

```cpp
 
$> python DFRobot_MCP4725.py

```

Run the demo:

```cpp

$> python OutputVoltage.py

```
## Methods

```C++
/*
 * @brief Set the IIC address
 *        addr = 0x60 or 0x61
 */
def setAddr_MCP4725(self,addr);

/*
 * @brief Setting the base voltage of DAC must equal the power supply voltage,
 *        and the unit is millivolt
 */
def set_refVoltage(self,vol);

/*
 * @brief Output voltage value vol mV
 */
def outputVoltage(self,vol);

/*
 * @brief Output voltage value vol mv and write to the EEPROM,
 *        meaning that the DAC will retain the current voltage output
 *        after power-down or reset
 */
def outputVoltageEEPROM(self,vol);

/*
 * @brief Get the input voltage value
 */
def inputVoltage(self);
```

## Credits

Written by DFRobot_xiaowu, 2018. (Welcome to our [website](https://www.dfrobot.com/))
