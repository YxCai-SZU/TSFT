#include <stdint.h>

/*@
    requires \true;
    ensures ((\result) == ((x) ^ 0x0000ffff));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    
    //@ assert (x ^ 0x0000ffff) == (x ^ 0x0000ffff);
    
    result = x ^ 0x0000ffff;
    
    //@ assert ((result) == ((x) ^ 0x0000ffff));
    
    return result;
}
