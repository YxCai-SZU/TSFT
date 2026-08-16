#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 3);
    assigns \nothing;
*/
int32_t func(uint32_t r)
{
    int32_t result;
    
    //@ assert (1 <= (r) <= 100);
    result = (int32_t)(r * 6);
    
    //@ assert result == 2 * (int32_t)r * 3;
    return result;
}
