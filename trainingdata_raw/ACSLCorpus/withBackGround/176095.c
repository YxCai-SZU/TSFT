#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(c, a) || \result == product(c, b) || 
            \result == product(a, d) || \result == product(b, d);
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long ans;
    long max1;
    long max2;
    long ca;
    long cb;
    long ad;
    long bd;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    ca = c * a;
    //@ assert ca == product(c, a);
    //@ assert ca <= 10000;

    cb = c * b;
    //@ assert cb == product(c, b);
    //@ assert cb <= 10000;

    ad = a * d;
    //@ assert ad == product(a, d);
    //@ assert ad <= 10000;

    bd = b * d;
    //@ assert bd == product(b, d);
    //@ assert bd <= 10000;

    if (ca > cb) {
        max1 = ca;
    } else {
        max1 = cb;
    }
    //@ assert max1 == product(c, a) || max1 == product(c, b);

    if (ad > bd) {
        max2 = ad;
    } else {
        max2 = bd;
    }
    //@ assert max2 == product(a, d) || max2 == product(b, d);

    if (max1 > max2) {
        ans = max1;
    } else {
        ans = max2;
    }
    //@ assert ans == product(c, a) || ans == product(c, b) || ans == product(a, d) || ans == product(b, d);

    return ans;
}
