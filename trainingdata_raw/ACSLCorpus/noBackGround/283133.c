#include <stdint.h>

/*@
    requires (0 <= (n) <= 100000000000000000 &&
        0 <= (m) <= 100000000000000000);
    ensures \result >= 0;
    ensures \result <= m / 2;
    ensures \result <= n;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at scope top
    uint64_t ans;

    //@ assert n <= 100000000000000000;
    //@ assert m / 2 <= 50000000000000000;

    if (n < m / 2) {
        ans = n;
    } else {
        ans = m / 2;
    }

    //@ assert ans >= 0;
    return ans;
}
