

#define r1 12
#define r2 11
#define r3 10
#define r4 9
#define r5 8
#define r6 7
#define r7 6
#define r8 5

byte br;

int relayPins[] = {
12,11,10,9,8,7,6,5
};

void relaySetup() {
  // put your setup code here, to run once:
 // Serial.begin(9600);

  pinMode(r1, OUTPUT);
  digitalWrite(r1,1);
  pinMode(r2, OUTPUT);
  digitalWrite(r2,1);
  pinMode(r3, OUTPUT);
  digitalWrite(r3,1);
  pinMode(r4, OUTPUT);
  digitalWrite(r4,1);
  pinMode(r5, OUTPUT);
  digitalWrite(r5,1);
  pinMode(r6, OUTPUT);
  digitalWrite(r6,1);
  pinMode(r7, OUTPUT);
  digitalWrite(r7,1);
  pinMode(r8, OUTPUT);
  digitalWrite(r8,1);

}

void relayLoop(byte br) {
  // put your main code here, to run repeatedly:
  
    if(br == 49){
  
      digitalWrite(r1, 0);
    Serial.println("Light On");
    
    }
    if(br == 48){
       digitalWrite(r1,1);
    Serial.println("Light off");
    
    }
   Serial.print("relay status");
  Serial.println(digitalRead(r1));
 
}

void relay(int relayNum, int state){
  Serial.print("printing from relay. state: ");
  Serial.println(state);
  Serial.print("relay num ");
  Serial.println(relayNum);
  if(state == 1){
    digitalWrite(relayPins[relayNum], 0);
    Serial.println("Light On");
  }
  if(state==0){
     digitalWrite(relayPins[relayNum],1);
    Serial.println("Light off");
  }
}
