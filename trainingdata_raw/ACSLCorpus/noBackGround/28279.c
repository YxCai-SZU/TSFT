#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 314 / 100);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi = 314;
    int64_t circumference = 0;
    int64_t temp = 2 * r * pi;
    int64_t divisor = 100;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert pi == 314;
    //@ assert temp == 2 * r * 314;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant pi == 314;
        loop invariant circumference * 100 + temp == 2 * r * 314;
        loop invariant circumference * 100 + temp >= 0;
        loop invariant circumference * 100 <= 2 * r * 314;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference * 100 + temp == 2 * r * 314;
    //@ assert 2 * r * 314 <= 2 * 100 * 314;
    //@ assert 0 <= 2 * r * 314;
    
    return circumference;
}
