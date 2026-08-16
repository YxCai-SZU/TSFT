#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * (314159));
    assigns \nothing;
*/
int64_t func(uint32_t r)
{
    int64_t pi = 314159;
    int64_t ans;
    
    //@ assert pi == (314159);
    //@ assert 2 * (int64_t)r * 314159 == 2 * (int64_t)r * pi;
    
    ans = 2 * (int64_t)r * pi;
    
    //@ assert ans == (2 * (r) * (314159));
    return ans;
}
