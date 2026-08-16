#include <stdint.h>

/*@
    requires ((x) <= 0x7FFFFFFF);
    ensures \result == ((x) + 1);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    
    //@ assert x < 0xFFFFFFFF;
    
    result = x + 1;
    
    //@ assert result == ((x) + 1);
    
    return result;
}
