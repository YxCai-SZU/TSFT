#include <stdbool.h>

/*@
    predicate is_in_range(integer a) = -40 <= a <= 40;
    
    logic integer compute_result(integer a) = 
        a < -40 ? 0 : a + 40;
*/

int func_temp(int a)
{
    int result;
    
    //@ assert is_in_range(a);
    
    if (a < -40)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        //@ assert a >= -40;
        result = a + 40;
        //@ assert result == a + 40;
    }
    
    //@ assert result == (a < -40 ? 0 : a + 40);
    //@ assert result >= 0;
    
    return result;
}

/*@
    predicate is_even(integer n) = n % 2 == 0;
*/

bool func_check(unsigned int d, unsigned int t, unsigned int s)
{
    unsigned int distance = d;
    unsigned int time = t;
    unsigned int speed = s;
    bool result;

    //@ assert 1 <= time <= 10000;
    //@ assert 1 <= speed <= 10000;
    //@ assert time * speed <= 10000 * 10000;

    result = (time * speed >= distance);

    return result;
}

/*@ predicate is_valid_range(integer v) = 1 <= v && v <= 100; */

/*@ lemma square_bound: 
      \forall integer r; is_valid_range(r) ==> r * r <= 10000; */

int func_square(int r)
{
    //@ assert is_valid_range(r);
    //@ assert r * r <= 10000;
    return r * r;
}

bool input_int_tuple(int a, int b)
{
    //@ assert is_valid_range(a) && is_valid_range(b);
    return a > b;
}

bool input_char_tuple(int x, int y)
{
    //@ assert is_valid_range(x) && is_valid_range(y);
    return x == y;
}

bool input_int_list(int n, int m)
{
    //@ assert is_valid_range(n) && is_valid_range(m);
    return n >= m * 2 || n == m * 2 - 1;
}

/* Scenario: Temperature-based speed limit enforcement system
   Data flow: 
   1. Read temperature sensor value (a) and convert to adjusted value via func_temp
   2. Use adjusted value to compute speed threshold (r) via func_square
   3. Compare vehicle speed and time against threshold using func_check to determine if speed is safe
*/

bool speed_enforcement_system(int temp_sensor, unsigned int distance, unsigned int time, unsigned int speed)
{
    int adj_val;
    int threshold;
    bool is_safe;
    
    adj_val = func_temp(temp_sensor);
    
    threshold = func_square(adj_val);
    
    is_safe = func_check(distance, time, speed);
    
    //@ assert (is_safe == 1) ==> (time * speed >= distance);
    
    return is_safe;
}
