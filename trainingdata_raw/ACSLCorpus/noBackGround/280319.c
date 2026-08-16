#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (31415)* (r)) / (10000));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t scale;
    int64_t circumference;
    int64_t temp;
    
    pi_approx = 31415;
    scale = 10000;
    circumference = 0;
    temp = 2 * pi_approx * r;
    
    //@ assert 0 < 2 * pi_approx * r <= 2 * 31415 * 100;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant temp >= 0;
        loop invariant temp <= 2 * pi_approx * r;
        loop invariant circumference * scale + temp == 2 * pi_approx * r;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        circumference = circumference + 1;
        temp = temp - scale;
    }
    
    return circumference;
}
