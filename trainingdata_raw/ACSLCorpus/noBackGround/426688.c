#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == (800 * (n) - 200 * (((n)) / 15));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    uint32_t quotient = 0;
    uint32_t temp_n = n;
    
    /*@
        loop invariant 0 <= quotient <= ((n) / 15);
        loop invariant temp_n + 15 * quotient == n;
        loop invariant 0 <= temp_n <= n;
        loop assigns quotient, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        quotient += 1;
    }
    
    int32_t ans = 800 * (int32_t)n - 200 * (int32_t)quotient;
    
    //@ assert ans == (800 * (n) - 200 * (((n)) / 15));
    
    return ans;
}
