#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && a <= b;
    requires (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000) && c <= d;
    ensures \result == a * d || \result == b * c || \result == a * c || \result == b * d;
*/
long func(long a, long b, long c, long d)
{
    long x;
    long y;
    long ans;

    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);

    if (a * c > a * d)
    {
        x = a * c;
    }
    else
    {
        x = a * d;
    }

    if (b * c > b * d)
    {
        y = b * c;
    }
    else
    {
        y = b * d;
    }

    if (x > y)
    {
        ans = x;
    }
    else
    {
        ans = y;
    }

    return ans;
}
