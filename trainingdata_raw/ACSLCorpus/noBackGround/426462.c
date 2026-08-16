#include <stdint.h>

/*@
    requires ((n) >= 0 && (n) <= 1000000000);
    ensures \result == (((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t ans;
    
    //@ assert n + 1 <= 1000000001;
    //@ assert (n + 1) / 2 <= 500000000;
    
    ans = (n + 1) / 2;
    return ans;
}
