#include <stdint.h>

/*@
    requires ((a) >= 0) && ((b) >= 0);
    requires ((a) + (b) <= 4294967295);
    ensures \result == (a | b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    
    //@ assert a >= 0 && b >= 0;
    //@ assert a + b <= 4294967295;
    //@ assert (a | b) == (a | b);
    
    result = a | b;
    
    //@ assert result == (a | b);
    return result;
}
