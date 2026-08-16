#include <stdint.h>

/*@
    predicate valid_params(integer lh, integer lw, integer h, integer w) =
        1 <= lh <= 20 &&
        1 <= lw <= 20 &&
        1 <= h <= lh &&
        1 <= w <= lw;

    logic integer compute_ans(integer lh, integer lw, integer h, integer w) =
        (lh - h) * (lw - w);

    lemma ans_bounds:
        \forall integer lh, lw, h, w;
        valid_params(lh, lw, h, w) ==>
        compute_ans(lh, lw, h, w) <= 400;
*/

/*@
    requires valid_params(lh, lw, h, w);
    ensures \result == compute_ans(lh, lw, h, w);
*/
uint32_t func(uint32_t lh, uint32_t lw, uint32_t h, uint32_t w)
{
    uint32_t ans;

    //@ assert lh >= h;
    //@ assert lw >= w;
    //@ assert lh - h <= 20;
    //@ assert lw - w <= 20;
    //@ assert (lh - h) * (lw - w) <= 400;

    ans = (lh - h) * (lw - w);
    return ans;
}
