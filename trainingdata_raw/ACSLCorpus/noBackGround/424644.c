#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result == ((n) * 2 <= (m) ? ((m) - (n)) / 4 + (n) : (m) / 2);
    ensures \result <= n + m;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at top of scope
    uint64_t result;

    if (n * 2 <= m)
    {
        //@ assert n * 2 <= m;
        result = (m - n) / 4 + n;
    }
    else
    {
        //@ assert n * 2 > m;
        result = m / 2;
    }

    //@ assert result <= n + m;
    return result;
}
