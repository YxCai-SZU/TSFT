#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((800 * ((n))) - (200 * (((n)) / 15)));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    int32_t x;
    int32_t y;
    int32_t res;

    //@ assert (1 <= (n) && (n) <= 100);
    
    x = 800 * (int32_t)n;
    //@ assert x == (800 * (n));
    
    y = 200 * (int32_t)(n / 15);
    //@ assert y == (200 * ((n) / 15));
    
    res = x - y;
    //@ assert res == ((800 * ((n))) - (200 * (((n)) / 15)));
    
    return res;
}
