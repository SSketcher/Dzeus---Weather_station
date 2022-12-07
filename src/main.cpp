#include <Arduino.h>
#include <measurements.h>
#include <wifi_module.cpp>
#include <Wire.h>
#include "time.h"


#define LED_BUILTIN   2
Sensors_unit sensors;

void setup() {
  Serial.begin(9600);
  Serial.println("Dzeus Weather station");
  Serial.println("Sensors initialization...");
  sensors.init();
  Serial.println("WiFi initialization...");
  WIFI_init();
  Serial.println("Initialization of RTC...");


}

void loop() {
  sensors.update();
  delay(5000);
}


