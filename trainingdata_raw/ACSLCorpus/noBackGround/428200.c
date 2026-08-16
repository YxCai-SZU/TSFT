#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * 314159 * (r)) / 100000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations
    int64_t pi_approx;
    int64_t scale;
    int64_t scaled_r;
    int64_t circumference;
    int64_t temp;
    int64_t count;
    
    // Initialization
    pi_approx = 314159;
    scale = 100000;
    scaled_r = r * scale;
    circumference = 0;
    temp = 2 * pi_approx * r;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314159;
        loop invariant scale == 100000;
        loop invariant scaled_r == r * scale;
        loop invariant temp >= 0;
        loop invariant count * scale + temp == 2 * pi_approx * r;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        temp -= scale;
        count += 1;
    }
    
    circumference = count;
    
    //@ assert circumference == ((2 * 314159 * (r)) / 100000);
    return circumference;
}
