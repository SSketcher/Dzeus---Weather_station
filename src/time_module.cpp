#include <Time.h>
//#include <DS1307RTC.h>

const char* NTP_SERVER = "ch.pool.ntp.org";
const char* TZ_INFO    = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";

tm timeinfo;
time_t now;

long unsigned lastNTPtime;
unsigned long lastEntryTime;

void NTP_init(){

}

void RTC_init(){

}

void Time_chceck(){
    
}