#include <stdint.h>

/*@
    predicate in_range(integer x) = 0 <= x < 100;

    logic integer mul(integer x, integer y) = x * y;

    lemma mul_bounds: \forall integer a, integer b; 
        in_range(a) && in_range(b) ==> mul(a, b) < 10000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == mul(a, c) || \result == mul(a, d) || 
            \result == mul(b, c) || \result == mul(b, d);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d) {
    uint64_t max1;
    uint64_t max2;
    uint64_t max3;
    
    //@ assert mul(a, c) < 10000;
    //@ assert mul(a, d) < 10000;
    //@ assert mul(b, c) < 10000;
    //@ assert mul(b, d) < 10000;
    
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
        max3 = max1;
    } else {
        max3 = max2;
    }
    
    //@ assert max1 < 10000;
    //@ assert max2 < 10000;
    //@ assert max3 < 10000;
    //@ assert max3 == mul(a, c) || max3 == mul(a, d) || max3 == mul(b, c) || max3 == mul(b, d);
    
    return max3;
}
