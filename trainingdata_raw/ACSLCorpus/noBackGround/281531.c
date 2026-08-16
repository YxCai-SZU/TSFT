#include <limits.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b && \result >= c * d;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long x;
    long y;
    long result;

    //@ assert (-100000000 <= (a * b) <= 100000000);
    //@ assert (-100000000 <= (c * d) <= 100000000);

    x = a * b;
    y = c * d;

    //@ assert (-100000000 <= (x) <= 100000000);
    //@ assert (-100000000 <= (y) <= 100000000);

    if (x > y)
    {
        result = x;
    }
    else
    {
        result = y;
    }

    //@ assert result == x || result == y;
    //@ assert result >= x && result >= y;

    return result;
}
