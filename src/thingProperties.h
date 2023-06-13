#ifndef THINGPROPERTIES_h
#define THINGPROPERTIES_h

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <credentials.h>
#include "struct.h"


void initProperties(data *data_struct){

float humidity = data_struct->humidity;
float light_intensity = data_struct->light_intensity;
float pressure = data_struct->pressure;
float temperature = data_struct->temperature;
float uv_intensity = data_struct->uv_intensity;


  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(humidity, READ, 60 * SECONDS, NULL);
  ArduinoCloud.addProperty(light_intensity, READ, 60 * SECONDS, NULL);
  ArduinoCloud.addProperty(pressure, READ, 60 * SECONDS, NULL);
  ArduinoCloud.addProperty(temperature, READ, 60 * SECONDS, NULL);
  ArduinoCloud.addProperty(uv_intensity, READ, 60 * SECONDS, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(ssid, password);

#endif