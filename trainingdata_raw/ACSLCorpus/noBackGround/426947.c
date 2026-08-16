#include <stdint.h>

/*@
    requires (1 <= (x) <= 23);
    ensures \result == (48 - (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert (1 <= (x) <= 23);
    //@ assert 0 <= 48 - x <= 47;
    
    result = 48 - x;
    
    //@ assert result == (48 - (x));
    return result;
}
