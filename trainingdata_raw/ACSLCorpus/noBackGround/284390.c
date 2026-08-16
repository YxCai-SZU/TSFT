#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at top of scope
    int32_t pi;
    int32_t result;
    
    //@ assert (1 <= (r) <= 100);
    
    pi = 3;
    
    //@ assert pi * r <= 300;
    
    //@ assert pi * r * r <= 30000;
    
    result = pi * r * r;
    
    //@ assert result == (3 * (r) * (r));
    
    return result;
}
