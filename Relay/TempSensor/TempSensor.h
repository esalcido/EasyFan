/*
	TempSensor.h - Library for the Temperature Sensor code.
	by Edward Salcido
*/

#ifndef TempSensor_h
#define TempSensor_h

#include "dht.h"


class TempSensor
{
public:
	TempSensor(int pin);
	void setup();
	String getTemp();
	double celToFaren(double value);
private:
	int _pin;
	int check;
	dht DHT;

};

#endif