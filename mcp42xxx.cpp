#include "mcp42xxx.h"

MCP42xxx::MCP42xxx(int selectSlavePin) {
	_selectSlavePin = selectSlavePin;

	// set the slaveSelectPin as an output:
	pinMode(selectSlavePin, OUTPUT);
}

void MCP42xxx::setValue(uint8_t channel, uint8_t value) {
  //select chip
  digitalWrite(_selectSlavePin,LOW);

  //create command
  uint8_t _cmd = 0x00;
  _cmd |= (CMD_WRITE << 5);
  _cmd |= (channel << 0);

  //send command
  SPI.transfer(_cmd);

  //set channel value
  SPI.transfer(value);

  //deselect chip
  digitalWrite(_selectSlavePin,HIGH);
}