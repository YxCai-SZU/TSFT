#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer x, integer y) = 
        -1000000000000000000 <= x * y <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d) {
    long max_val;
    long bc;
    long ad;
    long bd;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);

    //@ assert product_in_range(a, c);
    //@ assert product_in_range(a, d);
    //@ assert product_in_range(b, c);
    //@ assert product_in_range(b, d);

    max_val = a * c;

    bc = b * c;
    if (bc > max_val) {
        max_val = bc;
    }

    ad = a * d;
    if (ad > max_val) {
        max_val = ad;
    }

    bd = b * d;
    if (bd > max_val) {
        max_val = bd;
    }

    //@ assert max_val == b * d || max_val == b * c || max_val == a * d || max_val == a * c;
    return max_val;
}
