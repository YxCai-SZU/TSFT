#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result == ((n) > (m) ? (n) - (m) : (m) - (n));
    ensures \result <= n + m;
    ensures \result >= n - m;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t result;

    //@ assert (1 <= (n) && (n) <= 1000000000000 &&         1 <= (m) && (m) <= 1000000000000);

    if (n > m)
    {
        //@ assert n > m;
        result = n - m;
        //@ assert result == n - m;
    }
    else
    {
        //@ assert m >= n;
        result = m - n;
        //@ assert result == m - n;
    }

    //@ assert result == ((n) > (m) ? (n) - (m) : (m) - (n));
    //@ assert result <= n + m;
    //@ assert result >= n - m;

    return result;
}
