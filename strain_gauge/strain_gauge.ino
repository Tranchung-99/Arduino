#include<ADS1115_WE.h>
#include<Wire.h>
#include <SoftwareSerial.h>

#define I2C_ADDRESS_1 0x48
#define I2C_ADDRESS_2 0x49

ADS1115_WE adc_1 = ADS1115_WE(I2C_ADDRESS_1);
ADS1115_WE adc_2 = ADS1115_WE(I2C_ADDRESS_2);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial1.begin(115200);
  Serial.begin(115200);
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
  pinMode(13, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,LOW);
  byte load[3];
  float voltage1;
  float voltage2, voltage3;

  float gauge1 ;
  float gauge2 ;
  float gauge3 ;
  // static float tara = 0.0;
  voltage1 = readChannel(ADS1115_COMP_0_1);
  //delay(320);
  voltage2 = readChannel(ADS1115_COMP_2_3);
  voltage3 = readChannel2(ADS1115_COMP_0_1);
  gauge1 = abs(voltage1);
  //gauge1=byte(gauge1*100);
  //gauge1=int(gauge1);
  gauge2 = abs(voltage2);
  gauge3 = abs(voltage3);

  //byte x1 = mySerial.write(load[0]);
  //byte x2=Serial.write(load[0]);
  Serial.print(gauge1);
  Serial.print(" ");
  Serial.print(gauge2);
  Serial.print(" ");
  Serial.print(gauge3);
  Serial.print(" ");
  Serial.println();
 // delay(95);
//voltage = readChannel(ADS1115_COMP_2_GND);
//Serial.print(" ");
//voltage = readChannel(ADS1115_COMP_3_GND);
//Serial.println();
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
