#include <stdint.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((x) / 4 + 1);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    
    //@ assert x / 4 <= 25;
    //@ assert x / 4 + 1 <= 26;
    
    result = x / 4 + 1;
    
    //@ assert result == ((x) / 4 + 1);
    return result;
}
