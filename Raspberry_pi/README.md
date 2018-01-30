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

https://pypi.python.org/pypi/smbus-cffi/0.5.1 Download (or git pull) the code in pi. 
The Raspberry pi i2c1 and the board's i2c interface connected.
Run the program:

```cpp

$> python DFRobot_MCP4725.py

```

Run the demo:

```cpp

$> python OutputVoltage.py

```

## Credits

Written by DFRobot_xiaowu, 2018. (Welcome to our [website](https://www.dfrobot.com/))
