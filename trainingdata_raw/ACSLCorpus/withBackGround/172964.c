#include <stdint.h>

/*@
    predicate valid_x(integer x) = 1 <= x && x <= 179;

    logic integer compute_ans(integer x) = x * 800 - (x / 15) * 200;

    lemma x_bound_1:
        \forall integer x; valid_x(x) ==> x * 800 <= 179 * 800;

    lemma x_bound_2:
        \forall integer x; valid_x(x) ==> (x / 15) * 200 <= 12 * 200;
*/

/*@
    requires valid_x(x);
    ensures \result == compute_ans(x);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    // Variable declarations at scope top
    int32_t ans;

    //@ assert valid_x(x);
    //@ assert x * 800 <= 179 * 800;
    //@ assert (x / 15) * 200 <= 12 * 200;

    ans = (int32_t)(x * 800 - (x / 15) * 200);
    
    //@ assert ans == compute_ans(x);
    return ans;
}
