#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        a >= 1 && a <= 100 &&
        b >= 0 && b <= a;

    logic integer compute_result(integer a, integer b) =
        b > a ? a : b;

    lemma result_bounds:
        \forall integer a, b;
        valid_inputs(a, b) ==>
        compute_result(a, b) >= 0 &&
        compute_result(a, b) <= a;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result >= 0 && \result <= a;
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t ans;
    
    //@ assert valid_inputs(a, b);
    
    if (b > a)
    {
        //@ assert a >= 1 && a <= 100;
        ans = a;
    }
    else
    {
        //@ assert b >= 0 && b <= a;
        ans = b;
    }
    
    //@ assert ans == compute_result(a, b);
    //@ assert ans >= 0 && ans <= a;
    
    return ans;
}
