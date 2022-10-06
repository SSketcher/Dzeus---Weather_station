class Time
{
    public:
        Time();

        void init();

        void checkTime();

        void update_time();


    private:

        void NTP_init();

        void RTC_init();
        
};