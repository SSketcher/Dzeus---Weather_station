#include "time_module.h"
#include <Time.h>
//#include <DS1307RTC.h>


//NTP server and time zone info
const char* NTP_SERVER = "ch.pool.ntp.org";
const char* TZ_INFO    = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";

tm timeinfo;
time_t now;

long unsigned lastNTPtime;
unsigned long lastEntryTime;

Time::Time()
{
}

void Time::init(){

}

void Time::checkTime(){

}

void Time::update_time(){

}

void Time::NTP_init(){

}

void Time::RTC_init(){

}
