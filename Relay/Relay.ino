
#define RELAY1 7
byte byteRead;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(RELAY1, OUTPUT);
digitalWrite(RELAY1,1);
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
}
  

 
  
  
}
