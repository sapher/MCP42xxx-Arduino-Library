#ifndef _MCP42XXX_H_
#define _MCP42XXX_H_

#include <SPI.h>

//Channels
enum {
	CHANNEL_NONE = 0x0,
	CHANNEL_1 =    0x1,
	CHANNEL_2 =    0x2,
	CHANNEL_ALL =  0x3 
};

//Commands
enum {
	CMD_WRITE    = 0x1,
	CMD_SHUTDOWN = 0x2
};

class MCP42xxx {
public:
	MCP42xxx(int selectSlavePin);
	void setValue(uint8_t channel, uint8_t value);
	void setPercent(uint8_t channel, uint8_t percentage);
private:
	int _selectSlavePin;
};

#endif /* #ifndef _MCP42XXX_H_ */