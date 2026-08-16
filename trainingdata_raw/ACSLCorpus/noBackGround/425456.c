#include <stdint.h>

/*@
    requires (1 <= (m) && (m) <= 24);
    assigns \nothing;
    ensures \result == (48 - (integer)(m));
*/
int32_t func(uint32_t m)
{
    int32_t ans;
    int32_t tmp;
    
    //@ assert (1 <= (m) && (m) <= 24);
    tmp = (int32_t)m;
    ans = (24 - tmp) + 24;
    
    //@ assert ans == 48 - (int32_t)m;
    return ans;
}
