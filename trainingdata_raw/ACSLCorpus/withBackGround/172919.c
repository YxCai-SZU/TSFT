#include <stdint.h>

/*@
    predicate in_range(integer s) = 1 <= s && s <= 100;
*/

/*@
    requires in_range(s);
    ensures \result == s * s;
    assigns \nothing;
*/
uint32_t func(uint32_t s)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert in_range(s);
    //@ assert s * s <= 10000;
    
    ans = s * s;
    return ans;
}
