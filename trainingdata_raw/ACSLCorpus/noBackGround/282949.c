#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 10 && 0 <= (y) && (y) <= 10);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at top of scope
    uint32_t res;
    
    //@ assert (0 <= (x) && (x) <= 10 && 0 <= (y) && (y) <= 10);
    //@ assert ((x) * (y)) <= 100;
    
    res = x * y;
    
    //@ assert res == ((x) * (y));
    return res;
}
