void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  Serial1.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  byte i;
  byte data[6];

 if (Serial1.available() > 6) {
  if(Serial1.read()==255){
    digitalWrite(13,HIGH);
  }else{
      digitalWrite(13,LOW);
  if (Serial1.read() == 255) {
      data[0]=255;
    //  Serial.print(data[0]);
    //  Serial.print (" ");
      for ( i = 1; i<5;i++ )
      {
        data[i] = Serial1.read();
        //     Serial.print(data[i]);
        //     Serial.print(" ");
      }
      analogWrite(3, data[2]);
      analogWrite(6, data[4]);
      if(data[3]==0){
        data[3]=1;
//        if(data[3]==1){
//          data[1]=0;
//          data[3]=0;
//        }
     }
      else{
       data[3]=0;
//        if(data[3]==0){
//          data[1]=1;
//          data[3]=1;
//        }
     }
      digitalWrite(2, data[1]);
      digitalWrite(5, data[3]);
      //  Serial.println();
    }
 }
 }
}
