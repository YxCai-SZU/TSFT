#include <stdint.h>

/*@
    predicate is_valid_params(integer a, integer b) =
        a > 0 && a <= 10 && b > 0 && b <= 10;
    
    logic integer safe_product(integer a, integer b) = a * b;
    
    lemma product_bounds: \forall integer a, b;
        is_valid_params(a, b) ==> safe_product(a, b) <= 100;
*/

/*@
    requires is_valid_params(a, b);
    ensures \result == safe_product(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert a > 0 && a <= 10;
    //@ assert b > 0 && b <= 10;
    //@ assert a * b <= 100;
    
    return a * b;
}
