#include <stdint.h>

/*@
    requires (3 <= (n) <= 100);
    ensures \result == (((n) - 2) * 180);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    int32_t ans;
    
    //@ assert 1 <= n - 2 <= 98;
    
    //@ assert 180 <= (n - 2) * 180 <= 17640;
    
    ans = (int32_t)((n - 2) * 180);
    
    //@ assert ans == (((n) - 2) * 180);
    
    return ans;
}
