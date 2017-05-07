#include <dht.h>


#define RELAY1 7
byte byteRead;


dht DHT;
#define DHT11_PIN 6

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(RELAY1, OUTPUT);
digitalWrite(RELAY1,1);

int check;
Serial.print("DHT11 Status  \t");
check = DHT.read11(DHT11_PIN);
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

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() ){
    byteRead = Serial.read();
  
    if(byteRead == 49){
  
      digitalWrite(RELAY1, 0);
    Serial.println("Light On");
    
    }
    if(byteRead == 48){
       digitalWrite(RELAY1,1);
    Serial.println("Light off");
    
    }

    if(byteRead==51){
      Serial.println(DHT.humidity,1);
    }
    if(byteRead==52){
      Serial.println(celToFaren(DHT.temperature));
    }
    
  }
  
  //humidity and temperature output
Serial.print("Humidity: ");
Serial.print(DHT.humidity,1);
//Serial.print("\n");
Serial.print(".  Temperature: ");
double result = DHT.temperature;

Serial.println(celToFaren(result));


//Serial.print("f temp: ");
//Serial.println(celToFaren(result) );

delay(1000);
 
}

//int celToFaren(double value){
//
//double val = (value * 1.8) + 32;
//
//return val;
//}
