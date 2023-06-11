#ifndef SENSORS_MODULE_H
#define SENSORS_MODULE_H

//Libraries
#include <SPI.h>
#include <Wire.h>
#include <DHT.h>
#include "struct.h"
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"
#include "Adafruit_VEML7700.h"
#include <Adafruit_BMP085.h>
#include <Adafruit_ADS1X15.h>

//Defining pins for analog sensors
#define DHT22_PIN 4

//Adjusting the sea level pressure for more accurate pressure readings
#define SEALEVELPRESSURE_HPA (1005.0)

class Sensors_unit
{
    public:
        Sensors_unit();   

        void init();

        void update(data *data_struct);


    private:
        //The Arduino Map function but for floats
        //From: http://forum.arduino.cc/index.php?topic=3922.0
        float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);

        //Takes an average of readings on a given analog signal
        //Returns the average
        int averageAnalogRead(int pinToRead);

};

#endif