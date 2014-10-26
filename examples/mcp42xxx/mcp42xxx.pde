#include <SPI.h>
#include "mcp42xxx.h"

const int slaveSelectPin = 10;

MCP42xxx mcp42xxx(10);

void setup() {
  // initialize SPI
  SPI.begin(); 
}

void loop() {
	//Set channel 1
	mcp42xxx.setValue(CHANNEL_1, 192);
	delay(1000);

	//Set channel 2
	mcp42xxx.setValue(CHANNEL_2, 128);
	delay(1000);

	//Set all channel
	mcp42xxx.setPercent(CHANNEL_ALL, 30);
	delay(2500);
}