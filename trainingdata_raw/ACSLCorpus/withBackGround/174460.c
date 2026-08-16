#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer fixed_pi = 314159265;
    logic integer fixed_scale = 100000000;
    
    logic integer expected_circumference(integer r) = 
        (2 * fixed_pi * r) / fixed_scale;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_circumference(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t scale;
    int64_t circumference;
    int64_t temp;
    int64_t fraction;
    int64_t fractional_part;
    
    pi = 314159265;
    scale = 100000000;
    circumference = 0;
    temp = 2 * pi * r;
    
    //@ assert temp == 2 * fixed_pi * r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == fixed_pi;
        loop invariant scale == fixed_scale;
        loop invariant temp >= 0;
        loop invariant circumference * scale + temp == 2 * fixed_pi * r;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= scale)
    {
        temp -= scale;
        circumference += 1;
    }
    
    fraction = temp;
    fractional_part = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == fixed_pi;
        loop invariant scale == fixed_scale;
        loop invariant fraction >= 0;
        loop invariant fractional_part * scale + fraction == temp;
        loop assigns fraction, fractional_part;
        loop variant fraction;
    */
    while (fraction >= scale)
    {
        fraction -= scale;
        fractional_part += 1;
    }
    
    circumference += fractional_part;
    
    //@ assert circumference == expected_circumference(r);
    return circumference;
}
