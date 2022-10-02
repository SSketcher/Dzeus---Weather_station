#include "measurements.h"
#include <SPI.h>
#include <Wire.h>
#include <DHT.h>
#include "DFRobot_VEML7700.h"
#include <ML8511.h>
#include <Adafruit_BMP085.h>


#define I2C_SDA 33
#define I2C_SCL 32
#define DHT22_PIN 35
#define UV_PIN  34


DHT th_sensor(DHT22_PIN, DHT22);                //Temperature and humidity sensor
DFRobot_VEML7700 li_sensor;             //Light intensity sensor
ML8511 uv_sensor(UV_PIN);            //UV light sensor
Adafruit_BMP085 p_sensor;               //Presure  and internal temperature senor       




Sensors_unit::Sensors_unit()		//constructor
{
}

void Sensors_unit::init(){
    //Initialization of all sensors
    th_sensor.begin();
    Serial.print("DHT22 Temperature and humidity sensor -- Initalized");

    p_sensor.begin();
    Serial.print("BMP180 Presure  and internal temperature senor  -- Initalized");

    li_sensor.begin();
    Serial.print("VEML7700 Light intensity sensor -- Initalized");

}

void Sensors_unit::update(){
    Serial.println("Updateing messured valeus...");
    
}

void Sensors_unit::get_th(){
    temperature, humidity = th_sensor.readTemperature(), th_sensor.readHumidity();
}

void Sensors_unit::get_li(){
    li_sensor.getALSLux(light_intensity);
}

void Sensors_unit::get_uv(){
    uv_intensity = uv_sensor.getUV();
}

void Sensors_unit::get_p(){
    pressure = p_sensor.readPressure();
}

float Sensors_unit::get_internal_temperature(){
    return p_sensor.readTemperature();
}
