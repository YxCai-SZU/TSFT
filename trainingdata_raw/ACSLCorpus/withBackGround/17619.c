#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer x, integer y) = -1000000000000000000 <= x * y <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d || \result == c * b;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max_value;
    long long current_value;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);
    
    //@ assert product_in_range(a, c);
    max_value = a * c;

    //@ assert product_in_range(a, d);
    current_value = a * d;
    if (current_value > max_value) {
        max_value = current_value;
    }

    //@ assert product_in_range(b, d);
    current_value = b * d;
    if (current_value > max_value) {
        max_value = current_value;
    }

    //@ assert product_in_range(c, b);
    current_value = c * b;
    if (current_value > max_value) {
        max_value = current_value;
    }

    return max_value;
}
