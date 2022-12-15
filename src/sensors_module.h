#ifndef SENSORS_MODULE_H
#define SENSORS_MODULE_H

#include <SPI.h>
#include <Wire.h>
#include <DHT.h>
#include "Adafruit_VEML7700.h"
#include <ML8511.h>
#include <Adafruit_BMP085.h>

//Defining pins for analog sensors
#define DHT22_PIN 4
#define UV_PIN  32

class Sensors_unit
{
    public:
        Sensors_unit();

        float get_internal_temperature();

        void init();

        void update();


    private:
        float temperature = 0, humidity = 0, pressure = 0, light_intensity = 0, uv_intensity = 0;

        void get_th();

        void get_li();

        void get_uv();

        void get_p();

};

#endif