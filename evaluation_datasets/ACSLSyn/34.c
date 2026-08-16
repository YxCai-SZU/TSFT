#include <stdbool.h>

/* First function: checks if a or b or sum is multiple of 3 */
/*@
    predicate is_multiple_of_3(integer x) = x % 3 == 0;
    logic integer safe_sum(integer a, integer b) = a + b;
*/

bool func(unsigned long a, unsigned long b)
{
    bool a_is_multiple_of_3;
    bool b_is_multiple_of_3;
    bool sum_is_multiple_of_3;
    unsigned long sum;

    //@ assert 1 <= a + b <= 200;
    sum = a + b;

    a_is_multiple_of_3 = (a % 3 == 0);
    b_is_multiple_of_3 = (b % 3 == 0);
    sum_is_multiple_of_3 = (sum % 3 == 0);

    return a_is_multiple_of_3 || b_is_multiple_of_3 || sum_is_multiple_of_3;
}

/* Second function: checks if a <= b after range shifting */
/*@
    predicate in_range(integer v) = -100 <= v <= 100;
    predicate temp_in_range(integer v) = -100 <= v <= 200;
*/

bool func2(int a, int b)
{
    bool is_leq = false;
    int temp_a = a;
    int temp_b = b;
    int i = 0;

    while (i < 100)
    {
        temp_a += 1;
        temp_b += 1;
        i += 1;
        //@ assert i <= 100;
    }

    //@ assert temp_a == a + 100;
    //@ assert temp_b == b + 100;
    //@ assert (temp_a <= temp_b) == (a <= b);

    if (temp_a <= temp_b)
    {
        is_leq = true;
    }

    return is_leq;
}

/* Synthesized function: temperature sensor validation scenario */
bool temperature_sensor_validation(unsigned long a, unsigned long b)
{
    bool condition1 = func(a, b);
    bool condition2 = func2((int)a, (int)b);
    bool result = condition1 && condition2;

    //@ assert result == ((a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) && (a <= b));

    return result;
}
