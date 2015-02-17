/*
 *	
 *	Function library for easy interface of Lidar Lite with Arduino
 *	using I2C library
 *
 */
#include <Arduino.h>
#include <I2C.h>
#define    LIDARLite_ADDRESS   0x62          // Default I2C Address of LIDAR-Lite.
#define    RegisterMeasure     0x00          // Register to write to initiate ranging.
#define    MeasureValue        0x04          // Value to initiate ranging.
#define    RegisterHighLowB    0x8f          // Register to get both High and Low bytes in 1 call.

class LidarLite
{
	public:
		LidarLite();
		void getRange_cm(int16_t* distance);
		void initialize_i2c();
		
	private:
		uint8_t nackack; // Setup variable to hold ACK/NACK responses     
		byte distanceArray[2]; // array to store distance bytes from read function
};