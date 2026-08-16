#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer v) = -1000000000000000000 <= v <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long max_val;

    //@ assert product_in_range(a * c);
    max_val = a * c;

    //@ assert product_in_range(a * d);
    if (a * d > max_val)
    {
        max_val = a * d;
    }

    //@ assert product_in_range(b * c);
    if (b * c > max_val)
    {
        max_val = b * c;
    }

    //@ assert product_in_range(b * d);
    if (b * d > max_val)
    {
        max_val = b * d;
    }

    return max_val;
}
