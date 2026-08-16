#include <stdint.h>

/*@
    predicate in_range(integer x) = 0 <= x <= 100;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_range:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> 
            0 <= product(x, y) <= 10000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == product(c, d) || 
            \result == product(b, d) || 
            \result == product(a, c) || 
            \result == product(a, b);
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d) {
    uint64_t max1;
    uint64_t max2;
    uint64_t result;
    
    //@ assert 0 <= product(a, b) <= 10000;
    //@ assert 0 <= product(a, c) <= 10000;
    //@ assert 0 <= product(b, d) <= 10000;
    //@ assert 0 <= product(c, d) <= 10000;
    
    if (a * b > a * c) {
        max1 = a * b;
    } else {
        max1 = a * c;
    }
    
    if (b * d > c * d) {
        max2 = b * d;
    } else {
        max2 = c * d;
    }
    
    if (max1 > max2) {
        result = max1;
    } else {
        result = max2;
    }
    
    //@ assert result == product(c, d) || result == product(b, d) || result == product(a, c) || result == product(a, b);
    return result;
}
