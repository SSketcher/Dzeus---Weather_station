#ifndef STRUCT_H
#define STRUCT_H

#include "time.h"

//Structure containing sensors data and time of readings
//temperature (float) - temperature in °C from DHT22
//humidity  (float) - humidity in % from DHT22
//light_intensity (float) - light intensity in lx feom VEML7700
//uv_intensity (float) - UV intensity in mW/cm^2 from ?
//time (time_t) - reading time as a POSIX time
struct data
{
    float temperature = 0;
    float humidity = 0;
    float pressure = 0;
    float light_intensity = 0;
    float uv_intensity = 0;
    time_t time;
};

#endif