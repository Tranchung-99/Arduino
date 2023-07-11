#include<ADS1115_WE.h>
#include<Wire.h>


#define I2C_ADDRESS_1 0x48
#define I2C_ADDRESS_2 0x49

ADS1115_WE adc_1 = ADS1115_WE(I2C_ADDRESS_1);
ADS1115_WE adc_2 = ADS1115_WE(I2C_ADDRESS_2);

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  Serial1.begin(115200);
  Wire.begin();
  adc_1.setVoltageRange_mV(ADS1115_RANGE_0256);
  adc_1.setMeasureMode(ADS1115_CONTINUOUS);
  adc_1.setCompareChannels(ADS1115_COMP_0_GND);
  adc_1.setConvRate(ADS1115_64_SPS);
  adc_1.setPermanentAutoRangeMode(true);
  adc_2.setVoltageRange_mV(ADS1115_RANGE_0256);
  adc_2.setMeasureMode(ADS1115_CONTINUOUS);
  adc_2.setCompareChannels(ADS1115_COMP_0_1);
  adc_2.setConvRate(ADS1115_64_SPS);
  adc_2.setPermanentAutoRangeMode(true);
  //Timer1.initialize(100000);
  //Timer1.attachInterrupt

}

void loop() {
  // put your main code here, to run repeatedly:
  byte i;
  byte data[6];
  float voltage1;
  float voltage2, voltage3;

  float gauge1 ;
  float gauge2 ;
  float gauge3 ;
   voltage1 = readChannel(ADS1115_COMP_0_1);
    //delay(320);
    voltage2 = readChannel(ADS1115_COMP_2_3);
    voltage3 = readChannel2(ADS1115_COMP_0_1);
    gauge1 = abs(voltage1);
    //gauge1=byte(gauge1*100);
    //gauge1=int(gauge1);
    gauge2 = abs(voltage2);
    gauge3 = abs(voltage3);
    Serial.print(gauge1);
    Serial.print(" ");
    Serial.print(gauge2);
    Serial.print(" ");
    Serial.print(gauge3);
    Serial.println();
  

  // put your main code here, to run repeatedly:

  if (Serial1.available() > 6) {
   
    if (Serial1.read() == 255) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);

      if (Serial1.read() == 255) {
        data[0] = 255;
        //Serial.print(data[0]);
        Serial.print (" ");
        for ( i = 1; i < 5; i++ )
        {
          data[i] = Serial1.read();
          //Serial.print(data[i]);
          
        }
                   

        if (gauge1 > 0.8 || gauge2 > 1.0 || gauge3 > 1.0) {
            analogWrite(6, 150);
            analogWrite(3, 150);
            digitalWrite(2, 0);
            digitalWrite(5, 1);
            delay(1500);
            analogWrite(3, 127);
            analogWrite(6, 0);
            digitalWrite(2, 1);
            digitalWrite(5, 1);
            delay(2500);
            analogWrite(6, 127);
            analogWrite(3, 0);
            digitalWrite(2, 1);
            digitalWrite(5, 0);
            delay(1250);
            analogWrite(6, 127);
            analogWrite(3, 127);
            digitalWrite(2, 1);
            digitalWrite(5, 0);
             delay(2800);
         
        }
            
        else{
          analogWrite(3, data[2]);
          analogWrite(6, data[4]);
          if (data[3] == 1) {
            data[3] = 0;
//            if (data[3] == 1) {
//             data[1] = 0;
//              data[3] = 0;
           }
////          
            else {
              data[3] = 1;
            }
          }
//          else {
//            data[1] = 0;
//            if (data[3] == 0) {
//              data[1] = 1;
//              data[3] = 1;
//            }
//            else {
//              data[3] = 0;
//            }
          

          digitalWrite(2, data[1]);
          digitalWrite(5, data[3]);
          
        

       // }
        
        //Serial.println();
      }
      // static float tara = 0.0;
    }

  }

}


float readChannel(ADS1115_MUX channel) {
  float voltage = 0.0;
  adc_1.setCompareChannels(channel);

  voltage = adc_1.getResult_mV();
  return voltage;
}
float readChannel2(ADS1115_MUX channel) {
  float voltage = 0.0;
  adc_2.setCompareChannels(channel);
  voltage = adc_2.getResult_mV();
  return voltage;
}
