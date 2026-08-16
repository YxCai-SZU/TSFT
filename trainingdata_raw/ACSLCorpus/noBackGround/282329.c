#include <stddef.h>
/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
size_t func(size_t r)
{
    // Variable declarations at top of scope
    size_t res;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (3 * (r) * (r)) <= 30000;
    
    res = 3 * r * r;
    return res;
}
