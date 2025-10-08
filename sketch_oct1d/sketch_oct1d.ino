int pin[3] = {2, 4, 6};
int B = 8;
bool BS = 0;
int j = 0, add = 0 ;
bool Press = 0;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++){
    pinMode(pin[i], OUTPUT);
  }
  pinMode(B, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<=2;i+=1){
     digitalWrite(pin[i], 0);
  }
  // if(digitalRead(B)){
  //   BS = !BS;
  // }
  if(!digitalRead(B) && !Press){
    BS = !BS;
    Press = 1;
    add++;
    //digitalWrite(pin[0], 0);
  }
  else if(digitalRead(B) && Press)
  {
  //   digitalWrite(pin[2], 0);
    Press = 0;
  }
  if(add < 4){
      digitalWrite(pin[add], 1);
  }
  else if(add >= 4){
      digitalWrite(pin[add % 3], 1);
      digitalWrite(pin[(add + 1) % 3], 1);
  }
  if(add == 7){
    add = 0;
  }
  
  delay(10);
}