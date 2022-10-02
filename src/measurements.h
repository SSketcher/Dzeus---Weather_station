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