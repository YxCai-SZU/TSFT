#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a > b / 2 ? b / 2 : a;

    lemma result_properties:
        \forall integer a, b;
        valid_inputs(a, b) ==>
            compute_result(a, b) <= a &&
            compute_result(a, b) * 2 <= b;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result <= a;
    ensures \result * 2 <= b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t ans;
    //@ assert valid_inputs(a, b);
    
    if (a > b / 2) {
        ans = b / 2;
    } else {
        ans = a;
    }
    
    //@ assert ans <= a;
    //@ assert ans * 2 <= b;
    
    return ans;
}
