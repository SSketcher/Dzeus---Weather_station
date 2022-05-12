#include <Wire.h>
#include <DHT.h>
#include "DFRobot_VEML7700.h"
#include <ML8511.h>
#include <Adafruit_BMP085.h>


DHT th_sensor(5, DHT22);                //Temperature and humidity sensor
DFRobot_VEML7700 li_sensor;             //Light intensity sensor
#define ANALOGPIN     A0
ML8511 uv_sensor(ANALOGPIN);            //UV light sensor
Adafruit_BMP085 p_sensor;               //Presure  and internal temperature senor       






class sensors_unit
{
    public:

    private:

};

/*


//Initialization of all sensors
void init(){
    th_sensor.begin();
    p_sensor.begin();
    li_sensor.begin();
}

//
float measure(){

}

float get_th(){
    return th_sensor.readTemperature(), th_sensor.readHumidity();
}

float get_li(){
    float lux;
    li_sensor.getALSLux(lux);
    return lux;
}

float get_uv(){

}

float get_p(){
    return p_sensor.readPressure();
}

float get_internal_temperature(){
    return p_sensor.readTemperature();
}


*/