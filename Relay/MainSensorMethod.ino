
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
    //Serial.println(readString);


    command = readString.substring(0,1);
    rel =     readString.substring(2,3).toInt();
    state1 =  readString.substring(4,5).toInt();

    if(command.equals("a")){
       String json = "{";
      //get relay json
      json+= relay_states();
      json+=",";
       //get temperature json
      json+=getTemp();
      //json+=",";
      json+="}";
     Serial.println(json);
     Serial.flush();
     
      readString = "";
    }
    
    if(command.equals("r")){
//      Serial.print("command: ");
//      Serial.println(command);
//      Serial.print("rel: ");
//      Serial.println(String(rel));
//      Serial.print("state: ");
//      Serial.println(state1);
      
      String result = relay(rel,state1);
      Serial.println(result);
      readString = "";
    }
    if(command.equals("s")){
      Serial.print("soil");
       hygroLoop(readString );

       readString = "";
    }
   if(command.equals("t")){
     String result = getTemp();
     Serial.println(result);
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
      int rs = relay_state(rel);
      
      Serial.println(rs);
      readString = "";
   }

    if(command.equals("v")){
     //Serial.print("temp");
      String rs = relay_states();
      
      Serial.println(rs);
      readString = "";
   }
  }
 
}
