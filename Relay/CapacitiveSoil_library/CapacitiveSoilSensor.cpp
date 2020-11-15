#include "CapacitiveSoilSensor.h"
#include "Arduino.h"

 CapacitiveSoilSensor::CapacitiveSoilSensor(int pin)
 {
 	_pin = pin;
 	const int AirValue = 520;
 	const int WaterValue = 260;
 	int intervals = (AirValue - WaterValue)/3;
 	int soilMoisture = 0;

 }

 // void CapacitiveSoilSensor::setup(){
 // 	Serial.begin(115200);
 // }

int CapacitiveSoilSensor::getMoistureValue(){
	soilMoistureValue = analogRead(_pin);  //put Sensor insert into soil
	
	// Serial.println("getting moisture value.\n");
	// Serial.println(soilMoistureValue);

	if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
	{
  		Serial.println("Very Wet");
	}
	else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
	{
  		Serial.println("Wet");
	}
	else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
	{
  		Serial.println("Dry");
	}
	// delay(100);

	return soilMoistureValue;

}
