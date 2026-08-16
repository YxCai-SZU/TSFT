#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer x, integer y) = -1000000000000000000 <= x * y <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long max1;
    long max2;
    long res;

    //@ assert in_range(a);
    //@ assert in_range(c);
    //@ assert product_in_range(a, c);
    //@ assert product_in_range(a, d);
    max1 = (a * c > a * d) ? a * c : a * d;

    //@ assert in_range(b);
    //@ assert in_range(d);
    //@ assert product_in_range(b, d);
    //@ assert product_in_range(b, c);
    max2 = (b * c > b * d) ? b * c : b * d;

    res = (max1 > max2) ? max1 : max2;
    return res;
}
