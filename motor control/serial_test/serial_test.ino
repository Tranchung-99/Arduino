void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  byte data[1];
  if(Serial1.available()){
   data[0]=Serial1.read();
   Serial.print(data[0]);
  }
}
