int led = 13;
void setup() {
  pinMode(led,OUTPUT);
}
 
void loop() {
  viewS(); 
  viewO();
  viewS();
  
}
 
//显示S
void viewS(){
  for(int i=0;i<3;i++){
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW);
    delay(200);
  }
}
//显示O
void viewO(){
  for(int i=0;i<3;i++){
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
  }
}
