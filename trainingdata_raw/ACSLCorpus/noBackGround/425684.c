#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result >= 0;
    ensures \result <= m / 2;
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t result;
    size_t l;

    //@ assert (1 <= (n) && (n) <= 1000000000000 &&         1 <= (m) && (m) <= 1000000000000);

    if (n >= m / 2)
    {
        result = m / 2;
        //@ assert result >= 0;
        //@ assert result <= m / 2;
        //@ assert result <= n + m / 2;
        return result;
    }
    else
    {
        l = m - 2 * n;
        //@ assert l >= 0 && l <= m;
        //@ assert l / 4 <= m / 4;
        result = n + l / 4;
        //@ assert result >= 0;
        //@ assert result <= m / 2;
        //@ assert result <= n + m / 2;
        return result;
    }
}
