#include <stdint.h>

/*@
    requires 1 <= k && k <= 200;
    ensures \result == (k * k * 3) / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t k)
{
    // Variable declarations at scope top
    uint64_t ans;
    
    //@ assert k * k <= 200 * 200;
    
    //@ assert k * k * 3 <= 200 * 200 * 3;
    
    ans = k * k * 3 / 2;
    
    //@ assert ans == (k * k * 3) / 2;
    
    return ans;
}
