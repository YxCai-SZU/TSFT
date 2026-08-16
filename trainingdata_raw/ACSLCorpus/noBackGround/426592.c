#include <stdint.h>

/*@
    requires (0 <= (a) < 0x80000000);
    ensures \result == ((a) | (0x80000000));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert (0 <= (a) < 0x80000000);
    
    uint32_t result;
    result = a | 0x80000000;
    
    //@ assert result == ((a) | (0x80000000));
    return result;
}
