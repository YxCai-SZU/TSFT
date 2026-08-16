#include <limits.h>
#include <stdint.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate in_i64_range(integer v) = INT64_MIN <= v <= INT64_MAX;
    predicate product_in_range(integer x, integer y) =
        -1000000000000000000 <= x * y <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && a <= b;
    requires in_range(c) && in_range(d) && c <= d;
    requires in_i64_range(a) && in_i64_range(b);
    requires in_i64_range(c) && in_i64_range(d);
    ensures \result == a * d || \result == a * c || 
            \result == b * d || \result == b * c;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long x;
    long long y;
    long long ans;
    
    //@ assert in_range(a);
    //@ assert in_range(c);
    //@ assert INT64_MIN <= a <= INT64_MAX;
    //@ assert INT64_MIN <= c <= INT64_MAX;
    
    //@ assert product_in_range(a, c);
    //@ assert product_in_range(a, d);
    //@ assert product_in_range(b, c);
    //@ assert product_in_range(b, d);
    
    if (a * c > a * d) {
        x = a * c;
    } else {
        x = a * d;
    }
    
    if (b * c > b * d) {
        y = b * c;
    } else {
        y = b * d;
    }
    
    if (x > y) {
        ans = x;
    } else {
        ans = y;
    }
    
    //@ assert x == a * c || x == a * d;
    //@ assert y == b * c || y == b * d;
    //@ assert ans == x || ans == y;
    //@ assert ans == a * c || ans == a * d || ans == b * c || ans == b * d;
    
    return ans;
}
