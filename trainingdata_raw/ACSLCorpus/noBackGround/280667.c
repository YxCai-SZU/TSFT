#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0 && \result <= 200;
*/
size_t func(size_t a, size_t b, size_t c, size_t d)
{
    size_t m1;
    size_t m2;
    size_t res;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    if (a > b)
    {
        m1 = a - b;
    }
    else
    {
        m1 = b - a;
    }

    //@ assert (1 <= (c) <= 100) && (1 <= (d) <= 100);
    if (c > d)
    {
        m2 = c - d;
    }
    else
    {
        m2 = d - c;
    }

    //@ assert 0 <= m1 <= 100;
    //@ assert 0 <= m2 <= 100;
    if (m1 > m2)
    {
        res = m1 + m2;
    }
    else
    {
        res = m2 + m1;
    }

    //@ assert res == ((m1) > (m2) ? (m1) + (m2) : (m2) + (m1));
    //@ assert res <= 200;
    if (res >= 200)
    {
        return 0;
    }
    else
    {
        return res;
    }
}
