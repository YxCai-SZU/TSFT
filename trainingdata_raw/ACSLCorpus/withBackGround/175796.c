#include <stddef.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bounds: \forall integer a, b; 
        valid_range(a, b) ==> 1 <= safe_product(a, b) <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == safe_product(a, b);
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert valid_range(a, b);
    //@ assert 1 <= safe_product(a, b) <= 10000;
    
    result = a * b;
    
    //@ assert result == safe_product(a, b);
    return result;
}
