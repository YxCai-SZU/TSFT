#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 10000;

    ans = n * n - a;
    return ans;
}
