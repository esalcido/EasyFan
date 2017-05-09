
byte byteRead;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  relaySetup();

  DHTSetup();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() ){
    byteRead = Serial.read();
  
   relayLoop( byteRead);

   DHTLoop(byteRead);
    
  }
  
  printDHT();
  
  delay(1000);
 
}

void printDHT(){
  //humidity and temperature output
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity,1);
  //Serial.print("\n");
  Serial.print(".  Temperature: ");
  double result = DHT.temperature;
  
  Serial.println(celToFaren(result));
  
}


