#include <limits.h>

/*@
    predicate valid_range(integer a, integer b) =
        a >= -1000000000 && b <= 1000000000 && a <= b;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer x, y;
            x >= -1000000000 && x <= 1000000000 &&
            y >= -1000000000 && y <= 1000000000 ==>
            product(x, y) >= -1000000000000000000 &&
            product(x, y) <= 1000000000000000000;
*/

/*@
    requires valid_range(a, b);
    requires valid_range(c, d);
    ensures \result == a*d || \result == a*c || \result == b*d || \result == b*c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long x;
    long y;
    long ans;

    //@ assert a >= -1000000000 && a <= 1000000000;
    //@ assert c >= -1000000000 && c <= 1000000000;
    //@ assert d >= -1000000000 && d <= 1000000000;
    //@ assert a*c >= -1000000000000000000 && a*c <= 1000000000000000000;
    //@ assert a*d >= -1000000000000000000 && a*d <= 1000000000000000000;

    if (a * c > a * d) {
        x = a * c;
    } else {
        x = a * d;
    }

    //@ assert b >= -1000000000 && b <= 1000000000;
    //@ assert b*c >= -1000000000000000000 && b*c <= 1000000000000000000;
    //@ assert b*d >= -1000000000000000000 && b*d <= 1000000000000000000;

    if (b * c > b * d) {
        y = b * c;
    } else {
        y = b * d;
    }

    //@ assert x >= -1000000000000000000 && x <= 1000000000000000000;
    //@ assert y >= -1000000000000000000 && y <= 1000000000000000000;

    if (x > y) {
        ans = x;
    } else {
        ans = y;
    }

    //@ assert ans >= -1000000000000000000 && ans <= 1000000000000000000;
    return ans;
}
