#ifndef TIME_MODULE_H
#define TIME_MODULE_H

#include "time.h"
#include "WiFi.h"

bool rtc_init();
bool get_uptime(int sec);
void checkTime();

extern long unsigned lastNTPtime;
extern unsigned long lastEntryTime;

#endif