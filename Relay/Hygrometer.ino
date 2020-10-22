#define HYGRO_PIN A0
#define H2 A1
#define H3 A2
#define H4 A3


int value, value2, value3,value4;


void hygroSetup() { 

  pinMode(HYGRO_PIN,INPUT);
  pinMode(H2,INPUT);
  pinMode(H3,INPUT);
  pinMode(H4,INPUT);
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
void printHygro(){
  Serial.println("Soil Humidity: ");

 value= analogRead(HYGRO_PIN);
 value= constrain(value,400,1023);
 value= map(value,400,1023,100,0);

// value2= analogRead(H2);
// value2= constrain(value2,400,1023);
// value2= map(value2,400,1023,100,0);
// 
// value3= analogRead(H3);
// value3= constrain(value3,400,1023);
// value3= map(value3,400,1023,100,0);
//
// value4= analogRead(H4);
// value4= constrain(value4,400,1023);
// value4= map(value4,400,1023,100,0);
//
// 
 Serial.print("H1: ");
 Serial.print(value);
 Serial.print("% \t");

// Serial.print("H2: ");
// Serial.print(value2);
// Serial.print("% \t");
//
// 
// Serial.print("H3: ");
// Serial.print(value3);
// Serial.print("% \t");
// 
// 
// Serial.print("H4: ");
// Serial.print(value4);
// Serial.println("% ");
 delay(1000);
}

void hygroLoop(String br){

if(br.equals("s")){
  value= analogRead(HYGRO_PIN);
 value= constrain(value,400,1023);
 value= map(value,400,1023,100,0);
 Serial.print("Soil Humidity: ");
 Serial.print(value);
 Serial.println("% ");
 //delay(2000);
}
Serial.println("Soil Humidity: ");

 value= analogRead(HYGRO_PIN);
 value= constrain(value,400,1023);
 value= map(value,400,1023,100,0);
Serial.print("H1: ");
 Serial.print(value);
 Serial.println("% ");

//delay(2000);

 value2= analogRead(H2);
 value2= constrain(value2,400,1023);
 value2= map(value2,400,1023,100,0);
Serial.print("H2: ");
 Serial.print(value2);
 Serial.println("% ");


//delay(2000);

 value3= analogRead(H3);
 value3= constrain(value3,400,1023);
 value3= map(value3,400,1023,100,0);
 
 Serial.print("H3: ");
 Serial.print(value3);
 Serial.println("% ");
 //delay(2000);


  value4= analogRead(H4);
 value4= constrain(value4,400,1023);
 value4= map(value4,400,1023,100,0);
 
 Serial.print("H4: ");
 Serial.print(value4);
 Serial.println("% ");
 delay(1000);

    
}
