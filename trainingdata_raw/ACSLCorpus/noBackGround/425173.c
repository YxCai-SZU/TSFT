#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) + (b) + (c)) ||
            \result == ((a) + (c) + (d)) ||
            \result == ((a) + (b) + (d)) ||
            \result == ((b) + (c) + (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int sa;
    int sb;
    int sc;
    int sd;
    int m;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);

    //@ assert ((a) + (b) + (c)) <= 30000;
    sa = a + b + c;

    //@ assert ((a) + (c) + (d)) <= 30000;
    sb = a + c + d;

    //@ assert ((a) + (b) + (d)) <= 30000;
    sc = a + b + d;

    //@ assert ((b) + (c) + (d)) <= 30000;
    sd = b + c + d;

    m = sa;

    if (sb < m)
    {
        m = sb;
    }

    if (sc < m)
    {
        m = sc;
    }

    if (sd < m)
    {
        m = sd;
    }

    //@ assert m == sa || m == sb || m == sc || m == sd;

    return m;
}
