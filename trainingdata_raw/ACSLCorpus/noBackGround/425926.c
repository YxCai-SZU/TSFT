#include <stddef.h>

/*@
    requires (0 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= 100 &&
        (m) <= 2 * (n));
    ensures \result >= 0;
    ensures \result <= m;
    ensures \result <= 2 * n;
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t t;
    size_t u;
    size_t result;

    //@ assert (0 <= (n) && (n) <= 100 &&         0 <= (m) && (m) <= 100 &&         (m) <= 2 * (n));

    if (n > m / 2)
    {
        t = m / 2;
    }
    else
    {
        t = n;
    }

    u = m - 2 * t;
    result = t + u / 4;

    //@ assert result >= 0;
    //@ assert result <= m;
    //@ assert result <= 2 * n;

    return result;
}
