#ifndef THINGPROPERTIES_h
#define THINGPROPERTIES_h

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <credentials.h>
#include "struct.h"

void initProperties(data *data_struct){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(data_struct->humidity, READ, 60 * SECONDS, NULL);
  ArduinoCloud.addProperty(data_struct->light_intensity, READ, 60 * SECONDS, NULL);
  ArduinoCloud.addProperty(data_struct->pressure, READ, 60 * SECONDS, NULL);
  ArduinoCloud.addProperty(data_struct->temperature, READ, 60 * SECONDS, NULL);
  ArduinoCloud.addProperty(data_struct->uv_intensity, READ, 60 * SECONDS, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(ssid, password);

#endif