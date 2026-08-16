#include <stdint.h>

/*@
    requires (1 <= (k) && (k) <= (n) && (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t k)
{
    int32_t ans;
    //@ assert 1 <= k && k <= n && n <= 50;
    ans = (int32_t)(n - k + 1);
    //@ assert ans >= 1;
    //@ assert ans <= (int32_t)n;
    return ans;
}
