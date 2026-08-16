#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000000 &&
        1 <= (m) && (m) <= 1000000000000000);
    ensures \result == ((m) >= 2 * (n) ? (n) + ((m) - 2 * (n)) / 4 : (m) / 2);
    ensures \result <= n + m / 2;
    ensures \result >= m / 4;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at scope top
    uint64_t s;
    uint64_t rem;
    uint64_t result;

    s = n + m / 2;

    //@ assert s == n + m / 2;

    if (m >= 2 * n)
    {
        rem = m - 2 * n;
        //@ assert rem == m - 2 * n;
        //@ assert rem / 4 <= m / 2;
        result = n + (rem / 4);
        //@ assert result == n + (rem / 4);
    }
    else
    {
        //@ assert m / 2 <= n + m / 2;
        result = m / 2;
        //@ assert result == m / 2;
    }

    //@ assert result == ((m) >= 2 * (n) ? (n) + ((m) - 2 * (n)) / 4 : (m) / 2);
    //@ assert result <= n + m / 2;
    //@ assert result >= m / 4;
    return result;
}
