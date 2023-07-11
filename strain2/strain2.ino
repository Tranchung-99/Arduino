#include<ADS1115_WE.h> 
#include<Wire.h>
#define I2C_ADDRESS 0x48
const int taraPin = 7;
const float milliVoltToWeight = 12.15;
ADS1115_WE adc = ADS1115_WE(I2C_ADDRESS);
void setup() {
  Wire.begin();
  Serial.begin(9600);
  adc.setVoltageRange_mV(ADS1115_RANGE_6144); 
  adc.setMeasureMode(ADS1115_CONTINUOUS); 
}
void loop() {
  float weight = 0.0;
  static float tara = 0.0;
  float voltage = adc.getResult_mV();
  if(digitalRead(taraPin)){
    delay(2000);
    voltage = adc.getResult_mV();
    tara = voltage;
  }
  weight = (voltage - tara)/milliVoltToWeight; 
  voltage = adc.getResult_mV();
  Serial.print("Voltage 0 vs GND [mV]: ");
  Serial.println(voltage);
  Serial.print("Weight [g]: ");
  Serial.println(weight);
  delay(500);
}
