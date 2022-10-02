#include <Arduino.h>
#include <measurements.h>
#include <time_module.cpp>
#include <Wire.h>


#define LED_BUILTIN   2
Sensors_unit sensors;

void setup() {
  Serial.begin(9600);
  Serial.println("Dzeus Weather station");
  Serial.println("Sensors initialization...");
  sensors.init();
  //Serial.println("Initialization of RTC...");
  //RTC_init();


}

void loop() {
  sensors.update();
  delay(5000);
}


