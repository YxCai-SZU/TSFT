#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate valid_input(integer a, integer b, integer c, integer d) =
        in_range(a) && in_range(b) && in_range(c) && in_range(d) &&
        a <= b && c <= d;
    predicate product_in_range(integer x, integer y) =
        -1000000000000000000 <= x * y <= 1000000000000000000;
*/

/*@
    requires valid_input(a, b, c, d);
    ensures \result == b * d || \result == a * c || 
            \result == a * d || \result == b * c;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max_val;
    long long temp_val;

    //@ assert product_in_range(a, c);
    //@ assert product_in_range(a, d);
    //@ assert product_in_range(b, c);
    //@ assert product_in_range(b, d);

    max_val = a * c;
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    return max_val;
}
