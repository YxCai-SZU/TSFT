#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 9);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert 1 <= x && x <= 9;
    //@ assert x * x <= 81;
    //@ assert x * x * x <= 729;
    
    result = x * x * x;
    return result;
}
