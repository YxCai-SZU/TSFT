#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b, integer t) =
        1 <= a && a <= 20 &&
        1 <= b && b <= 20 &&
        1 <= t && t <= 20;

    logic integer compute_result(integer a, integer b, integer t) =
        (t / a) * b;

    lemma result_bounds:
        \forall integer a, b, t;
        valid_inputs(a, b, t) ==> (t / a) * b <= 400;
*/

/*@
    requires valid_inputs(a, b, t);
    ensures \result == compute_result(a, b, t);
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t)
{
    uint32_t ans;
    //@ assert t / a <= 20;
    //@ assert (t / a) * b <= 400;
    ans = (t / a) * b;
    return ans;
}
