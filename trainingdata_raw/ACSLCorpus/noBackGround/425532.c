#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures ((\result) == 3 * (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert 3 * r <= 300;
    
    //@ assert 3 * r * r <= 300 * 100;
    
    result = 3 * r * r;
    
    //@ assert ((result) == 3 * (r) * (r));
    return result;
}
