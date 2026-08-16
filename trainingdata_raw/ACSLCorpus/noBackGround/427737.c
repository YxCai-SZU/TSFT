#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long res;

    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);

    res = a * c;
    if (a * d > res)
    {
        res = a * d;
    }
    if (b * c > res)
    {
        res = b * c;
    }
    if (b * d > res)
    {
        res = b * d;
    }
    return res;
}
