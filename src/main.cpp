#include <Arduino.h>
#include <Wire.h>
#include "sensors_module.h"
#include "wifi_module.h"
#include <time_module.h>



#define LED_BUILTIN   2
Sensors_unit sensors;

void setup() {
  Serial.begin(9600);
  Serial.println("Dzeus Weather station");
  Serial.println("WiFi initialization...");
  WIFI_ini();
  Serial.println("Initialization of internal RTC...");
  rtc_init();
  Serial.println("Sensors initialization...");
  sensors.init();
}

void loop() {
  sensors.update();
  delay(5000);
}


