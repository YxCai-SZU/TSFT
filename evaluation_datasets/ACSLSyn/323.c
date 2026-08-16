/* Scenario: Temperature and humidity sensor data validation and trend analysis
   A sensor array produces readings in range [0,100] and we need to:
   1. Check if temperature readings are in normal range [30,40]
   2. Verify humidity readings satisfy a distribution property
   3. Check if there's a trend in the combined readings */

/*@
    predicate in_range(integer x) = 30 <= x && x <= 40;
 */

int func(unsigned int x)
{
    unsigned int a;
    unsigned int b;
    int result;

    a = 30;
    b = 40;

    if (x < a || x > b)
    {
        result = 0;
        //@ assert !in_range(x);
        return result;
    }
    else
    {
        //@ assert in_range(x);
        result = 1;
        return result;
    }
}

/*@
predicate nonnegative(integer x) = 0 <= x <= 1000;

lemma distributive_property:
    \forall integer x, y, z;
    nonnegative(x) && nonnegative(y) && nonnegative(z) ==>
    x * (y + z) == x * y + x * z;
*/

int lemma_mul_is_distributive_add(int x, int y, int z)
{
    //@ assert 0 <= x && x <= 1000;
    //@ assert 0 <= y && y <= 1000;
    //@ assert 0 <= z && z <= 1000;
    //@ assert x * (y + z) == x * y + x * z;
    return x * (y + z);
}

#include <stdbool.h>

/*@
    predicate increasing(integer a, integer b, integer c) = a < b && b < c;
    predicate decreasing(integer a, integer b, integer c) = a > b && b > c;
    predicate has_trend(integer a, integer b, integer c) = 
        increasing(a, b, c) || decreasing(a, b, c);
*/

bool func_trend(const int *v)
{
    int a;
    int b;
    int c;
    bool inc;
    bool dec;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];
    
    inc = a < b && b < c;
    dec = a > b && b > c;
    
    //@ assert inc == true <==> increasing(a, b, c);
    //@ assert dec == true <==> decreasing(a, b, c);
    
    result = inc || dec;
    
    //@ assert result == true <==> has_trend(a, b, c);
    
    return result;
}

/* Synthesized function: validate_sensor_data
   Takes three sensor readings (temperature, humidity_1, humidity_2) and checks:
   - Temperature is in normal range [30,40]
   - Humidity values satisfy distribution property via lemma
   - There's a trend in the combined readings
   Returns 1 if all checks pass, 0 otherwise */

int validate_sensor_data(unsigned int temperature, int humidity1, int humidity2, const int *sensor_trend)
{
    int temp_check;
    int dist_check;
    bool trend_check;
    int result;
    
    temp_check = func(temperature);
    
    dist_check = lemma_mul_is_distributive_add(5, humidity1, humidity2);
    
    trend_check = func_trend(sensor_trend);
    
    if (temp_check == 1 && dist_check == (5 * humidity1 + 5 * humidity2) && trend_check == true)
    {
        //@ assert in_range(temperature) && (humidity1 + humidity2) * 5 == 5 * humidity1 + 5 * humidity2 && has_trend(sensor_trend[0], sensor_trend[1], sensor_trend[2]);
        result = 1;
    }
    else
    {
        result = 0;
    }
    
    //@ assert (result == 1) <==> (in_range(temperature) && (humidity1 + humidity2) * 5 == 5 * humidity1 + 5 * humidity2 && has_trend(sensor_trend[0], sensor_trend[1], sensor_trend[2]));
    return result;
}
