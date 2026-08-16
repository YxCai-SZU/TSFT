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
    long long res = LLONG_MIN;
    
    //@ assert product_in_range(a, c);
    res = (res > a * c) ? res : a * c;
    
    //@ assert product_in_range(a, d);
    res = (res > a * d) ? res : a * d;
    
    //@ assert product_in_range(b, c);
    res = (res > b * c) ? res : b * c;
    
    //@ assert product_in_range(b, d);
    res = (res > b * d) ? res : b * d;
    
    return res;
}
