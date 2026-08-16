#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate bounds_ok(integer a, integer b, integer c, integer d) =
        in_range(a) && in_range(b) && in_range(c) && in_range(d) &&
        a <= b && c <= d;
*/

/*@
    requires bounds_ok(a, b, c, d);
    ensures \result == a*d || \result == a*c || \result == b*d || \result == b*c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d) {
    long x1;
    long x2;
    long x3;
    long x4;
    long x;

    //@ assert bounds_ok(a, b, c, d);
    
    // Bounds verification for products
    //@ assert -1000000000000000000 <= a*c <= 1000000000000000000;
    //@ assert -1000000000000000000 <= a*d <= 1000000000000000000;
    //@ assert -1000000000000000000 <= b*c <= 1000000000000000000;
    //@ assert -1000000000000000000 <= b*d <= 1000000000000000000;

    x1 = a * c;
    x2 = a * d;
    x3 = b * c;
    x4 = b * d;
    
    x = x1;
    if (x2 > x) {
        x = x2;
    }
    if (x3 > x) {
        x = x3;
    }
    if (x4 > x) {
        x = x4;
    }
    
    // Final verification
    //@ assert x == a*d || x == a*c || x == b*d || x == b*c;
    return x;
}
