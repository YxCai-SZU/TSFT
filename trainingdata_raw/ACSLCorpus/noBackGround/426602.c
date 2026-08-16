#include <stddef.h>
/*@
    requires 1 <= n && 1 <= m;
    requires n <= 1000000000000 && m <= 1000000000000;
    ensures \result <= n + m;
    ensures \result >= 0;
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t res;
    //@ assert 1 <= n && 1 <= m;
    //@ assert n <= 1000000000000 && m <= 1000000000000;

    if (2 * n < m)
    {
        //@ assert 2 * n < m;
        //@ assert n + ((m - 2 * n) / 4) <= n + m;
        res = n + ((m - 2 * n) / 4);
    }
    else
    {
        //@ assert 2 * n >= m;
        //@ assert m / 2 <= n + m;
        res = m / 2;
    }

    //@ assert res <= n + m;
    //@ assert res >= 0;
    return res;
}
