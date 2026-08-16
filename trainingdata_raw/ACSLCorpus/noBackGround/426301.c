#include <stdint.h>

/*@
    requires (0 <= (n) <= 1000000000) && (0 <= (m) <= 1000000000);
    ensures (n < m ==> \result == m - n) && (n >= m ==> \result == 0);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t ans;
    
    if (n < m)
    {
        ans = m - n;
    }
    else
    {
        ans = 0;
    }
    
    //@ assert n < m ==> ans == m - n;
    //@ assert n >= m ==> ans == 0;
    
    return ans;
}
