#include <stdbool.h>

/*@
    requires 0 <= a && a < 123;
    requires 0 <= b && b < 123;
    requires 0 <= c && c < 123;
    requires 0 <= d && d < 123;
    requires 0 <= e && e < 123;
    requires 0 <= k && k <= 123;
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long dist;

    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    //@ assert a < e;

    if (a > e)
    {
        dist = a - e;
    }
    else
    {
        dist = e - a;
    }

    //@ assert dist == ((a) > (e) ? (a) - (e) : (e) - (a));
    //@ assert dist == e - a;

    if (dist <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
