#include <stdbool.h>

typedef enum {
    Sunny,
    Rainy,
    Cloudy
} WeatherTag;

typedef struct {
    WeatherTag tag;
    union {
        int temperature;
        int precipitation;
        int cloud_cover;
    } data;
} Weather;

/*@
    requires (forecast.tag == Sunny && forecast.data.temperature > 30) ||
             (forecast.tag == Rainy && forecast.data.precipitation > 50);
    ensures \result == true;
    assigns \nothing;
*/
bool check_weather_forecast(Weather forecast)
{
    bool result;
    //@ assert forecast.tag == Sunny || forecast.tag == Rainy;
    
    if (forecast.tag == Sunny && forecast.data.temperature > 30) {
        //@ assert ((forecast.data.temperature) > 30);
        result = true;
    } else if (forecast.tag == Rainy && forecast.data.precipitation > 50) {
        //@ assert ((forecast.data.precipitation) > 50);
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

/*@
    requires forecast.tag == Cloudy && forecast.data.cloud_cover > 50;
    ensures \result == true;
    assigns \nothing;
*/
bool check_cloud_cover(Weather forecast)
{
    bool result;
    
    if (forecast.tag == Cloudy && forecast.data.cloud_cover > 50) {
        //@ assert ((forecast.data.cloud_cover) > 50);
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

int main()
{
    return 0;
}
