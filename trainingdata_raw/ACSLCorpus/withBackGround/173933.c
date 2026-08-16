#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate in_range64(integer v) = -1000000000000000000 <= v <= 1000000000000000000;
    logic integer product(integer x, integer y) = x * y;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == product(a, c) || \result == product(b, c) || 
            \result == product(a, d) || \result == product(b, d);
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long x1;
    long long x2;
    long long x3;
    long long x4;
    long long max_val;

    //@ assert in_range64(product(a, c));
    //@ assert in_range64(product(b, c));
    //@ assert in_range64(product(a, d));
    //@ assert in_range64(product(b, d));

    x1 = a * c;
    x2 = b * c;
    x3 = a * d;
    x4 = b * d;

    max_val = x1;
    if (x2 > max_val) {
        max_val = x2;
    }
    if (x3 > max_val) {
        max_val = x3;
    }
    if (x4 > max_val) {
        max_val = x4;
    }

    return max_val;
}
