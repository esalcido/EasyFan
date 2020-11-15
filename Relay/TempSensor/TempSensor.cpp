
#include "dht.h"
#include "TempSensor.h"

TempSensor::TempSensor(int pin)
{
	pinMode(pin,OUTPUT);
	_pin = pin;

	
}

void TempSensor::setup(){
	Serial.print("DHT11 Status  \t");
	  check = DHT.read(_pin);
	  //check status
	  switch (check)
	  {
	  case DHTLIB_OK:
	    Serial.print("OK\n");
	    break;
	  case DHTLIB_ERROR_CHECKSUM:
	    Serial.print("Checksum error\n");
	    break;
	  case DHTLIB_ERROR_TIMEOUT:
	    Serial.print("Timeout error\n");
	    break;
	  default:
	    Serial.print("Unknown error\n");
	    break;
	  }
}

String TempSensor::getTemp(){
	int check = DHT.read(_pin);

	double tempC = DHT.temperature;
	double tempF = celToFaren(tempC);
	double humid = DHT.humidity;

	//String result="{\"temperature\":";
	//String result="[";
	String result ="{ \"pin\":\""+ String(_pin)+"\", \"farenheit\":\""+ String(tempF)+"\",\"celcius\": \""+String(tempC)+"\",\"humidity\": \""+ String(humid)+"\" } ";
	//result+=",";
	return result;
}

double TempSensor::celToFaren(double value){

	double val = (value * 1.8) + 32;

	return val;
}