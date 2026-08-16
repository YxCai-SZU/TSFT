#include <stdint.h>

/*@
    requires (1 <= (k) <= 32 && (k) <= (n) <= 32);
    ensures \result == ((n) - ((k) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k)
{
    uint32_t ans;
    
    //@ assert k > 0 && k <= 32 && n >= k;
    ans = n - (k - 1);
    
    return ans;
}
