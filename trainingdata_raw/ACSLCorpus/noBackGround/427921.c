#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (((r)) * ((r))));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t r_squared;
    int64_t ans;
    
    //@ assert (1 <= (r) <= 100);
    
    //@ assert 1 <= r * r <= 10000;
    r_squared = r * r;
    
    //@ assert 3 * r_squared <= 30000;
    //@ assert 3 * r_squared >= 3;
    ans = 3 * r_squared;
    
    //@ assert ans == (3 * (((r)) * ((r))));
    return ans;
}
