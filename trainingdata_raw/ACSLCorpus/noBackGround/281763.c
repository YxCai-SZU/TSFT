#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * 50 - 1);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    int32_t result;
    
    //@ assert (1 <= (a) <= 100);
    result = (int32_t)(a * 50) - 1;
    
    //@ assert result == ((a) * 50 - 1);
    return result;
}
