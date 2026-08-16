#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer v) = -1000000000000000000 <= v <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == a * c || \result == b * c || \result == a * d || \result == b * d;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long x;
    
    //@ assert product_in_range(a * c);
    //@ assert product_in_range(b * c);
    
    x = a * c;
    if (b * c > x) {
        x = b * c;
    }
    
    //@ assert product_in_range(a * d);
    //@ assert product_in_range(b * d);
    
    if (a * d > x) {
        x = a * d;
    }
    if (b * d > x) {
        x = b * d;
    }
    
    return x;
}
