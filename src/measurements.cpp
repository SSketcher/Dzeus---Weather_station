#include "measurements.h"
#include <SPI.h>
#include <Wire.h>
#include <DHT.h>
#include "Adafruit_VEML7700.h"
#include <ML8511.h>
#include <Adafruit_BMP085.h>


//Defining pins for analog sensors
#define DHT22_PIN 4
#define UV_PIN  32

//I2C status status to avoid crash at update
bool status_BMP180 = true;
bool status_VEML7700 = true;

DHT th_sensor(DHT22_PIN, DHT22);                //Temperature and humidity sensor
Adafruit_VEML7700 li_sensor = Adafruit_VEML7700();             //Light intensity sensor
ML8511 uv_sensor(UV_PIN);            //UV light sensor
Adafruit_BMP085 p_sensor;               //Presure  and internal temperature senor       


Sensors_unit::Sensors_unit()		//constructor
{
}

void Sensors_unit::init(){
    //Initialization of all sensors
    th_sensor.begin();
    Serial.println("DHT22 Temperature and humidity sensor -- Initalized");

    if(!p_sensor.begin()){
        Serial.println("BMP180 Presure  and internal temperature senor  -- Initalization Failed");
        status_BMP180 = false;
    }
    else{
        Serial.println("BMP180 Presure  and internal temperature senor -- Initalized");
    }


    if(!li_sensor.begin()){
        Serial.println("VEML7700 Light intensity sensor -- Initalization Failed");
        status_VEML7700 = false;
    }
    else{
        Serial.println("VEML7700 Light intensity sensor -- Initalized");
    }
        

}

void Sensors_unit::update(){
    Serial.println("\nUpdating sensors readings...");
    get_li();
    get_uv();
    get_p();
    get_th();
}

void Sensors_unit::get_th(){
    temperature = th_sensor.readTemperature();
    humidity = th_sensor.readHumidity();
    //Printing out resoult
    Serial.print("Air tempreture: ");
    Serial.print(String(temperature));
    Serial.print(" °C\n");
    Serial.print("Air humidity: ");
    Serial.print(String(humidity));
    Serial.print(" %\n");
}

void Sensors_unit::get_li(){
    if(status_VEML7700)
        light_intensity = li_sensor.readLux();
    //Printing out resoult
    Serial.print("Light intesity: ");
    Serial.print(String(light_intensity));
    Serial.print(" lx\n");
}

void Sensors_unit::get_uv(){
    uv_intensity = uv_sensor.getUV();
    //Printing out resoult
    Serial.print("UV intenstiy: ");
    Serial.print(String(uv_intensity));
    Serial.print(" mW/cm2\n");
}

void Sensors_unit::get_p(){
    if(status_BMP180)
        pressure = p_sensor.readPressure()/100;         //Dividing by 100 to change Pa to hPa
    //Printing out resoult
    Serial.print("Air pressure: ");
    Serial.print(String(pressure));
    Serial.print(" hPa\n");
}

float Sensors_unit::get_internal_temperature(){
    if(status_BMP180)
        return p_sensor.readTemperature();
    else
        return 0;
}
