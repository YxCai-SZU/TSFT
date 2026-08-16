#include <stdbool.h>

/*@
    predicate non_negative(integer l, integer r) = l >= 0 && r >= 0;
    predicate sum_bound(integer l, integer r) = l + r <= 246;
*/

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long l = 0;
    long r = 0;

    if (a < b)
    {
        l = b - a;
    }
    else
    {
        r = a - b;
    }

    if (c < b)
    {
        //@ assert l >= 0 && r >= 0;
        l = (l > c - b) ? l : (c - b);
    }
    else
    {
        //@ assert l >= 0 && r >= 0;
        r = (r > b - c) ? r : (b - c);
    }

    if (d < c)
    {
        //@ assert l >= 0 && r >= 0;
        l = (l > c - d) ? l : (c - d);
    }
    else
    {
        //@ assert l >= 0 && r >= 0;
        r = (r > d - c) ? r : (d - c);
    }

    if (e < d)
    {
        //@ assert l >= 0 && r >= 0;
        l = (l > d - e) ? l : (d - e);
    }
    else
    {
        //@ assert l >= 0 && r >= 0;
        r = (r > e - d) ? r : (e - d);
    }

    //@ assert non_negative(l, r);
    //@ assert sum_bound(l, r);
    return e - a <= k;
}
