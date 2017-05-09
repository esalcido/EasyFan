

#define RELAY1 7
byte br;


void relaySetup() {
  // put your setup code here, to run once:
 // Serial.begin(9600);

  pinMode(RELAY1, OUTPUT);
  digitalWrite(RELAY1,1);

}

void relayLoop(byte br) {
  // put your main code here, to run repeatedly:
  
    if(br == 49){
  
      digitalWrite(RELAY1, 0);
    Serial.println("Light On");
    
    }
    if(br == 48){
       digitalWrite(RELAY1,1);
    Serial.println("Light off");
    
    }
    

 
}


