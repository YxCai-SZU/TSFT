#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 100);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert (0 <= (x) && (x) <= 100);
    //@ assert x * x <= 100 * 100;
    //@ assert x * x * x <= 100 * 100 * 100;
    
    result = x * x * x;
    
    //@ assert result == ((x) * (x) * (x));
    return result;
}
