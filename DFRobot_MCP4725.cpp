
#include "DFRobot_MCP4725.h"


void DFRobot_MCP4725::init(uint8_t addr, uint16_t vRef) 
{
  byte error;
  _IIC_addr = addr;
  _refVoltage = vRef;
  _PowerMode = MCP4725_NORMAL_MODE;
  Wire.begin();
  Wire.beginTransmission(_IIC_addr);
     
  error = Wire.endTransmission();
  while(error)
  {
     Wire.beginTransmission(_IIC_addr);
     
     error = Wire.endTransmission();
     Serial.println("ERROR! Not found I2C device address ");
     delay(500);
  }
}

void DFRobot_MCP4725::setMode(uint8_t powerMode)
{
  _PowerMode = powerMode;
  outputVoltage(_voltage);
}

void DFRobot_MCP4725::outputVoltage( uint16_t voltage)
{
  uint16_t data = 0;
  _voltage = voltage;
  if(_voltage > _refVoltage)
  {
     Serial.print("ERROR! The input voltage is greater than the maximum voltage!");
     return ;
  }
  else
  {
    data = (uint16_t)(((float)_voltage / _refVoltage) * 4095);
  
    Wire.beginTransmission(_IIC_addr);
  
    Wire.write(MCP4725_Write_CMD | (_PowerMode << 1));

    Wire.write(data / 16);
    Wire.write((data % 16) << 4);
    Wire.endTransmission();
  }
}

void DFRobot_MCP4725::outputVoltageEEPROM( uint16_t voltage)
{
  uint16_t data = 0;
  _voltage = voltage;
  if(_voltage > _refVoltage)
  {
     Serial.print("ERROR! The input voltage is greater than the maximum voltage!");
     return ;
  }
  else
  {
    data = (uint16_t)(((float)_voltage / _refVoltage) * 4095);
  
    Wire.beginTransmission(_IIC_addr);
  
    Wire.write(MCP4725_WriteEEPROM_CMD | (_PowerMode << 1));

    Wire.write(data / 16);
    Wire.write((data % 16) << 4);
    Wire.endTransmission();
  }
}
