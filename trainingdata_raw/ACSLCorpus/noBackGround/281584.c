#include <stdint.h>

/*@
    requires (0 <= (x) <= 23) && (0 <= (y) <= 23);
    ensures \result == ((x + y) % 24);
    ensures (0 <= (\result) <= 23);
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t sum;
    uint32_t result;
    
    //@ assert (0 <= (x) <= 23);
    //@ assert (0 <= (y) <= 23);
    
    //@ assert x + y <= 46;
    sum = x + y;
    
    //@ assert sum % 24 <= 23;
    result = sum % 24;
    
    //@ assert result == (x + y) % 24;
    //@ assert (0 <= (result) <= 23);
    
    return result;
}
