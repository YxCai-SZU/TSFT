#include <stdint.h>

/*@
    requires 0 <= n <= 1000000000000000000;
    requires 0 <= m <= 1000000000000000000;
    ensures \result <= n + m;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at top of scope
    uint64_t result;

    //@ assert (0 <= (n) <= 1000000000000000000 &&         0 <= (m) <= 1000000000000000000);

    if (2 * n < m)
    {
        //@ assert 2 * n < m;
        //@ assert n + (m - 2 * n) / 4 <= n + m;
        result = n + (m - 2 * n) / 4;
    }
    else
    {
        //@ assert 2 * n >= m;
        //@ assert m / 2 <= n + m;
        result = m / 2;
    }

    //@ assert result <= n + m;
    return result;
}
