#include <stdint.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    // Variable declarations at top
    uint32_t result;
    
    //@ assert (1 <= (x) <= 100);
    //@ assert 1 <= 100;
    //@ assert 1 * 1 * 1 <= 100 * 100 * 100;
    
    //@ assert x * x <= 10000;
    //@ assert x * x * x <= 1000000;
    
    result = x * x * x;
    
    //@ assert result == ((x) * (x) * (x));
    
    return result;
}
