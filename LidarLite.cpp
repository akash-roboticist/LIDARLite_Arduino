#include "LidarLite.h"
#include <I2C.h>

LidarLite::LidarLite()
{
}

void LidarLite::initialize_i2c()
{
	I2c.begin(); // Opens & joins the irc bus as master
	delay(100); // Waits to make sure everything is powered up before sending or receiving data  
	I2c.timeOut(50); // Sets a timeout to ensure no locking up of sketch if I2C communication fails
}


void LidarLite::getRange_cm(int16_t* distance)
{	
	// Write 0x04 to register 0x00
	nackack = 100;    
	
	// While NACK keep going (i.e. continue polling until sucess message (ACK) is received )
	while (nackack != 0)
	{ 
		nackack = I2c.write(LIDARLite_ADDRESS,RegisterMeasure, MeasureValue); // Write 0x04 to 0x00
		delay(1); // Wait 1 ms to prevent overpolling
	}
  
	// Read 2byte distance from register 0x8f
	nackack = 100; 
	
	// While NACK keep going (i.e. continue polling until sucess message (ACK) is received )
	while (nackack != 0)
	{ 
		nackack = I2c.read(LIDARLite_ADDRESS,RegisterHighLowB, 2, distanceArray); // Read 2 Bytes from LIDAR-Lite Address and store in array
		delay(1); // Wait 1 ms to prevent overpolling
	}
	
	*distance = (distanceArray[0] << 8) + distanceArray[1];  // Shift high byte [0] 8 to the left and add low byte [1] to create 16-bit int
}