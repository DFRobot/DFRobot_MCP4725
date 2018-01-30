import smbus
import time

# Get I2C bus
bus = smbus.SMBus(1)

# I2C address of the device
MCP4725A0_IIC_Address0				= 0x60
MCP4725A0_IIC_Address1				= 0x61
MCP4725_Write_CMD             = 0x40
MCP4725_WriteEEPROM_CMD       = 0X60
MCP4725_NORMAL_MODE			      = 0X00 
MCP4725_POWER_DOWN_1KRES			= 0X01 
MCP4725_POWER_DOWN_100KRES		= 0X02
MCP4725_POWER_DOWN_500KRES		= 0X03 

addr_G=MCP4725A0_IIC_Address0
OutVol_G=1000
class MCP4725():
	def setAddr_MCP4725(self,addr):
		global addr_G
		addr_G = addr	
	def set_refVoltage(self,vol):
		global voltage_G
		voltage_G = vol	
	def outputVoltage(self,vol):
		global addr_G	
		global voltage_G
		bus.write_word_data(addr_G,MCP4725_Write_CMD | (MCP4725_NORMAL_MODE<<1) ,int((vol/float(voltage_G))*4095))
	def outputVoltageEEPROM(self,vol):
		global addr_G
		global voltage_G
		bus.write_word_data(addr_G,MCP4725_WriteEEPROM_CMD | (MCP4725_NORMAL_MODE<<1) ,int((vol/float(voltage_G))*4095))
	def inputVoltage(self):
		global OutVol_G
		OutVol_G = int(input("Please input voltage = "))
		while OutVol_G > 5000 :
			OutVol_G = int(input("Please input voltage = "))
		return OutVol_G	