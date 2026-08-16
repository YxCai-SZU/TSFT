#include <stdbool.h>

/*@
    predicate is_overlap(integer a, integer b, integer c, integer d) =
        (c <= a && a <= d) || (c <= b && b <= d) || (a <= c && c <= b) || (a <= d && d <= b);
 */

/*@
    requires -1000000000 <= a <= 1000000000;
    requires -1000000000 <= b <= 1000000000;
    requires -1000000000 <= c <= 1000000000;
    requires -1000000000 <= d <= 1000000000;
    requires a <= b;
    requires c <= d;
    ensures \result == true <==> is_overlap(a, b, c, d);
 */
bool func(long a, long b, long c, long d)
{
    long e;
    long f;
    bool result;

    //@ assert a <= b && c <= d;

    if (a > c)
    {
        e = a;
    }
    else
    {
        e = c;
    }

    if (b < d)
    {
        f = b;
    }
    else
    {
        f = d;
    }

    if (e <= f)
    {
        result = true;
        //@ assert is_overlap(a, b, c, d);
        return result;
    }
    else
    {
        //@ assert e > f;
        //@ assert !is_overlap(a, b, c, d);
        result = false;
        return result;
    }
}
