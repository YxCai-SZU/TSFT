#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer expected_result(integer a, integer b) =
        a * b + 1;
    
    lemma product_bounds:
        \forall integer a, b;
        valid_range(a, b) ==> 1 <= a * b <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t product;
    int32_t result;
    
    //@ assert valid_range(a, b);
    
    //@ assert 1 <= a * b <= 10000;
    
    product = a * b;
    
    //@ assert product == a * b;
    
    result = (int32_t)(product + 1);
    
    //@ assert result == expected_result(a, b);
    
    return result;
}
