#include <stdint.h>

/*@
    predicate is_nonnegative(integer x) = 0 <= x;
    predicate within_bounds(integer x) = 0 <= x && x <= 1000000000;
    
    logic integer safe_product(integer a, integer b) = a * b;
    
    lemma product_bound: 
        \forall integer a, b; 
        within_bounds(a) && within_bounds(b) ==> 
        safe_product(a, b) <= 1000000000000000000;
*/

/*@
    requires within_bounds(a) && within_bounds(b);
    ensures \result <= 1000000000000000000;
*/
uint64_t func(uint64_t a, uint64_t b) {
    // Variable declarations at scope top
    uint64_t product;
    
    //@ assert within_bounds(a);
    //@ assert within_bounds(b);
    
    //@ assert a <= 1000000000;
    //@ assert b <= 1000000000;
    
    //@ assert a * b <= 1000000000 * 1000000000;
    
    product = a * b;
    
    //@ assert product <= 1000000000000000000;
    
    return product;
}
