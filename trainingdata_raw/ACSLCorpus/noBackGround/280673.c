#include <stddef.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
size_t func(size_t r)
{
    // Variable declarations at scope top
    size_t ans;
    
    //@ assert 1 <= r && r <= 100;
    
    //@ assert r * r <= 10000;
    
    //@ assert 3 * r * r <= 30000;
    
    ans = 3 * r * r;
    
    return ans;
}
