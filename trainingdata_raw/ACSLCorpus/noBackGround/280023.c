#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((((n)) * 800) - ((((n)) / 15) * 200));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    int32_t x;
    int32_t y;
    int32_t ans;
    uint32_t quotient = 0;
    uint32_t remainder = n;
    
    // Precondition ensures no overflow
    //@ assert (1 <= (n) && (n) <= 100);
    
    // Calculate x = 800 * n
    x = 800 * (int32_t)n;
    //@ assert x == ((n) * 800);
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= remainder && remainder <= n;
        loop invariant remainder + 15*quotient == n;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15)
    {
        remainder -= 15;
        quotient += 1;
    }
    
    // Final quotient verification
    //@ assert quotient == n / 15;
    
    y = (int32_t)quotient * 200;
    //@ assert y == (((n) / 15) * 200);
    
    ans = x - y;
    //@ assert ans == ((((n)) * 800) - ((((n)) / 15) * 200));
    
    return ans;
}
