#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        2 <= a && a <= 20 &&
        1 <= b && b <= 20;

    logic integer compute_result(integer a, integer b) =
        (b - 1 + (a - 2)) / (a - 1);

    lemma arithmetic_bounds:
        \forall integer a, b;
        valid_inputs(a, b) ==>
        b - 1 >= 0 &&
        a - 2 >= 0 &&
        (b - 1 + (a - 2)) >= 0 &&
        (b - 1 + (a - 2)) / (a - 1) <= (b - 1 + (a - 2));

    lemma result_in_u32_range:
        \forall integer a, b;
        valid_inputs(a, b) ==>
        0 <= compute_result(a, b) && compute_result(a, b) <= UINT32_MAX;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert b - 1 >= 0;
    //@ assert a - 2 >= 0;
    //@ assert (b - 1 + (a - 2)) >= 0;
    //@ assert (b - 1 + (a - 2)) / (a - 1) <= (b - 1 + (a - 2));
    //@ assert (b - 1 + (a - 2)) / (a - 1) <= UINT32_MAX;
    
    uint32_t result;
    result = (b - 1 + (a - 2)) / (a - 1);
    return result;
}
