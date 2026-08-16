#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n <= 20 && 1 <= a <= 100 && 1 <= b <= 2000;
    
    logic integer product(integer n, integer a) = n * a;
    
    lemma product_bound: \forall integer n, a; 
        valid_params(n, a, 0) ==> product(n, a) <= 2000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == product(n, a) || \result == b;
    ensures \result <= product(n, a);
    ensures \result <= b;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a, uint32_t b) {
    uint32_t max_val;
    uint32_t min_val;
    uint32_t product_val;
    
    //@ assert valid_params(n, a, b);
    
    product_val = n * a;
    
    //@ assert product_val == product(n, a);
    //@ assert product_val <= 2000;
    
    if (product_val > b) {
        max_val = product_val;
    } else {
        max_val = b;
    }
    
    if (product_val < b) {
        min_val = product_val;
    } else {
        min_val = b;
    }
    
    //@ assert min_val == product_val || min_val == b;
    //@ assert min_val <= product_val;
    //@ assert min_val <= b;
    
    return min_val;
}
