#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer v) = -1000000000000000000 <= v <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == a * d || \result == b * c || \result == a * c;
    ensures product_in_range(\result);
*/
long long func(long long a, long long b, long long c, long long d) {
    long long max_val;
    long long current;

    //@ assert in_range(a) && in_range(c);
    //@ assert product_in_range(a * c);
    max_val = a * c;

    //@ assert product_in_range(a * d);
    current = a * d;
    if (current > max_val) {
        max_val = current;
    }
    //@ assert max_val == a * c || max_val == a * d;

    //@ assert product_in_range(b * c);
    current = b * c;
    if (current > max_val) {
        max_val = current;
    }
    //@ assert max_val == a * c || max_val == a * d || max_val == b * c;

    //@ assert product_in_range(b * d);
    current = b * d;
    if (current > max_val) {
        max_val = current;
    }
    //@ assert max_val == a * c || max_val == a * d || max_val == b * c || max_val == b * d;

    //@ assert product_in_range(max_val);
    return max_val;
}
