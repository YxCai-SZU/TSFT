#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * 3141592 * (r) / 1000000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t two;
    int64_t scale_factor;
    int64_t circumference;
    int64_t temp;
    
    pi = 3141592;
    two = 2;
    scale_factor = 1000000;
    
    circumference = 0;
    temp = two * pi * r;
    
    /*@
        loop invariant ((1 <= ((r)) && ((r)) <= 100) &&
        (pi) == 3141592 &&
        (two) == 2 &&
        (scale_factor) == 1000000 &&
        (temp) >= 0 &&
        (circumference) * (scale_factor) + (temp) == (two) * (pi) * (r));
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale_factor)
    {
        //@ assert temp >= scale_factor;
        circumference = circumference + 1;
        temp = temp - scale_factor;
    }
    
    //@ assert circumference == (2 * 3141592 * (r) / 1000000);
    return circumference;
}
