#include <Arduino.h>
#include <Wire.h>
#include "wifi_module.h"
#include "time_module.h"
#include "struct.h"
#include "sensors_module.h"

Sensors_unit sensors;

void setup() {
  Serial.begin(9600);
  Serial.println("Dzeus Weather station\n");
  Serial.println("WiFi initialization...");
  WIFI_ini();
  Serial.println("Initialization of internal RTC...");
  rtc_init();
  Serial.println("Sensors initialization...");
  sensors.init();
}

void loop() {
  data measurements;
  sensors.update(&measurements);
  checkTime();
  measurements.time = get_POSIX();
  delay(10000);
}


