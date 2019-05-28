#define HYGRO_PIN 0
int value;


void hygroSetup() { 

  pinMode(HYGRO_PIN,INPUT);
//int check;
//  Serial.print("Hygrometer Status  \t");
//  check = DHT.read(HYGRO_PIN);
//  //check status
//  switch (check)
//  {
//  case DHTLIB_OK:
//    Serial.print("OK\n");
//    break;
//  case DHTLIB_ERROR_CHECKSUM:
//    Serial.print("Checksum error\n");
//    break;
//  case DHTLIB_ERROR_TIMEOUT:
//    Serial.print("Timeout error\n");
//    break;
//  default:
//    Serial.print("Unknown error\n");
//    break;
//  }
  
}


void hygroLoop(String br){

if(br=="s"){
  value= analogRead(HYGRO_PIN);
 value= constrain(value,400,1023);
 value= map(value,400,1023,100,0);
 Serial.print("Soil Humidity: ");
 Serial.print(value);
 Serial.println("% ");
 delay(2000);
}
 value= analogRead(HYGRO_PIN);
 value= constrain(value,400,1023);
 value= map(value,400,1023,100,0);
 Serial.print("Soil Humidity: ");
 Serial.print(value);
 Serial.println("% ");
 delay(2000);

    
}
