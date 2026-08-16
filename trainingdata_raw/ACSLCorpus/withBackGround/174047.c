#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 20;

    logic integer compute_result(integer a, integer b, integer t) =
        (t / a) * b;

    lemma result_bound:
        \forall integer a, b, t;
            valid_range(a) && valid_range(b) && valid_range(t) ==>
            compute_result(a, b, t) <= 400;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(t);
    ensures \result == compute_result(a, b, t);
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t t)
{
    size_t ans;
    //@ assert t / a <= 20;
    //@ assert (t / a) * b <= 400;
    ans = (t / a) * b;
    return ans;
}
