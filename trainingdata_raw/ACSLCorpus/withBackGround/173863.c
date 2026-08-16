#include <stdint.h>

/*@
    predicate bounds(integer a) = 0 <= a < 24;
    
    logic integer mod24(integer x) = x % 24;
*/

/*@
    requires bounds(a) && bounds(b);
    ensures \result == mod24(a + b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t ans;
    
    //@ assert a + b < 48;
    
    ans = (a + b) % 24;
    return ans;
}
