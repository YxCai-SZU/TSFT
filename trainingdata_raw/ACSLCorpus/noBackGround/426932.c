#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == (800 * (n) - 200 * (((n) / 15)));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    int32_t quotient;
    int32_t temp_n;
    
    x = 800;
    y = 200;
    quotient = 0;
    temp_n = (int32_t)n;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp_n;
        loop invariant temp_n == (int32_t)n - quotient * 15;
        loop assigns quotient, temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n -= 15;
        quotient += 1;
    }
    
    //@ assert quotient == ((n) / 15);
    return x * (int32_t)n - y * quotient;
}
