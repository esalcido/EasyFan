
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


void DHTLoop(byte br){

 if(br==50){
      Serial.print("Humidity: ");
      Serial.println(DHT.humidity,1);
    }
    if(br==51){
      Serial.print("temp: ");
      Serial.println(celToFaren(DHT.temperature));
    }

    
}



int celToFaren(double value){

double val = (value * 1.8) + 32;

return val;
}
