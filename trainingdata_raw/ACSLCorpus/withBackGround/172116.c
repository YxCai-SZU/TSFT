#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    
    logic integer max_of_four(integer m1, integer m2, integer m3, integer m4) =
        m1 >= m2 && m1 >= m3 && m1 >= m4 ? m1 :
        m2 >= m3 && m2 >= m4 ? m2 :
        m3 >= m4 ? m3 : m4;
    
    lemma product_in_range:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> 
            -1000000000000000000 <= x * y <= 1000000000000000000;
*/

/*@
    requires -1000000000 <= a <= b <= 1000000000;
    requires -1000000000 <= c <= d <= 1000000000;
    requires a <= LLONG_MAX && a >= LLONG_MIN;
    requires b <= LLONG_MAX && b >= LLONG_MIN;
    requires c <= LLONG_MAX && c >= LLONG_MIN;
    requires d <= LLONG_MAX && d >= LLONG_MIN;
    ensures \result >= a * c;
    ensures \result >= a * d;
    ensures \result >= b * c;
    ensures \result >= b * d;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long max1;
    long long max2;
    long long max3;
    long long max4;
    
    //@ assert in_range(a);
    //@ assert in_range(c);
    //@ assert -1000000000000000000 <= a * c <= 1000000000000000000;
    max1 = a * c;
    
    //@ assert in_range(a);
    //@ assert in_range(d);
    //@ assert -1000000000000000000 <= a * d <= 1000000000000000000;
    max2 = a * d;
    
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert -1000000000000000000 <= b * c <= 1000000000000000000;
    max3 = b * c;
    
    //@ assert in_range(b);
    //@ assert in_range(d);
    //@ assert -1000000000000000000 <= b * d <= 1000000000000000000;
    max4 = b * d;
    
    if (max1 < max2) {
        max1 = max2;
    }
    
    if (max1 < max3) {
        max1 = max3;
    }
    
    if (max1 < max4) {
        max1 = max4;
    }
    
    //@ assert max1 >= a * c;
    //@ assert max1 >= a * d;
    //@ assert max1 >= b * c;
    //@ assert max1 >= b * d;
    
    return max1;
}
