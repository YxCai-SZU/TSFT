#include <stdint.h>

/*@
    requires (1 <= (r) <= 4500 && 1 <= (g) <= 4500);
    ensures \result == (2 * (g) - (r));
    assigns \nothing;
*/
int32_t func(int32_t r, int32_t g)
{
    // Variable declarations at top of scope
    int32_t b;
    
    //@ assert (1 <= (r) <= 4500 && 1 <= (g) <= 4500);
    
    b = 2 * g - r;
    
    //@ assert b == (2 * (g) - (r));
    
    return b;
}

