#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result <= n + m / 2;
    ensures \result >= m / 4;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at scope top
    uint64_t ans;

    //@ assert m >= 2 * n || m < 2 * n;
    //@ assert m <= 2 * n || m > 2 * n;
    //@ assert m / 2 <= 1000000000000;
    //@ assert m / 4 <= 1000000000000;

    if (2 * n < m)
    {
        ans = n + (m - 2 * n) / 4;
    }
    else
    {
        ans = m / 2;
    }

    return ans;
}
