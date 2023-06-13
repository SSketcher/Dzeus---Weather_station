#include "sensors_module.h"

//I2C status status to avoid crash at update
bool status_BMP388 = true;
bool status_VEML7700 = true;
bool status_ADS = true;

DHT th_sensor(DHT22_PIN, DHT22);                //Temperature and humidity sensor
Adafruit_VEML7700 li_sensor = Adafruit_VEML7700();             //Light intensity sensor
Adafruit_BMP3XX p_sensor;               //Presure  and internal temperature senor
Adafruit_ADS1115 ads_adc;               //Analog to digital converter 


Sensors_unit::Sensors_unit()		//constructor
{
}

void Sensors_unit::init(){
    //Initialization of all sensors
    th_sensor.begin();
    Serial.println("DHT22 Temperature and humidity sensor -- Initalized");

    if(!ads_adc.begin()){
        Serial.println("ADS1115 Analog to digital converter   -- Initalization Failed");
        status_ADS = false;
    }
    else{
        Serial.println("ADS1115 Analog to digital converter  -- Initalized");
    }

    if(!p_sensor.begin_I2C()){
        Serial.println("BMP388 Presure  and internal temperature senor  -- Initalization Failed");
        status_BMP388 = false;
    }
    else{
        Serial.println("BMP180 Presure  and internal temperature senor -- Initalized");

        // Set up oversampling and filter initialization
        p_sensor.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
        p_sensor.setPressureOversampling(BMP3_OVERSAMPLING_4X);
        p_sensor.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
        p_sensor.setOutputDataRate(BMP3_ODR_50_HZ);
    }


    if(!li_sensor.begin()){
        Serial.println("VEML7700 Light intensity sensor -- Initalization Failed");
        status_VEML7700 = false;
    }
    else{
        Serial.println("VEML7700 Light intensity sensor -- Initalized");
    }
    Serial.print("\n");    
}



void Sensors_unit::update(data *data_struct){
    Serial.println("\nUpdating sensors readings...");

    //Updating temperature and humidity from DHT22
    data_struct->temperature = th_sensor.readTemperature();
    data_struct->humidity = th_sensor.readHumidity();
    Serial.printf("Air tempreture: %f °C\n", data_struct->temperature);
    Serial.printf("Air humidity: %f %\n", data_struct->humidity);


    //Updating light intensity from VEML7700
    if(status_VEML7700){
        data_struct->light_intensity = li_sensor.readLux();
        Serial.printf("Light intesity: %f lx\n", data_struct->light_intensity);
    }

    //Updating UV intensity from ML8511 with ADS1115
    if(status_ADS){
        int16_t adc0;
        float outputVoltage = 0.0;

        adc0 = ads_adc.readADC_SingleEnded(0);
        outputVoltage  = (adc0 * 0.1875)/1000;
        data_struct->uv_intensity = mapfloat(outputVoltage, 0.99, 2.9, 0.0, 15.0);
        Serial.printf("UV_Intensity: %f mW/cm^2\n", data_struct->uv_intensity);
    }
    
    //Updating presure from BMP388
    if(status_BMP388){
        data_struct->pressure = p_sensor.readPressure()/100.0;         //Dividing by 100 to change Pa to hPa
        Serial.printf("Air pressure: %f hPa\n", data_struct->pressure);
    }

}


float Sensors_unit::mapfloat(float x, float in_min, float in_max, float out_min, float out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int Sensors_unit::averageAnalogRead(int pinToRead){
    byte numberOfReadings = 8;      //Averages over 8 readings
    unsigned int runningValue = 0;

    for(int x = 0 ; x < numberOfReadings ; x++)
        runningValue += analogRead(pinToRead);
    runningValue /= numberOfReadings;

    return(runningValue);
}
