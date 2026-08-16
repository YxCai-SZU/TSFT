#include <stdint.h>

/*@
    requires ((x) <= 10 && (y) <= 10 && (z) <= 10);
    ensures \result == ((((x)) * ((y))) + (z));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert x <= 10;
    //@ assert y <= 10;
    //@ assert z <= 10;
    
    //@ assert ((x) * (y)) <= 100;
    
    result = (x * y) + z;
    
    //@ assert result == ((((x)) * ((y))) + (z));
    
    return result;
}
