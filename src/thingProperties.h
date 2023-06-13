#ifndef THINGPROPERTIES_h
#define THINGPROPERTIES_h

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <credentials.h>

float humidity;
float light_intensity;
float pressure;
float temperature;
float uv_intensity;

void initProperties(){
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