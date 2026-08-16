#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t ans;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (3 * (r) * (r)) <= 30000;
    
    ans = 3 * r * r;
    
    //@ assert ans == (3 * (r) * (r));
    return ans;
}
