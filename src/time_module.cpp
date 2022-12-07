#include "time.h"
#include "time_module.h"



//NTP server and time zone info
const char* NTP_SERVER = "ch.pool.ntp.org";
const char* TZ_INFO    = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";

tm timeinfo;
time_t now;

long unsigned lastNTPtime;
unsigned long lastEntryTime;



Time_unit::Time_unit()
{
}

void Time_unit::init(){
    configTime(0, 0, NTP_SERVER);
    setenv("TZ", TZ_INFO, 1);
    //tzset();
}

void Time_unit::checkTime(){

}

void Time_unit::update_time(){

}


