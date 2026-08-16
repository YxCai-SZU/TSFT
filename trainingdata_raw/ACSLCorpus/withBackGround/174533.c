#include <stdint.h>

/*@
    predicate in_range(integer a) = -100 <= a <= 100;
    
    logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = a - b;
    logic integer prod(integer a, integer b) = a * b;
    
    lemma product_bounds: 
        \forall integer a, b; in_range(a) && in_range(b) ==> -10000 <= prod(a, b) <= 10000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == sum(a, b) || \result == diff(a, b) || \result == prod(a, b);
    ensures \result >= sum(a, b) && \result >= diff(a, b) && \result >= prod(a, b);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t x;
    int64_t y;
    int64_t z;
    int64_t max_val;
    
    x = a + b;
    y = a - b;
    z = a * b;
    
    //@ assert x >= -200 && x <= 200;
    //@ assert y >= -200 && y <= 200;
    //@ assert z >= -10000 && z <= 10000;
    
    max_val = x;
    
    if (y > max_val) {
        max_val = y;
    }
    
    if (z > max_val) {
        max_val = z;
    }
    
    return max_val;
}
