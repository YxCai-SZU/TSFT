#include <stdint.h>

/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate in_range(integer x) = 1 <= x <= 20;
    
    logic integer safe_product(integer a, integer b) = a * b;
    
    lemma product_bound: \forall integer a, b; 
        is_small(a) && is_small(b) ==> safe_product(a, b) <= 81;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures (a <= 9 && b <= 9 ==> \result == a * b) && 
            (!(a <= 9 && b <= 9) ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t max;
    int32_t result;
    
    //@ assert in_range(a) && in_range(b);
    
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    
    if (max <= 9) {
        //@ assert a <= 9 && b <= 9;
        //@ assert is_small(a) && is_small(b);
        //@ assert a * b <= 81;
        result = (int32_t)(a * b);
    } else {
        result = -1;
    }
    
    return result;
}
