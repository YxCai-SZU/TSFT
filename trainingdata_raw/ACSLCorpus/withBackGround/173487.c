#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 20;

    logic integer compute_result(integer t, integer a, integer b) = (t / a) * b;

    lemma result_bound:
        \forall integer t, a, b;
            valid_range(a) && valid_range(b) && valid_range(t) ==>
            compute_result(t, a, b) <= 400;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(t);
    ensures \result == compute_result(t, a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t)
{
    // Variable declarations at top of scope
    uint32_t ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(t);
    //@ assert t / a <= 20;
    //@ assert (t / a) * b <= 400;

    ans = (t / a) * b;
    return ans;
}
