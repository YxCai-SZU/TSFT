#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((314 * ((r) * 2)) / 100);
    assigns \nothing;
*/
int32_t func(uint32_t r)
{
    // Variable declarations at scope top
    int32_t pi;
    int32_t circumference;
    int32_t result;
    int32_t temp;
    
    pi = 314;
    circumference = ((int32_t)r * 2) * pi;
    
    result = 0;
    temp = circumference;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314;
        loop invariant circumference == ((int32_t)r * 2) * pi;
        loop invariant result * 100 + temp == circumference;
        loop invariant temp >= 0;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= 100)
    {
        //@ assert temp >= 100;
        temp -= 100;
        result += 1;
    }
    
    //@ assert result == ((314 * ((r) * 2)) / 100);
    return result;
}
