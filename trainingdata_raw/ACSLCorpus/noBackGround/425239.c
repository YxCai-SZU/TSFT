#include <stdint.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((x) * (x) * 3);
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert (1 <= (x) <= 100);
    
    //@ assert 3 <= x * x * 3 <= 30000;
    
    result = x * x * 3;
    
    //@ assert result == ((x) * (x) * 3);
    
    return result;
}
