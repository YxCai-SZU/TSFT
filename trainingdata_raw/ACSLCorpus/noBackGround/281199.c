#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * (r * r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at the top
    int64_t pi;
    int64_t r_squared;
    int64_t ans;

    pi = 3;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert 1 * 1 <= r * r <= 100 * 100;
    r_squared = r * r;
    
    //@ assert 3 * (1 * 1) <= 3 * (r * r) <= 3 * (100 * 100);
    ans = pi * r_squared;
    
    //@ assert ans == 3 * (r * r);
    return ans;
}
