#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a && a <= 3 &&
        1 <= b && b <= 3 &&
        a != b;

    logic integer compute_result(integer a, integer b) = 6 - (a + b);

    lemma result_properties:
        \forall integer a, b;
        valid_inputs(a, b) ==>
            compute_result(a, b) >= 1 &&
            compute_result(a, b) <= 3 &&
            compute_result(a, b) != a &&
            compute_result(a, b) != b;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result == compute_result(a, b);
*/
uint32_t func(uint64_t a, uint64_t b)
{
    uint32_t ans;
    
    ans = 6 - (uint32_t)(a + b);
    
    //@ assert ans == compute_result(a, b);
    
    return ans;
}
