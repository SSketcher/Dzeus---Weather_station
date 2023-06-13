#include <Arduino.h>
#include <Wire.h>

//Code is crashing without this two lines, but most likely those are unnecessary
#include <WiFi.h>
#include <Arduino_ESP32_OTA.h>

#include "struct.h"
#include "sensors_module.h"
#include "thingProperties.h"

Sensors_unit sensors;
data measurements;

void setup() {
  Serial.begin(9600);
  delay(1500); 
  Serial.println("Dzeus Weather station\n");
  Serial.println("Sensors initialization...");
  sensors.init();
  Serial.println("Arduino IoT Cloud initialization...");
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  //Updating Arduino IoT Cloud
  ArduinoCloud.update();


  //Updating sensors valeus
  sensors.update(&measurements);

  humidity = measurements.humidity;
  light_intensity = measurements.light_intensity;
  pressure = measurements.pressure;
  temperature = measurements.temperature;
  uv_intensity = measurements.uv_intensity;
  delay(1000);
}


