#include <stdint.h>

/*@
    requires ((a) > 0) && ((b) > 0) && ((c) > 0);
    requires ((a) + (b) + (c) < 0x100000000);
    ensures \result == ((a) + (b) + (c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert a < 0x100000000;
    //@ assert b < 0x100000000;
    //@ assert c < 0x100000000;
    //@ assert a + b < 0x100000000;
    //@ assert a + b + c < 0x100000000;
    
    result = a + b + c;
    
    //@ assert result == ((a) + (b) + (c));
    
    return result;
}
