#include <Arduino.h>
#include <Wire.h>
#include "struct.h"
#include "sensors_module.h"
#include "thingProperties.h"

Sensors_unit sensors;
data measurements;

void setup() {
  Serial.begin(9600);
  Serial.println("Dzeus Weather station\n");
  Serial.println("Sensors initialization...");
  sensors.init();
  Serial.println("Arduino IoT Cloud initialization...");
  initProperties(&measurements);
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
}

void loop() {
  //Updating sensors valeus
  sensors.update(&measurements);

  //Updating Arduino IoT Cloud
  ArduinoCloud.update();
}


