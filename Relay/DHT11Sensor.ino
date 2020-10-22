
#include <dht.h>

dht DHT;
#define DHT11_PIN 3

void DHTSetup() {

int check;
  Serial.print("DHT11 Status  \t");
  check = DHT.read(DHT11_PIN);
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
void printDHT1(){
  //humidity and temperature output
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity,1);
 
  Serial.print(".  Temperature: ");
  double result = DHT.temperature;
  
  Serial.println(celToFaren(result));

  
  
}

void DHTLoop(String br){
int check = DHT.read(DHT11_PIN);
double result = DHT.temperature;
      Serial.print(celToFaren(result));
      Serial.print(" F | ");
      Serial.print(result);
      Serial.println(" C");
      Serial.print("Humidity: ");
      Serial.println(DHT.humidity);
      result=0;
}

String getTemp(){
  int check = DHT.read(DHT11_PIN);
 
  double tempC = DHT.temperature;
   double tempF = celToFaren(tempC);
  double humid = DHT.humidity;
  
  String result="{\"temperature\":";
  result +="{ \"farenheit\":\""+ String(tempF)+"\",\"celcius\": \""+String(tempC)+"\",\"humidity\": \""+ String(humid)+"\" } }";
  //result+=",";
  return result;
}

double getTempF(String br){
  int check = DHT.read(DHT11_PIN);
  double result = DHT.temperature;
  //Serial.println(celToFaren(result));
  result = celToFaren(result);
  return result;
}
double getTempC(String br){
  int check = DHT.read(DHT11_PIN);
  double result = DHT.temperature;
  //Serial.println(result);
  return result;
}
double getHumidity(String br){
  int check = DHT.read(DHT11_PIN);
  double result = DHT.humidity;
  //Serial.println(result);
  return result;
}


int celToFaren(double value){

double val = (value * 1.8) + 32;

return val;
}
