#include "time_module.h"

//NTP server and time zone info
const char* NTP_SERVER = "pl.pool.ntp.org";         //NTP server for Poland
const char* TZ_INFO    = "CET+1CEST+2,M3.5.0/02:00:00,M10.5.0/03:00:00";        //Time zone of Poland

tm timeinfo;
time_t now;

bool rtc_init(){
    if(WiFi.status() == WL_CONNECTED){
        configTime(0, 0, NTP_SERVER);
        setenv("TZ", TZ_INFO, 1);

        if(get_uptime(30)){
            Serial.println("RTC initialized...");
            return 1;
        }else{
            Serial.println("Can not initialized RTC");
            Serial.println("NTP server does not respond...");
            return 0;
        }
    }else{
        Serial.println("Can not initialized RTC");
        Serial.println("WiFi is not connected...");
        return 0;
    }
}

bool get_uptime(int sec){
    {
    uint32_t start = millis();
    do {
        Serial.println("Conecting to NTP server...");
        time(&now);
        localtime_r(&now, &timeinfo);
        Serial.print(".");
        delay(10);
    } while (((millis() - start) <= (1000 * sec)) && (timeinfo.tm_year < (2016 - 1900)));

    if (timeinfo.tm_year <= (2016 - 1900)){ //The NTP call was not successful
        return false;  
    }else{
        Serial.print("Currant POSIX time: ");  
        Serial.println(now);
    }
  }
  return true;
}

void checkTime(){
    char time_output[30];
    strftime(time_output, 30, "%a  %d-%m-%y %T", localtime(&now));
    Serial.println(time_output);
    Serial.println();
}