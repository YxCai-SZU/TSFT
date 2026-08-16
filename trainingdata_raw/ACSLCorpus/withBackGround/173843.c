#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate in_range64(integer v) = -1000000000000000000 <= v <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    requires a <= INT_MAX && a >= INT_MIN;
    requires b <= INT_MAX && b >= INT_MIN;
    requires c <= INT_MAX && c >= INT_MIN;
    requires d <= INT_MAX && d >= INT_MIN;
    ensures \result >= a * c;
    ensures \result >= a * d;
    ensures \result >= b * c;
    ensures \result >= b * d;
*/
long func(long a, long b, long c, long d) {
    long max1;
    long max2;
    long res;
    
    //@ assert in_range64(a * c);
    //@ assert in_range64(a * d);
    //@ assert in_range64(b * c);
    //@ assert in_range64(b * d);
    
    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }
    
    if (b * c > b * d) {
        max2 = b * c;
    } else {
        max2 = b * d;
    }
    
    if (max1 > max2) {
        res = max1;
    } else {
        res = max2;
    }
    
    return res;
}
