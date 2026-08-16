#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result == ((n) > (m) / 2 ? (m) / 2 : (n) + ((m) - 2 * (n)) / 4);
    ensures \result <= n + m / 2;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at scope top
    uint64_t sub;
    uint64_t add;
    uint64_t result;

    if (n > m / 2)
    {
        result = m / 2;
        //@ assert result == m / 2;
    }
    else
    {
        sub = m - 2 * n;
        add = sub / 4;
        result = n + add;
        
        //@ assert result == n + (m - 2 * n) / 4;
        //@ assert result <= n + m / 2;
    }

    return result;
}
