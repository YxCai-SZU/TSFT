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
    long max_val;
    long temp_val;

    //@ assert product_in_range(a, c);
    max_val = a * c;

    //@ assert product_in_range(a, d);
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert product_in_range(b, c);
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert product_in_range(b, d);
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    return max_val;
}
