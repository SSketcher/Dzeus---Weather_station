#include "wifi_module.h"

//The SSID and password of the network
const char* ssid = "Ett-m166";
const char* password = "123454321";


//Wifi initialization function
void WIFI_ini(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(1000);
    }
    Serial.print("Connect...  ");
    Serial.println(WiFi.localIP());
}