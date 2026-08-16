#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == (((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t ans;
    
    //@ assert (1 <= (n) <= 100);
    
    //@ assert n + 1 <= 101;
    //@ assert (n + 1) / 2 <= 50;
    
    ans = (n + 1) / 2;
    
    //@ assert ans == (((n) + 1) / 2);
    
    return ans;
}
