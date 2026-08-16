#include <stdint.h>

/*@
    requires ((x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    // Variable declarations at top of scope
    uint64_t result;

    //@ assert x <= 1;
    
    result = 1 - x;
    
    //@ assert result == (1 - (x));
    
    return result;
}
