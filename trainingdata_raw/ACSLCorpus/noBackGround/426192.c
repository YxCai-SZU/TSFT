#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result >= 0;
    ensures \result <= n * n;
    ensures \result == n * n - m || \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    uint32_t nn;
    int32_t ans;
    
    //@ assert n * n <= 10000;
    //@ assert n * n >= m;
    
    nn = n * n;
    ans = (int32_t)nn - (int32_t)m;
    
    if (ans < 0)
    {
        ans = 0;
    }
    
    //@ assert ans == 0 || ans == n * n - m;
    
    return ans;
}
