#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at top of scope
    int32_t res;

    //@ assert (1 <= (r) <= 100);
    //@ assert r * r <= 10000;
    //@ assert 3 * r * r <= 30000;
    
    res = 3 * r * r;
    return res;
}
