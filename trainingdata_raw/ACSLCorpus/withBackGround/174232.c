#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 20;
    predicate b_in_range(integer b) = 1 <= b <= 20;
    predicate both_small(integer a, integer b) = a <= 9 && b <= 9;
    predicate one_large(integer a, integer b) = a > 9 || b > 9;
    logic integer safe_product(integer a, integer b) = a * b;
    lemma product_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> safe_product(a, b) <= 400;
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    ensures (both_small(a, b) ==> \result == safe_product(a, b));
    ensures (one_large(a, b) ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at top
    int32_t result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert safe_product(a, b) <= 400;
    
    if (a > 9 || b > 9) {
        result = -1;
    } else {
        result = (int32_t)(a * b);
    }
    
    return result;
}
