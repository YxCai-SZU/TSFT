#include <limits.h>

/*@
    predicate valid_range(integer x) = -1000000000 <= x <= 1000000000;
    predicate product_in_range(integer x, integer y) = -1000000000000000000 <= x * y <= 1000000000000000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max_value;
    
    //@ assert product_in_range(a, c);
    max_value = a * c;
    
    //@ assert product_in_range(a, d);
    if (a * d > max_value) {
        max_value = a * d;
    }
    
    //@ assert product_in_range(b, c);
    if (b * c > max_value) {
        max_value = b * c;
    }
    
    //@ assert product_in_range(b, d);
    if (b * d > max_value) {
        max_value = b * d;
    }
    
    return max_value;
}
