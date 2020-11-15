#include <TempSensor.h>
#include <CapacitiveSoilSensor.h>

TempSensor tempSensor1(3);
TempSensor tempSensor2(4);

CapacitiveSoilSensor soil(A0);

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
  Serial.begin(115200);

  tempSensor1.setup();
  tempSensor2.setup();
  
  relaySetup();

//  DHTSetup();

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

    command = readString.substring(0,1);
    rel =     readString.substring(2,3).toInt();
    state1 =  readString.substring(4,5).toInt();

    if(command.equals("a")){
       String json = "[{";
      
      //get relay json
      json+= relay_states();
      json+=",";

      //get temp sensor data and format
      String result = tempSensor1.getTemp();
      String result2 = tempSensor2.getTemp();
      String jsonString = "\"temps\":[";
      jsonString+=result+","+result2;
      jsonString+="]";
      //get temperature json
      //json+=getTemp();
      json+=jsonString;
      
      json+="}]";
     Serial.println(json);
     //Serial.flush();
     
      readString = "";
    }
    
    if(command.equals("r")){
      
      String result = relay(rel,state1);

      
      
     // Serial.println(result);
      readString = "";
    }
    if(command.equals("s")){
      Serial.print("soil");
       hygroLoop(readString );

       readString = "";
    }
   if(command.equals("t")){
    
     String result = tempSensor1.getTemp();
     String result2 = tempSensor2.getTemp();
     String json = "[";
     
     json+=result+","+result2;
     json+="]";
      Serial.println(json);     
//     Serial.println(result);
//     Serial.println(" ");
//     Serial.println(result2);

     readString = "";
   }
   if(command.equals("c")){
      getTempC(readString);

      readString = "";
   }
   if(command.equals("h")){
      getHumidity(readString);

      readString = "";
   }
   
   if(command.equals("u")){
     //Serial.print("temp");
     
      String rs = relay_states();
     String rs1 = "{";
     rs1+=rs;
     rs1+="}"; 
      Serial.println(rs1);
      readString = "";
   }

    if(command.equals("v")){
     //Serial.print("temp");
      String rs = relay_states();
      
      Serial.println(rs);
      readString = "";
   }
  }

String json = "[{";
      
      //get relay data
      json+= relay_states();
      json+=",";

      //get temp sensor data and format
      String result = tempSensor1.getTemp();
      String result2 = tempSensor2.getTemp();
      String jsonString = "\"temps\":[";
      jsonString+=result+","+result2;
      jsonString+="]";
      
      //get temperature jsons
      json+=jsonString;

      //get soil reading
      String soilData = ",\"soil\":";
      int sd = soil.getMoistureValue();
      soilData += sd;
//      soilData+="]";
      json+=soilData;

      
      json+="}]";
      
      //Print All json data
     Serial.println(json);

//     int soilValue = soil.getMoistureValue();
//     Serial.println(soilValue);

     delay(2000);

 
}
