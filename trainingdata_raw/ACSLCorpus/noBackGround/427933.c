#include <stdint.h>

/*@
    requires (1 <= (x) <= 23);
    ensures \result == (48 - (x));
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t result;
    
    //@ assert 48 - (int32_t)x == 48 - (int32_t)x;
    
    result = 48 - (int32_t)x;
    return result;
}
