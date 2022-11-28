#include <SoftwareSerial.h>
SoftwareSerial mygsm(7,8);
void setup() {
  mygsm.begin(9600);
  Serial.begin(9600);
  Serial.println("Function letters  ");
  Serial.println("S --> send message");
  Serial.println("A --> Answer call");
  Serial.println("C --> Get call");
  Serial.println("X --> Cut Call");
 
}

void loop() {
 if(Serial.available()>0){
  switch (Serial.read()){
    case 's' :
    sendMessaage();
    break;
    
    case 'a' :
    getCall();
    break;
    
    case 'c' :
    receiveCall();
    break;
   
    case 'x' :
    cutCall();
    break;
    }
    if(mygsm.available()>0){
      Serial.write(mygsm.read());
      }
  }
}
void sendMessaage(){
  mygsm.println("AT+CMGF=1");
  delay(1000);
  mygsm.println("AT+CMGS=\"+94778367497\"\r");
  delay(1000);
  mygsm.println("This message from arduino gsm module");
  delay(1000);
  mygsm.println((char)26);
  delay(1000);
  }
void getCall(){
  mygsm.println("ATD+94778367497;");
  Serial.print("Calling");
  delay(500);
  Serial.print(".");
  delay(500);
  Serial.print(".");
  delay(500);
  Serial.println(".");
  }

void  receiveCall(){
  mygsm.println("ATA");
  delay(1000);
  }

void cutCall(){
  mygsm.println("ATH");
  Serial.println("Cut Call");
  delay(1000);
  
  
  }
  
