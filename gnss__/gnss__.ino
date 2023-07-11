void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int data[2];
  data[0]=Serial.read();
  if(data[0]=1){
    
  data[1]=(Serial.read());
  Serial.print(data[0]);
  Serial.println(data[1]);
  }
  
}
