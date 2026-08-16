#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 23);
    ensures \result == (48 - (n));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    
    //@ assert (1 <= (n) && (n) <= 23);
    result = 48 - (int32_t)n;
    
    //@ assert result == (48 - (n));
    return result;
}
