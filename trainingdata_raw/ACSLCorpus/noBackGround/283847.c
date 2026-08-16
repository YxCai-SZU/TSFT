#include <stdint.h>

/*@
    requires ((a) == ((a) & 0xFFFFFFFF));
    ensures \result == ((a) ^ (0xFFFFFFFF));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert ((a) == ((a) & 0xFFFFFFFF));
    
    result = a ^ 0xFFFFFFFFU;
    
    //@ assert result == ((a) ^ (0xFFFFFFFF));
    
    return result;
}
