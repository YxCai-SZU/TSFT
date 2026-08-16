#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (((n) - 2) * 180);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t result;
    
    //@ assert (3 <= (n) && (n) <= 100);
    x = (int32_t)n - 2;
    
    //@ assert x == (int32_t)n - 2;
    
    result = x * 180;
    //@ assert result == (((n) - 2) * 180);
    
    return result;
}

