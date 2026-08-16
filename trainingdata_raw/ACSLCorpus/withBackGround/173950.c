#include <limits.h>

/*@
    predicate in_range(integer v) = -1000 <= v <= 1000;
    predicate product_in_range(integer x, integer y) = -1000000 <= x * y <= 1000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d || \result == c * b;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int max1;
    int max2;
    int max3;
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);
    
    //@ assert product_in_range(a, c);
    tmp1 = a * c;
    //@ assert product_in_range(a, d);
    tmp2 = a * d;
    
    if (tmp1 > tmp2) {
        max1 = tmp1;
    } else {
        max1 = tmp2;
    }
    
    //@ assert product_in_range(b, c);
    tmp3 = b * c;
    //@ assert product_in_range(b, d);
    tmp4 = b * d;
    
    if (tmp3 > tmp4) {
        max2 = tmp3;
    } else {
        max2 = tmp4;
    }
    
    //@ assert max1 == a * c || max1 == a * d;
    //@ assert max2 == b * c || max2 == b * d;
    
    if (max1 > max2) {
        max3 = max1;
    } else {
        max3 = max2;
    }
    
    //@ assert max3 == a * c || max3 == a * d || max3 == b * c || max3 == b * d || max3 == c * b;
    return max3;
}
