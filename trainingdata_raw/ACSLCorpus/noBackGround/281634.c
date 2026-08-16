#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    uint32_t l;
    int32_t ans;

    //@ assert (1 <= (n) <= 100 && 0 <= (m) <= (n));
    l = n - m;
    
    //@ assert l == ((n) - (m));
    
    if (l == 0)
    {
        ans = 0;
    }
    else
    {
        ans = 1;
    }
    
    //@ assert ans == ((l) == 0 ? 0 : 1);
    //@ assert ans == 0 || ans == 1;
    
    return ans;
}
