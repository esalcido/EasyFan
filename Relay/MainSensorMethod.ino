
char byteRead;
String serialResponse = "", relayNum, state;//130,hi,7.2,389*
char strings[32];

String readString; //main captured String 
String angle; //data String
String fuel;
String speed1;
String altidude;

String command;
int rel, state1;

int ind1; // , locations
int ind2;
int ind3;
int ind4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  relaySetup();

  DHTSetup();

 hygroSetup();

}

void loop() {
 
  // put your main code here, to run repeatedly:

  while(Serial.available() ){
    delay(3);
     if(Serial.available()>0 ){
      
      char c = Serial.read();
      readString+=c;
     }
    
  }

  if(readString.length() >0){
    Serial.println(readString);


    command = readString.substring(0,1);
    rel =     readString.substring(2,3).toInt();
    state1 =  readString.substring(4,5).toInt();
    
    if(command.equals("r")){
      Serial.print("command: ");
      Serial.println(command);
      Serial.print("rel: ");
      Serial.println(String(rel));
      Serial.print("state: ");
      Serial.println(state1);
      
      relay(rel,state1);
      readString = "";
    }
    if(command.equals("s")){
      Serial.print("soil");
       hygroLoop(readString );

       readString = "";
    }
   if(command.equals("t")){
     Serial.print("temp");
      DHTLoop(readString);

      readString = "";
   }

  }
printDHT1();
  printHygro();
// 
//   //relayLoop( byteRead);
//
   //DHTLoop(byteRead);
//
//hygroLoop(byteRead);
//
//   
//    
//  }
  
 
  
  delay(1000);
 
}

void printDHT(){
  //humidity and temperature output
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity,1);
 
  Serial.print(".  Temperature: ");
  double result = DHT.temperature;
  
  Serial.println(celToFaren(result));

  
  
}
