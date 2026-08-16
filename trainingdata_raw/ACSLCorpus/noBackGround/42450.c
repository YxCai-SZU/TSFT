#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000 && 1 <= (k) <= (n));
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t ans;
    
    //@ assert (1 <= (n) <= 100000 && 1 <= (k) <= (n));
    ans = n - k + 1;
    //@ assert ans == ((n) - (k) + 1);
    
    return ans;
}
