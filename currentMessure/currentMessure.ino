#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
uint32_t value;

void setup()
{
 uint32_t currentFrequency;

 Serial.begin(9600);
 Serial.println("Hello!");

 Serial.println("Measuring voltage and current with INA219 ...");
 ina219.begin();
 pinMode(2,OUTPUT);
 value=HIGH;
}

void loop()
{
  value=not value;
 digitalWrite(2,value);
 float shuntvoltage = 0;
 float busvoltage = 0;
 float current_mA = 0;
 float loadvoltage = 0;
 float power = 0;

 shuntvoltage = ina219.getShuntVoltage_mV();
 busvoltage = ina219.getBusVoltage_V();
 current_mA = ina219.getCurrent_mA();
 loadvoltage = busvoltage + (shuntvoltage / 1000);
 power = current_mA * loadvoltage;

 Serial.print("Bus Voltage: "); Serial.print(busvoltage); Serial.println(" V");
 Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
 Serial.print("Load Voltage: "); Serial.print(loadvoltage); Serial.println(" V");
 Serial.print("Current: "); Serial.print(current_mA); Serial.println(" mA");
 Serial.print("Power: "); Serial.print(power); Serial.println(" mW");
 Serial.println("");

delay(1000);
}
