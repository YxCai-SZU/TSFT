#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 10);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert (1 <= (x) && (x) <= 10);
    //@ assert x * x <= 100;
    //@ assert x * x * x <= 1000;
    
    result = x * x * x;
    
    //@ assert result == ((x) * (x) * (x));
    return result;
}
