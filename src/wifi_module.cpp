#include <WiFi.h>


//The SSID and password of the network
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";


//Wifi initialization function
void WIFI_init(){
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