#include "LidarLite.h"
#include <I2C.h> // Improved I2C library for Arduino

#define LED_PIN 13
LidarLite sensor_1; //Define Lidar Lite
int16_t range_1;
int32_t aq_time=0;

void setup()
{
	Serial.println("Initializing I2C");
	sensor_1.initialize_i2c(); //needed only once for any number of sensors
}

void loop()
{
	if((millis() - aq_time) > 100)
	{
		sensor_1.getRange_cm(&range_1);
		aq_time = millis();
		
		Serial.print("Range_1: ");
		Serial.print(range_1);
		Serial.println(" cm");
	}	
	
}