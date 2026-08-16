#include <stdint.h>

/*@
    requires (3 <= (s) <= 100);
    ensures \result == (((s) - 2) * 180);
    assigns \nothing;
*/
int32_t func(uint32_t s)
{
    int32_t result;
    
    //@ assert 1 <= s - 2 <= 98;
    result = (int32_t)(s - 2) * 180;
    
    return result;
}
